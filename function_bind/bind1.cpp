/*
 * @Author: zwb 
 * @Date: 2021-01-30 12:59:29 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 13:04:40
 * @Desc: bind绑定普通函数
 */
#include <boost/bind.hpp>
#include <iostream>
using namespace std;

double my_divide(double x, double y)
{
    return x/y;
}

int main()
{
    // bind第一个参数为函数名，普通函数做实参，会隐式转换成函数指针；_1,_2 占位符
    auto fn_half = bind(my_divide, _1, _2); 
    cout << fn_half(10,2) << '\n';
}
