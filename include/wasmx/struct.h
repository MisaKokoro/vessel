#pragma once
#include <bitsery/bitsery.h>
// in ordered to serialize/deserialize data to buffer, include buffer adapter
#include <bitsery/adapter/buffer.h>
// bitsery itself doesn't is lightweight, and doesnt include any unnessessary
// files, traits helps library to know how to use types correctly, in this case
// we'll be using vector both, to serialize/deserialize data and to store use as
// a buffer.
#include <bitsery/traits/vector.h>
#include <bitsery/traits/string.h>
#include <bitsery/brief_syntax.h>
#include <bitsery/brief_syntax/map.h>
#include <bitsery/brief_syntax/string.h>
#include <bitsery/brief_syntax/vector.h>

#include <iostream>

// 定义结构
struct MyVector
{
    std::vector<int> vec;
    template <typename S>
    void serialize(S &s)
    {
       s(vec);
    }
};

struct MyString {
    std::string str;
    template <typename S>
    void serialize(S &s)
    {
       s(str);
    }
};
