#include <iostream>

using namespace std;

class Box
{
private:
    double length;
    double height;
    double breadth;

    // 成员函数声明
public:
    double getVolume();
    void setLength(double len);
    void setBreadth(double bre);
    void setHeight(double hei);
};

// 成员函数定义
double Box::getVolume() {
    return length * height * breadth;
}

void Box::setLength(double len) {
    length = len;
}

void Box::setHeight(double hei) {
    height = hei;
}

void Box::setBreadth(double bre) {
    breadth = bre;
}

int main()
{
    Box Box1;
    Box Box2;
    double volume = 0.0;

    Box1.setLength(6.0);
    Box1.setHeight(5.0);
    Box1.setBreadth(7.0);

    Box2.setLength(12.0);
    Box2.setHeight(13.0);
    Box2.setBreadth(10.0);

    volume = Box1.getVolume();
    cout << "Box1的体积： " << volume << endl;

    volume = Box2.getVolume();
    cout << "Box2的体积： " << volume << endl;

    return 0;
}

