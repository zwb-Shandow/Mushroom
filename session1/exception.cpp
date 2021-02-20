//
// Created by zwb on 2020/10/23.
//
#include <iostream>
using namespace std;

int main()
{
    // throw 异常
//    int a;
//    cout << "请输入一个100以内整数：" << endl;
//    cin >> a;
//    if (a < 100) {
//        cout << "输入正确" << endl;
//    } else {
//        throw out_of_range("your input is out of range");
//    }

    // try...catch异常
    int a=10, b;
//    b = a/0;
    try {
        b = a / 0;
    } catch (exception) {
        cout << "exception" << endl;
    }


    return 0;

}
