#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include "struct.h"
using namespace std;

inline void *vptr_add(void *p, uint32_t offset)
{
    return (void *)((uint8_t *)p + offset);
}
// class Serialize {
// public:
// vector复制，返回包括自身的offset
// vec：要复制的vector
// p：内存段开始的头指针
// offset：之前的数据已经占用了多少
template <typename T>
uint32_t copy_vector(const std::vector<T> &vec, void *p, uint32_t offset)
{ //[头指针][当前最后一位指针][最后一位指针][数据段]
    // p+=offset;
    uint32_t n = vec.size();
    *((uint32_t *)p) = 12 + offset; /////////////////////////////////// p+12+offset？
    *((uint32_t *)p + 1) = 12 + sizeof(T) * n + offset;
    *((uint32_t *)p + 2) = 12 + sizeof(T) * n + offset;
    uint32_t *st = (uint32_t *)p + 3;
    T *start = (T *)(st);
    for (uint32_t i = 0; i < n; i++)
    {
        *(start + i) = vec[i];
    }
    // std::copy_n(vec.data(), n, start);
    return offset + 12 + sizeof(T) * n;
}

// 字符串复制，返回包括自身的offset
// s：要复制的字符串
// p：内存段开始的头指针
// offset：之前的数据已经占用了多少
uint32_t copy_string(const std::string &s, void *p, uint32_t offset)
{
    // p+=offset;
    uint32_t n = s.size();
    if (n <= 10)
    { ////////////////////////////////////////本地存储[10B char数据][1B全0][1B长度]
        for (uint32_t i = 0; i < n; i++)
            *((char *)p + i) = s[i];
        *((uint8_t *)p + 11) = n; // 长度
        return offset + 12;
    }
    else
    { /////////////////////////////////////////////异地存储[4B char指针][4B size][1全0]
        char *data = (char *)p + 12;
        // for (uint32_t i = 0; i < n; i++)
        //     *(data + i) = s[i];
        std::copy_n(s.data(), n, data);
        *((uint32_t *)p) = 12 + offset; /////////////////////////*(char**)p=data;
        *((uint32_t *)p + 1) = n;
        *((uint32_t *)p + 2) = 2147483680; // 标志位为1   cout<<*((char*)(&s)+11)-'('<<endl;
        return offset + 12 + n;
    }
}

// uint32_t copy_person_info(MyPersonInfo &person_info, void *p, uint32_t offset)
// {
//     // build int
//     memcpy(p, &person_info, 24);
//     copy_string(person_info.name, (void*)(p + 24), offset + 24);
//     return offset + 36;
// }
/// @brief map类型内存构造 20230422
/// @tparam key类型
/// @tparam 值类型
/// @param mp 要构造的map
/// @param p 主机指针
/// @param liner 线性地址中数据段起始地址
/// @param offset 距离开始写入地址的偏移量（前面写了多少byte了）
/// @return 后续数据偏移量
////////map:12B [最小结点位置][根节点地址][结点数]
////////红黑树结点 [left][right][parent][bool is black要和pair内存对齐][pair<key,value>][中间0][35]  两个结点的pair相隔32B
////////STL红黑树结点[bool is black 8B][parent 8B][left 8B][right 8B][pair<key,value>]，rb_tree [8B compare][辅助结点48B，其中parent存根节点]
template <typename T1, typename T2>
uint32_t copy_map(map<T1, T2> &mp, void *p, uint32_t liner, uint32_t offset)
{
    liner += offset;
    p = vptr_add(p, offset);
    uint32_t n = mp.size();
    int s1 = sizeof(T1);
    int s2 = sizeof(T2);
    bool align = false;      // bool是否占4B
    uint32_t punit = max(s1, s2);
    int unit = 12 + 2*punit; // 每一个结点大小
    if (punit >= 4)  // bool和pair对齐
    {
        unit += 4;
        align = true; // 用4B存储
    }
    else
        unit += max(s1, s2);
    queue<uint64_t> qe;
    uint64_t root = *((uint64_t *)(&mp) + 2);
    qe.push(root);
    uint32_t counter = 1;        // 子树结点应该选第几个结点
    uint32_t cur = 0;            // 当前结点是第几个
    map<uint64_t, uint32_t> par; // 用于找parent，将内存地址对应到线性地址
    while (!qe.empty())
    {
        root = qe.front();
        qe.pop();
        uint32_t nodeoff = 12 + unit * cur; // 结点在线性地址中的偏移量
        void *add = vptr_add(p, nodeoff);           // 写入结点的地址（主机指针）
        par[root] = nodeoff;
        uint64_t is_black = *((uint64_t *)root);
        uint64_t parent = *((uint64_t *)root + 1);
        uint64_t left = *((uint64_t *)root + 2);
        uint64_t right = *((uint64_t *)root + 3);
        //T1 key = *(T1 *)((char *)root + unit - 2 * punit); ///////////////
        //T2 value = *(T2 *)((char *)root + unit - s2);      //////////////////
        T1 key=*(T1 *)((char *)root + 32);
        T2 value= *(T2 *)((char *)root + 32 + punit);  
        if (left != 0)
        {
            qe.push(left);
            *(uint32_t *)add = liner + 12 + unit * counter;
            counter++;
            // cout<<"enqueue left"<<qe.front()<<" "<<qe.size()<<endl;
        }
        else
        { // 左子树为0
            *(uint32_t *)add = 0;
        }
        if (right != 0)
        {
            qe.push(right);
            *((uint32_t *)add + 1) = liner + 12 + unit * counter;
            counter++;
        }
        else
        { // 右子树为0
            *((uint32_t *)add + 1) = 0;
        }
        *((uint32_t *)add + 2) = par[parent]; // parent
        // printf("%x:%d\n",root,par[root]);
        if (align)
        { // 4byte存
            *((uint32_t *)add + 3) = is_black;
        }
        else
        { // 2byte存
            *((uint16_t *)add + 6) = (uint16_t)is_black;
        }
        *(T1 *)((char *)add + unit - 2 * punit) = key;
        *(T2 *)((char *)add + unit - s2) = value;
        cur++;
        printf("root:%x key:%d value:%d left:%x right:%x parent:%x is_black:%d\n", root, key, value, left, right, parent, is_black);
    }
    *((uint32_t *)p) = par[*((uint64_t *)(&mp) + 3)]; // 最小结点地址
    *((uint32_t *)p + 1) = (uint32_t)(liner + 12);    // 根节点地址
    *((uint32_t *)p + 2) = n;                         // 结点数
    *((uint32_t *)p + 5) = liner + 4;                 // 根节点的parent指回map第二个指针
    return offset + 12 + unit * n;
}

uint32_t copy_map(map<int,string> &mp, void *p, uint32_t liner, uint32_t offset)
{
    liner += offset;
    p = vptr_add(p, offset);
    uint32_t n = mp.size();
    uint32_t node_size=16+4+12; ///////////////int string
    uint32_t data=offset+12+node_size*n;//写string的起始地址
    queue<uint64_t> qe;
    uint64_t root = *((uint64_t *)(&mp) + 2);
    qe.push(root);
    uint32_t counter = 1;        // 子树结点应该选第几个结点
    uint32_t cur = 0;            // 当前结点是第几个
    map<uint64_t, uint32_t> par; // 用于找parent，将内存地址对应到线性地址
    while (!qe.empty())
    {
        root = qe.front();
        qe.pop();
        uint32_t nodeoff = 12 + node_size * cur; // 结点在线性地址中的偏移量
        void *add = vptr_add(p, nodeoff);           // 写入结点的地址（主机指针）
        par[root] = nodeoff;
        uint64_t is_black = *((uint64_t *)root);
        uint64_t parent = *((uint64_t *)root + 1);
        uint64_t left = *((uint64_t *)root + 2);
        uint64_t right = *((uint64_t *)root + 3);
        //T1 key = *(T1 *)((char *)root + unit - 2 * punit); ///////////////
        //T2 value = *(T2 *)((char *)root + unit - s2);      //////////////////
        int key=*(int *)((uint64_t*)root + 4);
        //T2 value= *(T2 *)((char *)root + 32 + punit);  
        uint64_t sp=*((uint64_t*)root+5);
        uint64_t ssize=*((uint64_t*)root+6);
        if (left != 0)
        {
            qe.push(left);
            *(uint32_t *)add = liner + 12 + node_size * counter;
            counter++;
            // cout<<"enqueue left"<<qe.front()<<" "<<qe.size()<<endl;
        }
        else
        { // 左子树为0
            *(uint32_t *)add = 0;
        }
        if (right != 0)
        {
            qe.push(right);
            *((uint32_t *)add + 1) = liner + 12 + node_size * counter;
            counter++;
        }
        else
        { // 右子树为0
            *((uint32_t *)add + 1) = 0;
        }
        *((uint32_t *)add + 2) = par[parent]; // parent
        // printf("%x:%d\n",root,par[root]);
        *((uint32_t *)add + 3) = is_black;
       
        *(int *)((char *)add + 16) = key;
        *(uint32_t*)((char*)add+20)=data + liner;
        *(uint32_t*)((char*)add+24)=(uint32_t)ssize;
        *(uint32_t*)((char*)add+28)=2147483648;
        memcpy(vptr_add(p,data),(void*)sp,ssize);
        //printf("%s\n",_vptr_add(p,data));
        //*(T2 *)((char *)add + unit - s2) = value;
        //_copy_string(string s, void *p, uint32_t liner, uint32_t offset, uint32_t stroff)
        cur++;
        printf("root:%x key:%d ssize:%d sp:%x left:%x right:%x parent:%x is_black:%d copyed:%d\n", root, key, ssize,sp ,left, right, parent, is_black,data);
        printf("copyed:%s\n",vptr_add(p,data));
        data+=ssize+1;
    }
    *((uint32_t *)p) = par[*((uint64_t *)(&mp) + 3)]; // 最小结点地址
    *((uint32_t *)p + 1) = (uint32_t)(liner + 12);    // 根节点地址
    *((uint32_t *)p + 2) = n;                         // 结点数
    *((uint32_t *)p + 5) = liner + 4;                 // 根节点的parent指回map第二个指针
    return offset + 12 + node_size * n;
}

/// @brief 递归构造map结点，由于cpmap调用，使用不同的库文件
/// @tparam T1 
/// @tparam T2 
/// @param root 原结点地址
/// @param minn 寻找最小结点
/// @param p    写入地址指针
/// @param unit 结点大小
/// @param counter 本结点计数
/// @param par 父结点技术
int counter=0;
template <typename T1, typename T2>
void cpmap_node(uint64_t root,uint64_t minn,void *p,int par,int liner){
    bool align=false;
    int cur=counter;
    uint32_t punit = max(sizeof(T1), sizeof(T2));
    if(punit>=4)
        align=false;
    int unit = 12 + 2*punit; // 每一个结点大小
    if (punit >= 4)  // bool和pair对齐
    {
        unit += 4;
        align = true; // 用4B存储
    }
    else
        unit += max(sizeof(T1), sizeof(T2));
    void*add=vptr_add(p,12+unit*counter);
    if(root==minn){
        *((uint32_t *)p) = 12+unit*counter+liner; // 最小结点地址
    }
    uint64_t is_black = *((uint64_t *)root);
    uint64_t parent = *((uint64_t *)root + 1);
    uint64_t left = *((uint64_t *)root + 2);
    uint64_t right = *((uint64_t *)root + 3);
    counter++;
    T1 key=*(T1 *)((char *)root + 32);
    T2 value= *(T2 *)((char *)root + 32 + max(sizeof(T1),sizeof(T2)));  
    *((uint32_t *)add + 2) = 12 + unit * par + liner;                           //写parent
    if (align){ // 4byte存                                              //写is_black
            *((uint32_t *)add + 3) = is_black;
    }else{ // 2byte存
            *((uint16_t *)add + 6) = (uint16_t)is_black;
    }
    *(T1 *)((char *)add + unit - 2 * punit) = key;                      //写kv对
    *(T2 *)((char *)add + unit - sizeof(T2)) = value;
    if(left!=0){                                                        //写left
        *(uint32_t *)add = 12 + unit * (counter) +liner;
        cpmap_node<T1,T2>(left,minn,p,cur,liner);
        counter++;
    }else
        *(uint32_t *)add = 0;
    if(right!=0){                                                       //写right
        *((uint32_t *)add + 1) = 12 + unit * (counter)+liner;
        cpmap_node<T1,T2>(right,minn,p,cur,liner);
        counter++;
    }else
        *((uint32_t *)add + 1)=0;
    //printf("root:%lx key:%d value:%d left:%lx right:%lx parent:%lx is_black:%ld counter:%d\n", root, key, value, left, right, parent, is_black,counter);
}


/// @brief 存储红黑树
/// @tparam T1 
/// @tparam T2 
/// @param mp 
/// @param p 
/// @param liner 
/// @param offset 
/// @return 
template <typename T1, typename T2>
uint32_t cpmap(map<T1, T2> &mp, void *p, uint32_t liner, uint32_t offset)
{
    liner += offset;
    p = vptr_add(p, offset);
    uint32_t n = mp.size();
    uint64_t root = *((uint64_t *)(&mp) + 2);   //根结点位置
    uint64_t minn =*((uint64_t *)(&mp) + 3);    //最小结点地址
    cpmap_node<T1,T2>(root,minn,p,0,liner);         //递归构造结点
    *((uint32_t *)p + 1) = (uint32_t)(liner + 12);    // 根节点地址
    *((uint32_t *)p + 2) = n;                         // 结点数
    *((uint32_t *)p + 5) = liner + 4;                 // 根节点的parent指回map第二个指针
    //cout<<"done"<<endl;
    return offset;                               ////////////////////////////////////////return多少       
}


// x (uint64_t*)(&mp)+2