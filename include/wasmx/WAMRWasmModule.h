#include "wasmx/WasmModule.h"
#include "wasm_runtime_common.h"


#define ERROR_BUFFER_SIZE 256
#define STACK_SIZE_KB 8192
#define HEAP_SIZE_KB 8192
#define NO_WASM_FUNC_PTR -1

namespace wasm {

class WAMRWasmModule : public WasmModule {
public:
    static void initialiseWAMRGlobally();

    WAMRWasmModule();

    ~WAMRWasmModule();

    size_t getMemorySizeBytes() override;

    uint8_t* getMemoryBase() override;

    size_t getMaxMemoryPages() override;

    uint8_t* wasmPointerToNative(uint32_t wasmPtr) override;


    WASMModuleInstanceCommon* getModuleInstance();

    int executeWasmFunction(const std::string& funcName);

    void doBindToFunction(const std::string& msg, bool cache) override;

    void printDebugInfo();
private:
    /**
     * @brief 
     * 最底层的调用wasm函数的方法，暂时不捕获异常，虽然仍然叫这个名字 ):
     * @param func 
     * @param wasmFuncPtr 
     * @param argc 
     * @param argv 
     * @return true 
     * @return false 
     */
    bool executeCatchException(WASMFunctionInstanceCommon* func,
                            int wasmFuncPtr,
                            int argc,
                            std::vector<uint32_t>& argv);
    
    void bindInternal(const std::string& msg);
private:
    char error_buffer_[ERROR_BUFFER_SIZE];
    std::vector<uint8_t> wasm_bytes_;
    WASMModuleCommon* wasm_module_ = nullptr;
    WASMModuleInstanceCommon* module_instance_ = nullptr;
};
}