#include <span>
#include "wasmx/WAMRWasmModule.h"
#include "snapshot/snapshot.h"
#include "util/log.h"
#include "util/ScopeTime.h"
#include "util/config.h"

using namespace wasm;
using namespace util;
using namespace snapshot;

int main(int argc, char *argv[]) {
    auto& conf = getSystemConfig();
    conf.wasm_memory_mode = "system_alloc";
    conf.print();
    // initLogging();


    //std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/rustpython.aot";
    //std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/uap_bench.aot";
    std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/uap_bench.control.aot";
    std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/uap_bench.wizer.aot";
    int flag = std::stoi(argv[1]);
    WAMRWasmModule app1;
    std::string wasm_path;
    if (flag == 1) {
        wasm_path = wasm_path1;
    } else {
        wasm_path = wasm_path2;
    }
    SPDLOG_INFO("wasm path {}", wasm_path);
    // std::vector<uint8_t> wasm_bytes;
    // auto wasm_module = loadWasmFile(wasm_path, wasm_bytes);

    char error_buffer_[256] = {0};
    app1.bindToFunction(wasm_path);

    // app1.executeWasmFunction("show_data");
    // app1.executeWasmFunction("mod_data");
    std::string snapkey = app1.snapshot();


    //std::vector<std::thread> ts;

    app1.printDebugInfo();
    {
        ScopeTime st("run1 func cost");
        app1.executeWasmFunction("run");
    }
    
    WAMRWasmModule app2;
    // std::vector<uint8_t> wasm_bytes2;
    // auto wasm_module2 = loadWasmFile(wasm_path, wasm_bytes2);
    app2.bindToFunction(wasm_path);
    
    app2.printDebugInfo();
    {   ScopeTime st("restore");
        app2.restore(snapkey);
    }
    //app2.executeWasmFunction("show_data");
    //app2.executeWasmFunction("mod_data");
    //app2.executeWasmFunction("show_data");
    {
        ScopeTime st("run2 func cost");
        app2.executeWasmFunction("run");
    }
    /*WAMRWasmModule app3;
    app3.bindToFunction(wasm_path);
    app3.restore(snapkey);
    app3.executeWasmFunction("show_data");
    */
    // app2.printDebugInfo();

    return 0;
    
}