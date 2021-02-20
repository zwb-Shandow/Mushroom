/*
 * @Author: zwb 
 * @Date: 2021-02-14 22:22:54 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 08:46:29
 * @Desc: 函数重载
 * 满足条件：
 * --同一作用域下
 * --函数名称相同
 * --函数参数类型不同或者个数不同或者顺序不同
 * 注意：函数的返回值不可以作为函数重载条件
 */
#include <iostream>
using namespace std;

void func()
{
    cout << "func的调用" << endl;
}

void func(int a)
{
    cout << "func(int a)的调用" << endl;
}

void func(double a)
{
    cout << "func(double a)的调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a, double b)的调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b)的调用" << endl;
}

int main()
{
    func();
    func(3);
    func(3.14);
    func(3,3.14);
    func(3.14,3);
    return 0;
}
