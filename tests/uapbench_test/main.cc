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


    app1.bindToFunction(wasm_path);
    std::string snapkey = app1.snapshot();
    app1.printDebugInfo();

    {
        ScopeTime st("run func cost");
        app1.executeWasmFunction("run");
    }

    WAMRWasmModule app2;
    app2.bindToFunction(wasm_path);
    app2.printDebugInfo();
    app2.restore(snapkey);

    return 0;
    
}