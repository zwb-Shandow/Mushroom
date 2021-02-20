/*
 * @Author: zwb 
 * @Date: 2021-02-07 22:25:48 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-07 22:55:51
 * @Desc: 利用指针访问数组
 */
#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1,2,3,4,5};

    // 1.利用下标访问数组元素
    cout << arr[0] << endl;

    // 2.利用指针访问数组
    int* p = arr; // 数组名即数组首地址
    cout << *p << endl;
    p++;
    cout << *p << endl;
    return 0;
}