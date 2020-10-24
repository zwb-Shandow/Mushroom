#include <iostream>
#include <cstring>

using namespace std;

// 函数声明
struct Demo
{
    char name[10000];
    int count;
};
void func1(Demo demo);
void func2(const Demo *demo_p);
void func3(const Demo& demo_ref);

int main()
{
    Demo my_demo;
    strcpy(my_demo.name, "zzz");
    my_demo.count = 123;

    Demo *my_demo_p = &my_demo;
    Demo& my_demo_ref = my_demo;

    // 方式1：传递实参
    func1(my_demo);

    // 方式2：传递指针
    func2(my_demo_p);

    // 方式3：传递引用
    func3(my_demo_ref);

    return 0;
}

void func1(Demo demo)
{
    cout << "func1: " << demo.name << endl;
}

void func2(const Demo *demo_p)
{
    cout << "func2: " << demo_p->name << endl;
}

void func3(const Demo& demo_ref)
{
    cout << "func3: " << demo_ref.name << endl;
}

