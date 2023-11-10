#include "wasmx/WamrManager.h"
#include "util/ScopeTime.h"
WamrManager::~WamrManager() {
    DestoryEnv_();
}

WamrManager::WamrManager(const std::string &wasm_path) : wasm_path_(wasm_path) {
    InitWamr_();
}

wasm_module_inst_t WamrManager::GetWasmModuleInst() {
    return module_inst_;
}

wasm_exec_env_t WamrManager::GetWasmExecEnv() {
    return exec_env_;
}

bool WamrManager::LookUpFunction(const std::string &function_name) {
    auto func_inst = wasm_runtime_lookup_function(module_inst_,function_name.c_str(),nullptr);
    if (!func_inst) {
        printf("The %s function is not found\n",function_name.c_str());
        return false;
    }
    function_hashtable_[function_name] = func_inst;
    return true;
}

wasm_function_inst_t WamrManager::GetWasmFunctionInst(const std::string &function_name) {
    return function_hashtable_[function_name];
}

void WamrManager::InitWamr_() {
    // ScopeTime st("init");
    memset(&init_args_, 0, sizeof(RuntimeInitArgs));
    init_args_.mem_alloc_type = Alloc_With_Pool;
    init_args_.mem_alloc_option.pool.heap_buf = global_heap_buf_;
    init_args_.mem_alloc_option.pool.heap_size = sizeof(global_heap_buf_);

    // sleep(10);

    // ScopeTime *st1 = new ScopeTime("runtime full init");
    if (!wasm_runtime_full_init(&init_args_)) {
        printf("Init runtime environment failed.\n");
        std::abort();
    }
    // delete st1;

    // sleep(10);
    // ScopeTime *st2 = new ScopeTime("read file to buffer");
    buffer_ = bh_read_file_to_buffer(wasm_path_.c_str(),&buf_size_);
    if (!buffer_) {
        printf("Open wasm app file [%s] failed.\n", wasm_path_.c_str());
        std::abort();
    }
    // delete st2;

    // sleep(10);
    // ScopeTime *st3 = new ScopeTime("runtime load");
    module_ = wasm_runtime_load(reinterpret_cast<uint8_t*>(buffer_),buf_size_,error_buf_,sizeof(error_buf_));
    auto module2 = wasm_runtime_load(reinterpret_cast<uint8_t*>(buffer_),buf_size_,error_buf_,sizeof(error_buf_));
    if (!module_) {
        printf("Load wasm module failed. error: %s\n", error_buf_);
        std::abort();
    }
    // delete st3;

    // sleep(10);

    // ScopeTime *st4 = new ScopeTime("runtime instantiate");
    module_inst_ = wasm_runtime_instantiate(module_,stack_size_,heap_size_,error_buf_,sizeof(error_buf_));
    if (!module_inst_) {
        printf("Instantiate wasm module failed. error: %s\n", error_buf_);
        std::abort();
    }
    // delete st4;

    // sleep(10);

    // ScopeTime *st5 = new ScopeTime("runtime create execenv");
    exec_env_ = wasm_runtime_create_exec_env(module_inst_,stack_size_);
    if (!exec_env_) {
        printf("Create wasm execution environment failed.\n");
        std::abort();
    }
    // delete st5;
}

void WamrManager::DestoryEnv_() {
    if (exec_env_)
        wasm_runtime_destroy_exec_env(exec_env_);
    if (module_inst_) {
        wasm_runtime_deinstantiate(module_inst_);
    }
    if (module_)
        wasm_runtime_unload(module_);
    if (buffer_)
        BH_FREE(buffer_);
    wasm_runtime_destroy();
}

bool WamrManager::CallWasmFunction(const std::string &funcName,uint32_t arg_addr,uint32_t len) {
    uint32_t argv[2] = {arg_addr,len};
    if (!wasm_runtime_call_wasm(exec_env_,GetWasmFunctionInst(funcName),2,argv)) {
        printf("call wasm function %s failed. error: %s\n",
               funcName.c_str(),wasm_runtime_get_exception(module_inst_));
        return false;
    }
    // std::cout << argv[0] << std::endl;
    return true;
}

uint32_t WamrManager::ModuleMalloc(void **native_ptr,uint32_t size) {
    return wasm_runtime_module_malloc(module_inst_,size,native_ptr);
}

void WamrManager::ModuleFree(uint32_t wasm_ptr) {
    wasm_runtime_module_free(module_inst_,wasm_ptr);
}

wasm_module_inst_t WamrManager::InstFromModule() {
    auto module_inst = wasm_runtime_instantiate(module_,stack_size_,heap_size_,error_buf_,sizeof(error_buf_));
    if (!module_inst_) {
        printf("Instantiate wasm module failed. error: %s\n", error_buf_);
        std::abort();
    }
    return module_inst;
}
