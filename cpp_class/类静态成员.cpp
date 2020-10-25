/*
 * 静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，
 * 所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，但是
 * 可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
 */

#include <iostream>

using namespace std;

class Box
{
public:
    static int objectCount;
    Box(double l=2.0, double b=2.0, double h=2.0);
    double Volume();

private:
    double length;
    double breadth;
    double height;
};

Box::Box(double l, double b, double h) {
    cout << "构造函数" << endl;
    length = l;
    breadth = b;
    height = h;
    objectCount++;
}

double Box::Volume() {
    return length * breadth * height;
}

// 初始化类Box的静态成员
int Box::objectCount = 0;

int main()
{
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);

    cout << "Total objects: " << Box::objectCount << endl;

    return 0;
}
