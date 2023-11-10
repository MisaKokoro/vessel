/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */


#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <unistd.h>

#include "testData.pb-c.h"
#include "struct.h"

using namespace std;
using Buffer = std::vector<uint8_t>;
using OutputAdapter = bitsery::OutputBufferAdapter<Buffer>;
using InputAdapter = bitsery::InputBufferAdapter<Buffer>;

typedef struct My_Person_Info {
    int age;
    double height;
    double weight;
    string name;
}My_Person_Info;

typedef struct ListString {
    char *str[10];
} ListString;

//不能nostdlib编译，因此加上main函数
//nostdlib编译会出现一个没有实现的函数__assert_fail,导致程序无法运行
extern "C" {
// void printPersonInfo(Person per) {
//     printf("name: %s\nage: %d\nphonenum: %lld\nhigh = %d\n",per.name,per.age,per.phonenum,per.high);
//     printf("address person = %p\n",&per);
//     printf("address age = %p, address phonenum = %p, address name = %p address high = %p\n",&per.age,&per.phonenum,&per.name,&per.high);
//     printf("value of name = %p\n",per.name);
// }
int bitsery_arr_sum(uint8_t* buf, int size) {
    MyVector res;
    Buffer buffer(buf, buf + size);
    int sum = 0;
    auto state = bitsery::quickDeserialization<InputAdapter>({buffer.begin(), static_cast<size_t>(size)}, res);
    for (int d : res.vec) {
        sum += d * d;
    }
    return sum;
}

int bitsery_str_hash(uint8_t *buf, int size) {  
    MyString res;
    int hash = 0;
    Buffer buffer(buf, buf + size);
    auto state = bitsery::quickDeserialization<InputAdapter>({buffer.begin(), static_cast<size_t>(size)}, res);
    // printf("str = %s\n",res.str.c_str());
    int p = 131;
    int mod = 1e9 + 7;
    for (char c : res.str) {
        hash = (hash * p + static_cast<int>(c)) % mod;
    }
    return hash;
}

void add(int a,int b) {
    cout << a + b << endl;
}
void printListString(ListString test) {
//     printf("size of ListString = %d\n",sizeof (test));
//     for (int i = 0; i < 10; i++) {
//         printf("str[%d] = %s\n",i,test.str[i]);
//     }
// }
}

int my_arr_sum(vector<int> &test,int len) {
    int sum = 0;
    int n = test.size();
    for (int i = 0; i < n; i++) {
        sum += test[i] * test[i];
    }
    // cout << sum << endl;

    return sum;
}

double my_distance(vector<double> &points, int len) {
    if (points.size() < 4) {
        // printf("args error!\n");
        return 0;
    }
    double res = 0;
    double x1 = points[0], y1 = points[1];
    double x2 = points[2], y2 = points[3];
    res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return res;
}

double proto_distance(uint8_t *buf, int len) {
    ArrayDouble *arr = array_double__unpack(nullptr, len, buf);
    if (arr->n_arr < 4) {
        // printf("args error!\n");
        return 0;
    }
    
    double *points = arr->arr;
    double res = 0;
    double x1 = points[0], y1 = points[1];
    double x2 = points[2], y2 = points[3];
    res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return res;
}


int proto_arr_sum(void *buf, int len) {
    Array *arr = array__unpack(nullptr,len,static_cast<uint8_t*>(buf));
    int sum = 0;

    int n = arr->n_arr;
    for (int i = 0; i < n; i++) {
        sum += arr->arr[i] * arr->arr[i];
    }

    return sum;
}

int my_str_hash(string &str, int len) {
    int p = 131;
    int mod = 1e9 + 7;
    int res = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        res = (res * p + static_cast<int>(str[i])) % mod; 
    }
    return res;
}

int proto_str_hash(void *buffer,int len) {
    int p = 131;
    int mod = 1e9 + 7;
    int res = 0;

    Person *per = person__unpack(nullptr,len,static_cast<uint8_t*>(buffer));
    char *str = per->name;
    // printf("str = %s\n",str);
    for (int i = 0;str[i] != '\0'; i++) {
        res = (res * p + static_cast<int>(str[i])) % mod; 
    }

    return res;
}

void* my_split(string &str, int len) {
    // printf("str = %s\n",str.c_str());
    char c = '.';
    vector<string> res;
    int i = 0, j = 0, n = str.size();
    while (i < n) {
        while (j < n && str[j] != c) {
            j++;
        }
        res.push_back(str.substr(i,j - i));
        i = j + 1;
        j = i;
    }
    // for (auto &s : res) {
    //     printf("s = %s ",s.c_str());
    // }
    // printf("\n");
    return &res;
}

void* proto_split(uint8_t *buf, int len) {
    Person *p = person__unpack(nullptr,len,buf);
    // cout << "?\n";
    // cout << p << endl;
    // cout << p->name << endl;
    string str(p->name);
    // cout << str << endl;

    char c = '.';
    vector<string> res;
    int i = 0, j = 0, n = str.size();
    while (i < n) {
        while (j < n && str[j] != c) {
            j++;
        }
        res.push_back(str.substr(i,j - i));
        i = j + 1;
        j = i;
    }
    // for (auto &s : res) {
    //     printf("s = %s ",s.c_str());
    // }
    // printf("\n");
    return &res;
}

double my_bmi(My_Person_Info *person_info, int len) {
    double bmi = 0;
    double height = person_info->height, weight = person_info->weight;
    bmi = weight / (height * height);
    // string res = person_info->name + " BMI:" + to_string(bmi);
    // printf("%s\n",res.c_str());
    return bmi;
}

double proto_bmi(uint8_t* buf, int len) {
    PersonInfo *person_info = person__info__unpack(nullptr,len,buf);
    double bmi = 0;
    double height = person_info->height, weight = person_info->weight;
    bmi = weight / (height * height);
    // string res = string(person_info->name) + " BMI:" + to_string(bmi);
    // printf("%s\n",res.c_str());
    return bmi;
}

void map_test(map<int,int> &mp, int len) {
    // if (mp.find(2) != mp.end()) {
    //     printf("mp[2] = %d\n",mp[2]);
    // } else {
    //     printf("should not be here\n");
    // }

    // if (mp.find(10) == mp.end()) {
    //     printf("should be here\n");
    // }
    for (int i = 0; i < 10; i++) {
        // printf("mp[%d] = %p mp[%d].c_str() = %p, mp[%d] = %s\n",i,&mp[i],i,mp[i].c_str(),i,mp[i].c_str());
        printf("mp[%d] = %p, mp[%d] = %d\n",i,&mp[i],i,mp[i]);
    }

    // for (auto &[k,v] : mp) {
    //     printf("[%d,%d]\n",k,v);
    // }
}
}




int main(int argc,char *argv[]) {
    return 0;
}