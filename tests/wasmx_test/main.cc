
/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include <iostream>

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <thread>

#include "wasmx/WamrManager.h"
#include "wasmx/testUDF.h"
#include "util/ScopeTime.h"



using namespace std;

void *P;
bool is_extern_mem = false;


int main(int argc, char *argv[])
{
    volatile int lock = 1;
    string wasm_path = "/home/yanxiang/Desktop/wasmX/build/testcase/sum_no_malloc.aot";
    // sleep(15);
    int thread_size = 2;
    if (argc != 1) {
        thread_size = stoi(argv[1]);
    }

    WamrManager wamrManager(wasm_path);

    // WamrManager *manger = new WamrManager("/home/yanxiang/Desktop/wasmX/build/wasm-app/test_bitsery.aot");
    // WamrManager t("/home/yanxiang/Desktop/wasmX/build/wasm-app/testapp.wasm");
    // wamrManager.LookUpFunction("printString");
    wamrManager.LookUpFunction("my_arr_sum");
    wamrManager.LookUpFunction("add");
    // wamrManager.LookUpFunction("bitsery_arr_sum");
    // wamrManager.LookUpFunction("proto_arr_sum");
    // wamrManager.LookUpFunction("add");
    // wamrManager.LookUpFunction("my_str_hash");
    // wamrManager.LookUpFunction("proto_str_hash");
    // wamrManager.LookUpFunction("proto_split");
    // wamrManager.LookUpFunction("proto_distance");
    // wamrManager.LookUpFunction("my_split");
    // wamrManager.LookUpFunction("my_distance");
    // wamrManager.LookUpFunction("my_bmi");
    // wamrManager.LookUpFunction("proto_bmi");
    // wamrManager.LookUpFunction("map_test");
    // wamrManager.LookUpFunction("bitsery_str_hash");
    // while(1) {
    //     sleep(1);
    // }


    // auto exec_env = wamrManager.GetWasmExecEnv();
    // auto module_inst = wamrManager.GetWasmModuleInst();

    auto Run = [&]() {
        while (lock);
        RuntimeInitArgs init_args;
        memset(&init_args, 0, sizeof(RuntimeInitArgs));
        // init_args.mem_alloc_type = Alloc_With_Pool;
        // wasm_runtime_full_init(&init_args);

        int stack_size = 8192;
        ScopeTime *st = new ScopeTime("init once ");

        auto module_inst = wamrManager.InstFromModule();
        delete st;

        // auto exec_env = wasm_runtime_create_exec_env(module_inst,stack_size);
        // auto func_inst = wasm_runtime_lookup_function(module_inst,"add",nullptr);

        // ScopeTime *st = new ScopeTime("call once ");
        // uint32_t argv[2] = {1,1};
        // if (!wasm_runtime_call_wasm(exec_env,func_inst,2,argv)) {
        //     printf("call wasm function %s failed. error: %s\n",
        //         "add",wasm_runtime_get_exception(module_inst));
        //     return;
        // }
        // delete st;


        // printf("res = %d\n",argv[0]);
    };
    // vector<thread> th;
    // for (int i = 0; i < thread_size; i++) {
    //    th.push_back(thread(Run));
    // }
    // ScopeTime *st = new ScopeTime("test thread sisze " + to_string(thread_size));
    // lock = 0;
    // for (int i = 0; i < thread_size; i++) {
    //     th[i].join();
    // }
    // delete st;

    ScopeTime *st = new ScopeTime("Run once ");
    lock = 0;
    Run();
    delete st;
    // while (1) {
    //     sleep(1);
    // }



    // TestUDF test(&wamrManager,100000,100);
    // test.TestFuncDirect("my_bmi");
    // test.TestFuncProto("proto_bmi");
    // test.TestFuncDirect("my_distance");
    // test.TestFuncProto("proto_distance");
    // // test.TestFuncDirect("my_str_hash");
    // test.TestFuncDirect("my_arr_sum");
    // test.TestFuncProto("proto_split");
    // test.TestFuncDirect("my_split");
    // test.TestMap();
    // test.TestFuncUseBitsery("bitsery_arr_sum");
    // test.TestFuncProto("proto_arr_sum");
    // test.TestFuncDirect("my_arr_sum");
    // test.TestFuncUseBitsery("bitsery_str_hash");
    // test.TestFuncDirect("my_str_hash");
    // test.TestFuncProto("proto_str_hash");


    // test.TestFuncProto("proto_str_hash");



    return 0;
}