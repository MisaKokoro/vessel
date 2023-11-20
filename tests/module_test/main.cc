#include <span>
#include "wasmx/WAMRWasmModule.h"
#include "snapshot/snapshot.h"
#include "util/log.h"
#include "util/ScopeTime.h"

using namespace wasm;
using namespace util;
using namespace snapshot;

int main(int argc, char *argv[]) {
    std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/regex_bench.control.aot";
    std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/wizer.aot";
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

    // app1.executeWasmFunction("show_data");
    // app1.executeWasmFunction("mod_data");

    std::string snapkey = app1.snapshot();
    app1.printDebugInfo();
    
    WAMRWasmModule app2;
    app2.bindToFunction(wasm_path);
    {   ScopeTime st("restore");
        app2.restore(snapkey);
    }
    // app2.executeWasmFunction("show_data");
    app2.printDebugInfo();

    return 0;
    
}