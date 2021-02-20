/*
 * @Author: zwb 
 * @Date: 2021-02-07 17:24:50 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-07 17:42:50
 * @Desc: 函数调用时，实参将数值传入形参；形参不会影响实参
 * 函数为值传递时，形参改变不会影响实参
 */

#include <iostream>
using namespace std;

// 两个数值交换
void swap(int num1, int num2)
{
    cout << "交换前num1： " << num1 << endl;
    cout << "交换前num2： " << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "交换后num1： " << num1 << endl;
    cout << "交换后num2： " << num2 << endl;
}


int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << "主函数中a： " << a << endl;
    cout << "主函数中b： " << b << endl;
    return 0;
}
