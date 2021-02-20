/*
 * @Author: zwb 
 * @Date: 2021-02-15 16:09:21 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 16:15:13
 * @Desc: 静态成员
 */
#include <iostream>
using namespace std;

class Person
{
public:
    static void func()
    {
        cout << "static void func调用" << endl;
    }
    static int m_A; // 静态成员变量
};

int Person::m_A = 0; // 类外初始化

void test01()
{
    Person p;
    p.func();
    Person::func();
}

int main()
{
    test01();
    return 0;
}