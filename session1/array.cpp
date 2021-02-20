//
// Created by zwb on 2020/10/22.
//
#include <iostream>
using namespace std;

int main()
{
    // 一维数组
    int arr[5] = {0,1,2,3,4};
    cout << "数组长度为：" << sizeof(arr) << endl;

    cout << "数组单个元素长度为：" << sizeof(arr[0]) << endl;

    cout << arr << endl;

    // 二维数组
    int arrs[2][2] = {{1,2}, {3,4}};
    cout << arrs << endl;
    cout << arrs[0][2] << endl;

    return 0;
}
