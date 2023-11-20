#include "wasmx/WAMRWasmModule.h"
#include "aot_runtime.h"
#include "wasm_export.h"
#include "wasm_runtime_common.h"
#include "util/log.h"
#include "util/file.h"
#include "util/ScopeTime.h"

namespace wasm {

static bool wamr_initialised = false;

void WAMRWasmModule::initialiseWAMRGlobally() {
    if (wamr_initialised) {
        return;
    }
    // Initialise WAMR runtime
    RuntimeInitArgs initArgs;
    memset(&initArgs, 0, sizeof(RuntimeInitArgs));
    // Memory configuration 先使用系统的malloc函数作为分配函数
    // 后续增加可选内存池模式
    initArgs.mem_alloc_type = Alloc_With_Allocator;
    initArgs.mem_alloc_option.allocator.malloc_func = (void*)::malloc;
    initArgs.mem_alloc_option.allocator.realloc_func = (void*)::realloc;
    initArgs.mem_alloc_option.allocator.free_func = (void*)::free;

    bool success = wasm_runtime_full_init(&initArgs);
    if (!success) {
        throw std::runtime_error("Failed to initialise WAMR");
    }

    SPDLOG_DEBUG("Successfully initialised WAMR");

    bh_log_set_verbose_level(BH_LOG_LEVEL_WARNING);

    wamr_initialised = true;
}

WAMRWasmModule::WAMRWasmModule() {
    initialiseWAMRGlobally();
}

WAMRWasmModule::~WAMRWasmModule() {
    wasm_runtime_deinstantiate(module_instance_);
    wasm_runtime_unload(wasm_module_);
}

uint8_t* WAMRWasmModule::wasmPointerToNative(uint32_t wasmPtr) {
    void* nativePtr = wasm_runtime_addr_app_to_native(module_instance_, wasmPtr);
    if (nativePtr == nullptr) {
        SPDLOG_ERROR("WASM offset {} is out of the WAMR module's address space",
                     wasmPtr);
        throw std::runtime_error("Offset out of WAMR memory");
    }
    return static_cast<uint8_t*>(nativePtr);
}

uint8_t* WAMRWasmModule::getMemoryBase() {
    auto* aot_module = reinterpret_cast<AOTModuleInstance*>(module_instance_);
    AOTMemoryInstance* aot_mem = ((AOTMemoryInstance**)aot_module->memories)[0];
    return reinterpret_cast<uint8_t*>(aot_mem->memory_data);
}

size_t WAMRWasmModule::getMemorySizeBytes() {
    auto* aotModule = reinterpret_cast<AOTModuleInstance*>(module_instance_);
    AOTMemoryInstance* aotMem = ((AOTMemoryInstance**)aotModule->memories)[0];
    return aotMem->cur_page_count * WASM_BYTES_PER_PAGE;
}

size_t WAMRWasmModule::getMaxMemoryPages() {
    auto* aotModule = reinterpret_cast<AOTModuleInstance*>(module_instance_);
    AOTMemoryInstance* aotMem = ((AOTMemoryInstance**)aotModule->memories)[0];
    return aotMem->max_page_count;
}

WASMModuleInstanceCommon* WAMRWasmModule::getModuleInstance() {
    if (module_instance_ == nullptr) {
        SPDLOG_ERROR("Trying to get a null-pointing module instance");
        throw std::runtime_error("Null WAMR module instance");
    }
    return module_instance_;
}

int WAMRWasmModule::executeWasmFunction(const std::string& funcName) {
    SPDLOG_DEBUG("WAMR executing function from string {}", funcName);

    WASMFunctionInstanceCommon* func =
      wasm_runtime_lookup_function(module_instance_, funcName.c_str(), nullptr);
    if (func == nullptr) {
        SPDLOG_ERROR("Did not find function {} for module",
                     funcName);
        throw std::runtime_error("Did not find named wasm function");
    }

    // Note, for some reason WAMR sets the return value in the argv array you
    // pass it, therefore we should provide a single integer argv even though
    // it's not actually used
    std::vector<uint32_t> argv = { 0 };
    bool success = executeCatchException(func, NO_WASM_FUNC_PTR, 0, argv);
    uint32_t returnValue = argv[0];

    if (!success) {
        SPDLOG_ERROR("Error executing {}: {}",
                     funcName,
                     wasm_runtime_get_exception(module_instance_));
        throw std::runtime_error("Error executing WASM function with WAMR");
    }

    SPDLOG_DEBUG("WAMR finished executing {}", funcName);
    return returnValue;
}

// Low-level method to call a WASM function in WAMR and catch any thrown
// exceptions. This method is shared both if we call a function by pointer or
// by name
bool WAMRWasmModule::executeCatchException(WASMFunctionInstanceCommon* func,
                                           int wasmFuncPtr,
                                           int argc,
                                           std::vector<uint32_t>& argv) {

    auto execEnvDtor = [&](WASMExecEnv* execEnv) {
        if (execEnv != nullptr) {
            wasm_runtime_destroy_exec_env(execEnv);
        }
    };

    // Create an execution environment
    std::unique_ptr<WASMExecEnv, decltype(execEnvDtor)> execEnv(
      wasm_exec_env_create(module_instance_, STACK_SIZE_KB), execEnvDtor);
    if (execEnv == nullptr) {
        throw std::runtime_error("Error creating execution environment");
    }

    // Set thread handle and stack boundary (required by WAMR)
    // wasm_exec_env_set_thread_info(execEnv.get());
    bool success;
    success = wasm_runtime_call_wasm(execEnv.get(), func, argc, argv.data());
    return success;
}

void WAMRWasmModule::doBindToFunction(const std::string& msg, bool cache) {
    // Load the wasm file
    std::string path = msg;
    wasm_bytes_ =  util::readFileToBytes(path);


    SPDLOG_TRACE("WAMR loading {} wasm bytes\n", wasm_bytes_.size());
    wasm_module_ = wasm_runtime_load(
        wasm_bytes_.data(), wasm_bytes_.size(), error_buffer_, ERROR_BUFFER_SIZE);

    if (wasm_module_ == nullptr) {
        std::string errorMsg = std::string(error_buffer_);
        SPDLOG_ERROR("Failed to load WAMR module: \n{}", errorMsg);
        throw std::runtime_error("Failed to load WAMR module");
    }

    bindInternal(msg);
}

void WAMRWasmModule::bindInternal(const std::string& msg) {

    // Instantiate module. Set the app-managed heap size to 0 to use
    // wasi-libc's managed heap. See:
    // https://bytecodealliance.github.io/wamr.dev/blog/understand-the-wamr-heap/
    {
    ScopeTime st("init cost");
    module_instance_ = wasm_runtime_instantiate(
      wasm_module_, STACK_SIZE_KB, 0, error_buffer_, ERROR_BUFFER_SIZE);
    }

    // Sense-check the module
    auto* aotModule = reinterpret_cast<AOTModuleInstance*>(module_instance_);
    AOTMemoryInstance* aotMem = ((AOTMemoryInstance**)aotModule->memories)[0];

    if (aotMem->num_bytes_per_page != WASM_BYTES_PER_PAGE) {
        SPDLOG_ERROR("WAMR module bytes per page wrong, {} != {}, overriding",
                     aotMem->num_bytes_per_page,
                     WASM_BYTES_PER_PAGE);
        throw std::runtime_error("WAMR module bytes per page wrong");
    }

    if (module_instance_ == nullptr) {
        std::string errorMsg = std::string(error_buffer_);
        SPDLOG_ERROR("Failed to instantiate WAMR module: \n{}", errorMsg);
        throw std::runtime_error("Failed to instantiate WAMR module");
    }

    current_brk_ = getMemorySizeBytes();
}

void WAMRWasmModule::printDebugInfo() {
    SPDLOG_INFO("memory base {}, memory bytes {}", static_cast<void*>(getMemoryBase()), getMemorySizeBytes());
}


}