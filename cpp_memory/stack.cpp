/*
 * @Author: zwb 
 * @Date: 2021-02-09 11:19:57 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-09 11:33:40
 */
#include <iostream>
using namespace std;

int* func()
{
    // 栈区开辟
    // int a = 10;
    // return &a;  // 返回局部变量地址

    // 堆区开辟
    int* p = new int (10);
    return p;
}

int main()
{
    int* p = func();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}