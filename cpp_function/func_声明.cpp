/*
 * @Author: zwb 
 * @Date: 2021-02-07 20:38:55 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-07 20:42:28
 * @Desc: 声明可以有多次，定义只能有一次
 */
#include <iostream>
using namespace std;

int max(int, int);

int main()
{
    int num1 = 10;
    int num2 = 20;
    cout << max(num1, num2) << endl;
}


int max(int a, int b)
{
    return a > b ? a : b;
}