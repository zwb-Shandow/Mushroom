/*
 * @Author: zwb 
 * @Date: 2021-02-15 14:55:11 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 15:27:26
 * @Desc: 深拷贝与浅拷贝
 */
#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age, int height)
    {
        m_Age = age;
        m_Height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }

    // 自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height; // 编译器默认实现的就是这行代码
        // 深拷贝操作
        m_Height = new int(*p.m_Height);
    }


    ~Person()
    {
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person的析构函数调用" << endl;
    }
public:
    int m_Age;
    int * m_Height;
};

void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为： " << p1.m_Age <<  "身高为： " << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2的年龄为： " << p2.m_Age <<  "身高为： " << *p2.m_Height << endl;
}

int main()
{
    test01();
    return 0;
}