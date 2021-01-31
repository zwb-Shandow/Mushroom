/*
 * @Author: zwb 
 * @Date: 2021-01-04 23:05:08 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-05 23:38:58
 */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// vector是类模板
void init()
{
    vector<int> v1;  // v1是空vector
    vector<int> v2(v1);
    // 列表初始化
    vector<string> v3{"a", "an", "the"};
    // 创建指定数量的元素
    vector<int> v4(10,0); // 10个int类型元素，统一初始化为0
}

// 向vector添加元素
void add_element()
{
    vector<int> v2;  //空vector
    for (int i=0; i!=100; ++i)
        v2.push_back(i);
}

// vector中元素求平方
void sqrt()
{
    vector<int> v{1,2,3,4,5,6};
    for (auto &i : v)  //通过引用为v的元素赋值
        i *= i;
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    add_element();
    sqrt();
    return 0;
}