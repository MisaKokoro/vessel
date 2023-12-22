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


    std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/rustpython.aot";
    std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/snapshot.aot";
    int flag = std::stoi(argv[1]);
    WAMRWasmModule app1;
    std::string wasm_path;
    if (flag == 1) {
        wasm_path = wasm_path1;
    } else {
        wasm_path = wasm_path2;
    }
    SPDLOG_INFO("wasm path {}", wasm_path);
    app1.bindToFunction(wasm_path);
    std::string snapkey = app1.snapshot();

    app1.executeWasmFunction("show_data");
    app1.executeWasmFunction("mod_data");

    app1.printDebugInfo();
    
    WAMRWasmModule app2;
    app2.bindToFunction(wasm_path);
    {   ScopeTime st("restore");
        app2.restore(snapkey);
    }
    app2.executeWasmFunction("show_data");
    app2.executeWasmFunction("mod_data");
    app2.executeWasmFunction("show_data");

    WAMRWasmModule app3;
    app3.bindToFunction(wasm_path);
    app3.restore(snapkey);
    app3.executeWasmFunction("show_data");

    // app2.printDebugInfo();

    return 0;
    
}