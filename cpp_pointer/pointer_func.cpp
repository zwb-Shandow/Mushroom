/*
 * @Author: zwb 
 * @Date: 2021-02-07 22:55:13 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-08 09:25:41
 * @Desc: 指针和函数
 * 地址传递可以修饰实参，值传递不可修改实参
 */
#include <iostream>
using namespace std;

void swap(int*, int*);

int main()
{
    int a = 10;
    int b = 20;
    swap(&a, &b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}