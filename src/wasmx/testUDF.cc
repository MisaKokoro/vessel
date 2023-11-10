#include <vector>
#include <string>
#include <iostream>

#include "testUDF.h"
#include "testData.pb.h"
#include "ScopeTime.h"
#include "serialize.h"
#include "struct.h"
using namespace std;

using Buffer = std::vector<uint8_t>;
using OutputAdapter = bitsery::OutputBufferAdapter<Buffer>;
using InputAdapter = bitsery::InputBufferAdapter<Buffer>;

// 现在默认测试vec
void TestUDF::TestFuncDirect(const string &funcName)
{
    void *native_ptr = nullptr;
    auto offset = wamr_handle_->ModuleMalloc(&native_ptr, mem_size_);
    ScopeTime st("Test Func " + funcName);
    // Serialize ser;
    if (funcName == "my_arr_sum")
    {
        copy_vector<int>(vec_, native_ptr, offset);
        for (int i = 0; i < cnt_; i++)
        {
            copy_vector(vec_, native_ptr, offset);
            wamr_handle_->CallWasmFunction(funcName, offset, 0);
        }
    }
    else if (funcName == "my_str_hash")
    {
        copy_string(str_, native_ptr, offset);
        for (int i = 0; i < cnt_; i++)
        {
            // copy_string(str_,native_ptr,offset);
            wamr_handle_->CallWasmFunction(funcName, offset, 0);
        }
    }
    else if (funcName == "my_distance")
    {
        copy_vector(vec_double_, native_ptr, offset);
        for (int i = 0; i < cnt_; i++)
        {
            // copy_vector(vec_double_,native_ptr,offset);
            wamr_handle_->CallWasmFunction(funcName, offset, 0);
        }
    }
    else if (funcName == "my_split")
    {
        copy_string(str_, native_ptr, offset);
        for (int i = 0; i < cnt_; i++)
        {
            copy_string(str_, native_ptr, offset);
            wamr_handle_->CallWasmFunction(funcName, offset, 0);
        }
    }
    else if (funcName == "my_bmi")
    {
        // copy_person_info(person_,native_ptr,offset);
        // for (int i = 0; i < cnt_; i++) {
        //     // copy_person_info(person_,native_ptr,offset);
        //     wamr_handle_->CallWasmFunction(funcName,offset,0);
        // }
    }

    wamr_handle_->ModuleFree(offset);
}

void TestUDF::TestFuncProto(const string &funcName)
{
    void *nativ_ptr = nullptr;
    auto offset = wamr_handle_->ModuleMalloc(&nativ_ptr, mem_size_);
    int len = 0;
    ScopeTime st("Test Func " + funcName);
    if (funcName == "proto_arr_sum")
    {
        Array arr;
        for (int d : vec_)
            arr.add_arr(d);

        len = arr.ByteSizeLong();
        arr.SerializeToArray(nativ_ptr, mem_size_);
        for (int i = 0; i < cnt_; i++)
        {
            // arr.SerializeToArray(nativ_ptr,mem_size_);
            wamr_handle_->CallWasmFunction(funcName, offset, len);
        }
    }
    else if (funcName == "proto_str_hash")
    {
        Person p;
        p.set_name(str_);
        len = p.ByteSizeLong();
        p.SerializeToArray(nativ_ptr, mem_size_);

        for (int i = 0; i < cnt_; i++)
        {
            // p.SerializeToArray(nativ_ptr,mem_size_);
            wamr_handle_->CallWasmFunction(funcName, offset, len);
            // Person new_p;
            // new_p.ParseFromArray(nativ_ptr,len);
        }
    }
    else if (funcName == "proto_distance")
    {
        ArrayDouble arr;
        for (auto d : vec_double_)
            arr.add_arr(d);

        len = arr.ByteSizeLong();
        arr.SerializeToArray(nativ_ptr, mem_size_);
        for (int i = 0; i < cnt_; i++)
        {
            // arr.SerializeToArray(nativ_ptr,mem_size_);
            wamr_handle_->CallWasmFunction(funcName, offset, len);
        }
    }
    else if (funcName == "proto_split")
    {
        Person p;
        p.set_name(str_);
        len = p.ByteSizeLong();
        p.SerializeToArray(nativ_ptr, mem_size_);
        for (int i = 0; i < cnt_; i++)
        {
            p.SerializeToArray(nativ_ptr, mem_size_);
            wamr_handle_->CallWasmFunction(funcName, offset, len);
        }
    }
    else if (funcName == "proto_bmi")
    {
        // Person_Info p;
        // p.set_age(person_.age);
        // p.set_name(person_.name);
        // p.set_height(person_.height);
        // p.set_weight(person_.weight);

        // len = p.ByteSizeLong();
        // p.SerializeToArray(nativ_ptr,mem_size_);
        // for (int i = 0; i < cnt_; i++) {
        //     // p.SerializeToArray(nativ_ptr,mem_size_);
        //     wamr_handle_->CallWasmFunction(funcName,offset,len);
        // }
    }

    wamr_handle_->ModuleFree(offset);
}

void TestUDF::TestMap()
{
    //     //测试一些map
    void *native_ptr;
    auto offset = wamr_handle_->ModuleMalloc(&native_ptr, 2048);
    // map<int,string> test = {
    //     {0,"tgdfidgfuigfjkghfjgh"},
    //     {1,"asdfghjklsdfghjk"},
    //     {2,"fgjhfjhfjhfjhfjh"},
    //     {3,"edfghjkltfgiojklhklh"},
    //     {4,"tyuiogjrjgrljgrtgg"},
    // };
    map<int, int> test = {
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 8},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 7},
        {8, 8},
        {9, 9},
    };
    cpmap(test, native_ptr, offset, 0);
    // for (int i = 0; i < 3; i++)
    //     printf("%d\n", *((uint32_t *)native_ptr + i));
    // printf("   le\trt\tpar\tbl\tkey\tvalue\n");
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d:", 12 + i * 6 * 4);
    //     for (int j = 0; j < 6; j++)
    //         printf("%d\t", *((uint32_t *)native_ptr + 3 + i * 6 + j));
    //     printf("\n");
    // }
    wamr_handle_->CallWasmFunction("map_test", offset, 0);
}

void TestUDF::TestFuncUseBitsery(const string &funcName)
{
    void *native_ptr;
    auto offset = wamr_handle_->ModuleMalloc(&native_ptr, mem_size_);
    ScopeTime st("test " + funcName);
    if (funcName == "bitsery_arr_sum")
    {
        MyVector vec{vec_};
        Buffer buffer;
        int writtenSize = bitsery::quickSerialization<OutputAdapter>(buffer, vec);
        memcpy(native_ptr, buffer.data(), writtenSize);
        for (int i = 0; i < cnt_; i++)
        {
            // int writtenSize = bitsery::quickSerialization<OutputAdapter>(buffer, vec);
            wamr_handle_->CallWasmFunction(funcName, offset, writtenSize);
        }
    }
    else if (funcName == "bitsery_str_hash")
    {
        MyString str{str_};
        Buffer buffer;
        int writtenSize = bitsery::quickSerialization<OutputAdapter>(buffer, str);
        memcpy(native_ptr, buffer.data(), writtenSize);
        for (int i = 0; i < cnt_; i++)
        {
            // int writtenSize = bitsery::quickSerialization<OutputAdapter>(buffer, str);
            // MyString new_str{};
            // bitsery::quickDeserialization<InputAdapter>({buffer.begin(),writtenSize},new_str);
            wamr_handle_->CallWasmFunction(funcName, offset, writtenSize);
        }
    }

    wamr_handle_->ModuleFree(offset);
}