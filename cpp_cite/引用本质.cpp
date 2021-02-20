/*
 * @Author: zwb 
 * @Date: 2021-02-14 21:31:12 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-14 21:42:59
 */
#include <iostream>
using namespace std;

void func(int& ref)  // 发现是引用，转换为 int* const ref = &a;
{
    ref = 100;  // ref是引用，转换为 *ref = 100
}

int main()
{
    int a = 10;

    int& ref = a;  // 自动转换为int* const ref = &a

    ref = 20;  // 内部发现ref是引用，自动转换为： *ref = 20;

    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    func(a);

    return 0;
}