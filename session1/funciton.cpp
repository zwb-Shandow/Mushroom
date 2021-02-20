//
// Created by zwb on 2020/10/22.
//
#include <iostream>
using namespace std;

void swap(int num1, int num2);

void swap(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    swap(a, b);

    cout <<  << endl;
    cout << b << endl;

    return 0;
}
