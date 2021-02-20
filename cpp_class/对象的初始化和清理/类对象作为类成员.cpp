/*
 * @Author: zwb 
 * @Date: 2021-02-15 15:37:02 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 15:55:47
 * @Desc: 类对象作为类成员
 * 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身；析构顺序与构造顺序相反
 */
#include <iostream>
#include <string>
using namespace std;

class Phone
{
public:
    Phone(string pName)
    {
        m_PName = pName;
        cout << "Phone构造" << endl;
    }
    string m_PName;
};


class Person
{
public:
    Person(string name, string pName) : m_Name(name) , m_Phone(pName)
    {
        cout << "Person构造" << endl;
    }
    string m_Name;
    Phone m_Phone;
};

void test01()
{
    Person p("张三", "iphone");
}

int main()
{
    test01();
    return 0;
}
