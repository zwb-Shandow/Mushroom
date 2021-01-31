/*
 * @Author: zwb 
 * @Date: 2021-01-28 23:24:26 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-28 23:39:05
 */
#include <iostream>
using namespace std;

int main()
{
    cout << "----引用左值----" << endl;
    int a = 5;
    int &add_a(a);

    cout << "a=" << a << " &a=" << &a << endl;
    cout << "add_a=" << add_a << " &add_a=" << &add_a << endl;
    cout << "----------------" << endl;

    cout << "----右值引用----" << endl;
    int b = 10;
    // int &&add_b = std::move(b);
    int &&add_b(b+1);
    cout << "b=" << b << " " << " &b" << &b << endl;
    cout << "add_b=" << add_b << " " << " &add_b=" << &add_b << endl;
    add_b++;
    cout << "add+b++=" << add_b << " " << " &add_b++" << &add_b << endl;
    cout << "-------------------" << endl;

    return 0; 
}
