/*
 * @Author: zwb 
 * @Date: 2021-02-01 11:17:00 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-01 11:24:28
 * @Desc: 一般继承，无虚函数覆盖
 */
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f()
    {
        cout << "Base::f" << endl;
    }
    virtual void g()
    {
        cout << "Base::g" << endl;
    }
};

class Derive : public Base
{

};

int main()
{
    Base* b = new Derive();
    b->f();
}


