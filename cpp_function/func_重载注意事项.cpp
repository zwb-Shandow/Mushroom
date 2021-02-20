/*
 * @Author: zwb 
 * @Date: 2021-02-15 08:47:45 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 08:58:51
 * @Desc: 函数重载注意事项
 * 1. 引用作为重载条件
 * 2. 函数重载碰到函数默认参数
 */
#include <iostream>
using namespace std;

// 1.引用作为重载条件
void func(int &a)
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a)
{
    cout << "func(const int &a)调用" << endl;
}

// 2.函数重载碰到默认参数，出现二义性，尽量不要在重载时设置默认参数


int main()
{
    int a = 10;
    func(a);
    func(10);
    return 0;
}