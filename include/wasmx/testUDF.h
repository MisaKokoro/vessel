#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include "WamrManager.h"
#include "struct.h"
class TestUDF {
public:
    TestUDF( WamrManager *wamr_handle,int cnt = 1000000,int size = 1000, int mem_size = 10240) : cnt_(cnt),size_(size),mem_size_(mem_size),wamr_handle_(wamr_handle) {
        vec_.resize(size_);
        // str_.resize(size_,'a');
        std::iota(vec_.begin(),vec_.end(),1);

        //构造点数据
        vec_double_.resize(4);
        vec_double_[0] = 2.7, vec_double_[1] = 3.6;
        vec_double_[2] = 4.1, vec_double_[3] = 5.5;

        //构造切割字符串数据
        for (int i = 0; i < size; i++) {
           str_ += static_cast<char>(i % 26 + 'a');
        }
        str_.pop_back();
    }

    void TestFuncDirect(const std::string &funcName);
    void TestFuncProto(const std::string &funcName);
    void TestMap();
    void TestFuncUseBitsery(const std::string &funcName);

private:
    std::vector<int> vec_;
    std::vector<int> vec_double_;
    std::string str_;
    int cnt_;
    int size_;
    int mem_size_;
    WamrManager *wamr_handle_;
};