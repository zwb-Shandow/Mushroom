/*
 * @Author: zwb 
 * @Date: 2021-02-01 11:26:03 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-01 11:34:03
 * @Desc: 一般继承， 有虚函数覆盖
 */
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f(){cout << "Base::f" << endl;}
    virtual void g(){cout << "Base::g" << endl;}
    virtual void h(){cout << "Base::h" << endl;}
};

class Derive : public Base
{
    virtual void f(){cout << "Derive::f" << endl;}
    virtual void g1(){cout << "Derive::g1" << endl;}
    virtual void h1(){cout << "Derive::h1" << endl;}
};

int main()
{
    Base* b = new Derive();
    b->f();
}
