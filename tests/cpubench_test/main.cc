#include <span>
#include "wasmx/WAMRWasmModule.h"
#include "snapshot/snapshot.h"
#include "util/log.h"
#include "util/ScopeTime.h"
#include "util/config.h"
#include <sys/time.h>
using namespace wasm;
using namespace util;
using namespace snapshot;

int main(int argc, char *argv[]) {
    
    auto& conf = getSystemConfig();
    conf.wasm_memory_mode = "system_alloc";
    conf.print();
    // initLogging();
    
    std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/cpu_bench.control.aot";
    std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/cpu_bench.wizer.aot";
    int flag = std::stoi(argv[1]);
    
    std::string wasm_path;
    if (flag == 1) {
        wasm_path = wasm_path1;
    } else {
        wasm_path = wasm_path2;
    }
    SPDLOG_INFO("wasm path {}", wasm_path);


    int iter=std::stoi(argv[2]);
    for(int i=0;i<iter;i++)
    {
        WAMRWasmModule app1;

        app1.bindToFunction(wasm_path);
        std::string snapkey = app1.snapshot();
    {
        //ScopeTime st("run1 func cost");
        app1.executeWasmFunction("run");
    }
    WAMRWasmModule app2;
    app2.bindToFunction(wasm_path);
    {   //ScopeTime st("restore");
        app2.restore(snapkey);
    }
    {
        //ScopeTime st("run2 func cost");
        app2.executeWasmFunction("run");
    }

    }


    return 0;
    
}