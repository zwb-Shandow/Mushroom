/*
 * @Author: zwb 
 * @Date: 2021-02-15 21:05:12 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 21:12:42
 */
#include <iostream>
using namespace std;

class Person
{
public:
    int m_A; // 属于类的对象上的
    static int m_B; // 不属于类的对象上
    void func() {} // 不属于类的对象上
    static void func2() {} // 不属于类的对象上
};

void test01()
{
    Person p; // C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    cout << sizeof(p) << endl;
}

int main()
{
    test01();

    return 0;
}