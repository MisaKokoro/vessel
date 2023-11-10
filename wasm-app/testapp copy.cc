/*
 * Copyright (C) 2019 Intel Corporation.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */


#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#include "testData.pb.h"
using namespace std;

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
    ArrayDouble arr;
    arr.ParseFromArray(buf,len);
    if (arr.arr_size() < 4) {
        // printf("args error!\n");
        return 0;
    }
    
    double res = 0;
    double x1 = arr.arr(0), y1 = arr.arr(1);
    double x2 = arr.arr(2), y2 = arr.arr(3);
    res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return res;
}


int proto_arr_sum(void *buf, int len) {
    Array arr;
    arr.ParseFromArray(buf,len);
    int sum = 0;

    int n = arr.arr_size();
    for (int i = 0; i < n; i++) {
        sum += arr.arr(i)* arr.arr(i);
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

    Person per;
    per.ParseFromArray(buffer,len);
    const string &str = per.name();
    // printf("str = %s\n",str);
    for (int i = 0;str[i] != '\0'; i++) {
        res = (res * p + static_cast<int>(str[i])) % mod; 
    }

    return res;
}

void* my_split(string &str, int len) {
    printf("str = %s\n",str.c_str());
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
    for (auto &s : res) {
        printf("s = %s ",s.c_str());
    }
    printf("\n");
    return &res;
}

void* proto_split(uint8_t *buf, int len) {
    Person p;
    p.ParseFromArray(buf,len);
    // cout << "?\n";
    // cout << p << endl;
    // cout << p->name << endl;
    const string &str = p.name();
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
    for (auto &s : res) {
        printf("s = %s ",s.c_str());
    }
    printf("\n");
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
    Person_Info person;
    person.ParseFromArray(buf,len);
    double bmi = 0;
    double height = person.age(), weight = person.weight();
    bmi = weight / (height * height);
    // string res = string(person_info->name) + " BMI:" + to_string(bmi);
    // printf("%s\n",res.c_str());
    return bmi;

}
}




int main(int argc,char *argv[]) {
    return 0;
}