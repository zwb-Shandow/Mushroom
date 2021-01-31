#include<iostream>
#include<stdlib.h>

using namespace std;

/************
 引用进行参数传递时，传递的是实参
 可以节约时间，节约空间
 ***********/

// void test(int &a)
// {
//     cout << &a << " " << a << endl;
// }

// int main()
// {
//     int a=1;
//     cout << &a << " " << a << endl;
//     test(a);

//     return 0;
// }


/*******************************
  要达到同时修改指针的目的，需使用引用
 *******************************/
void test(int *&p)
{
    int a=1;
    p=&a;
    cout << p << " " << *p << endl;
}

int main()
{
    int *p=NULL;
    test(p);
    if (p!=NULL)
    {
        cout << "指针不为NULL" << endl;
        cout << p << " " << *p << endl;
    }
    return 0;
}