#include <span>
#include "wasmx/WAMRWasmModule.h"
#include "snapshot/snapshot.h"
#include "util/log.h"
#include "util/ScopeTime.h"
#include "util/config.h"
#include <pthread.h>
#include <unistd.h>
#include <vector>
using namespace wasm;
using namespace util;
using namespace snapshot;
std::string snapkey="";
std::string wasm_path="";
void* execute(void* arg)
{
    WAMRWasmModule app;
    // app.bindToFunction(wasm_path);
    //app.createNewInstance();
    app.restore(snapkey);
    app.executeWasmFunction("run");

}


int main(int argc, char *argv[]) {
    auto& conf = getSystemConfig();
    conf.wasm_memory_mode = "system_alloc";
    conf.print();
    // initLogging();

    std::string wasm_path1 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/uap_bench.control.aot";
    std::string wasm_path2 = "/home/yanxiang/Desktop/MyProject/vessel/build/bin/uap_bench.wizer.aot";
    int flag = std::stoi(argv[1]);
    WAMRWasmModule app1;
    if (flag == 1) {
        wasm_path = wasm_path1;
    } else {
        wasm_path = wasm_path2;
    }
    SPDLOG_INFO("wasm path {}", wasm_path);
    // std::vector<uint8_t> wasm_bytes;
    // auto wasm_module = loadWasmFile(wasm_path, wasm_bytes);

    app1.bindToFunction(wasm_path);
    snapkey = app1.snapshot();
    {
        ScopeTime st("multi-thread cost");
        int number_of_threads=16;
        std::vector<pthread_t> threads(number_of_threads);
        std::vector<int> thread_nums(number_of_threads);
        for (int i = 0; i < number_of_threads; ++i) {
        // 存储线程的序号，以便传递给线程函数
        thread_nums[i] = i;

        // 创建线程
        if (pthread_create(&threads[i], nullptr, execute, &thread_nums[i])) {
            std::cerr << "Error creating thread " << i << std::endl;
            return 1;
        }
    }
    // 等待所有线程完成
    for (int i = 0; i < number_of_threads; ++i) {
        if (pthread_join(threads[i], nullptr)) {
            std::cerr << "Error joining thread " << i << std::endl;
            return 2;
        }
    }

    std::cout << "All threads completed." << std::endl;

    }

    return 0;
    
}