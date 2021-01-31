/*
 * @Author: zwb 
 * @Date: 2021-01-29 16:18:53 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 12:52:52
 */
#include <iostream>
#include <functional>

// 普通函数
int add(int a, int b)
{
    return a+b;
}

// lambda表达式
auto mod = [](int a, int b)
{
    return a%b;
};

// 函数对象类
struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator/divisor;
    }
};

int main()
{
    divide di;
    std::function<int(int, int)> a = add;
    std::function<int(int, int)> b = mod;
    std::function<int(int, int)> c = divide();

    std::cout << add(3,4) << std::endl;
    std::cout << mod(2,1) << std::endl;
    std::cout << di.operator()(10, 2) << std::endl;

    return 0;
}

