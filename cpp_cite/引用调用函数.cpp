#include <iostream>

using namespace std;

// 函数声明
void swap(int& x, int& y);

int main()
{
    //局部变量声明
    int a = 100;
    int b = 200;

    cout << "交换前，a = " << a << endl;
    cout << "交换前，b = " << b << endl;

    // 调用swap函数
    swap(a, b);

    cout << "交换后，a = " << a << endl;
    cout << "交换后，b = " << b << endl;

    return 0;
}

// 函数定义
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}

