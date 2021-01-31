/*
 * @Author: zwb 
 * @Date: 2021-01-30 13:06:43 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 14:21:07
 * @Desc: bind绑定一个成员函数
 */
#include <iostream>
#include <boost/bind.hpp>

struct Foo
{
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 10;
};

int main()
{
    Foo foo;
    // bind绑定成员函数时，第一个参数表示对象的成员函数指针，第二个参数表示对象的地址
    auto f = std::bind(&Foo::print_sum, &foo, std::placeholders::_2, std::placeholders::_1);
    f(5, 95);
    return 0;
}

