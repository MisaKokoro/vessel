#pragma once
#include "wasm_export.h"
#include "bh_getopt.h"
#include "bh_read_file.h"
#include "wasm_c_api.h"
#include "platform_api_vmcore.h"

#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h> 
#include <vector>
#include <string>
#include <unordered_map>

namespace wasm {
class WamrManager {
    public:
        WamrManager(const std::string &wasm_path);

        bool LookUpFunction(const std::string &function_name);
        wasm_function_inst_t GetWasmFunctionInst(const std::string &function_name);
        wasm_module_inst_t GetWasmModuleInst();
        wasm_exec_env_t GetWasmExecEnv();
        bool CallWasmFunction(const std::string &funcName,uint32_t arg_addr,uint32_t len);
        uint32_t ModuleMalloc(void **native_ptr,uint32_t size);
        void ModuleFree(uint32_t wasm_ptr);
        wasm_module_inst_t InstFromModule();

        size_t getMemorySizeBytes();

        uint8_t* getMemoryBase();

        ~WamrManager();
        
    private:
        wasm_module_t           module_ = NULL;
        wasm_module_inst_t      module_inst_ = NULL;
        wasm_exec_env_t         exec_env_ = NULL;
        uint32_t                buf_size_, stack_size_ = 8192, heap_size_ = 8192;
        // uint32_t wasm_buffer_ = 0;
        char                    *buffer_;
        RuntimeInitArgs         init_args_;
        std::string             wasm_path_;

        char global_heap_buf_[1024 * 1024];
        char error_buf_[128];
        std::unordered_map<std::string,wasm_function_inst_t> function_hashtable_;
    private:
        void InitWamr_();   
        void DestoryEnv_();
};
}

