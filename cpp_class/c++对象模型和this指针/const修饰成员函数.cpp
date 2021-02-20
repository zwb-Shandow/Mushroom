/*
 * @Author: zwb 
 * @Date: 2021-02-15 21:49:19 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 22:00:22
 */
#include <iostream>
using namespace std;

// 常函数
class Person
{
public:
    // this指针的本质是指针常量，指针的指向是不可以修改的
    // const Person * const this
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const
    {
        this->m_B = 100;
    }

    int m_A;
    mutable int m_B; // 特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
void test02()
{
    const Person p; // 在对象前加const，变为常对象
    p.m_B = 100;
}