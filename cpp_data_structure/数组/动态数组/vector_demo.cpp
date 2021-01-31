/***********************************************************  
* File name: vector.cpp                                        *
* Time: 2020/12/12                                           
* Author: trunk    
* Description: 容器
***********************************************************/
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {1,2,3,4};
    cout << sizeof(v) << endl;
    v.push_back(12);  // 在末尾添加元素
    v.pop_back();  // 在末尾删除元素
    v.at(3);  // 读取第三个元素
    v[3];  // 读写第三个元素
    v.insert(v.begin()+3, 12);  // 将元素插在第三个位置上

    return 0;
}