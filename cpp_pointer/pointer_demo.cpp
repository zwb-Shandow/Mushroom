#include<iostream>
#include<stdlib.h>

/****************************
指针作为参数进行传递，是将实参的一个拷贝传递给形参，
是值传递，想同步修改实参，需要用引用
****************************/

using namespace std;

void swap_int(int *a, int *b)
{
    int *temp = a;
    cout << a << endl;
    cout << b << endl;
    a = b;
    cout << a << endl;
    b = temp;
}

void test(int *p)
{
    int a = 1;
    p = &a;
    cout << p << " " << *p << endl;
}

int main()
{
    int a = 1, b = 2;
    int *p=NULL;
    swap_int(&a, &b);
    cout << a << " " << b << endl;
    test(p);
    if (p==NULL)
    {
        cout << "空指针" << endl;
    }

    return 0;
}