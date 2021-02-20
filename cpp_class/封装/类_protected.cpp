#include <iostream>

using namespace std;

class Box
{
protected:
    double width;
};

class SmallBox:Box  // SmallBox是派生类
{
public:
    void setSmallWidth(double wid);
    double getSmallWidth();
};

// 子类成员函数
double SmallBox::getSmallWidth() {
    return width;
}

void SmallBox::setSmallWidth(double wid) {
    width = wid;
}

int main()
{
    SmallBox box;

    box.setSmallWidth(5.0);
    cout << "Width of box: " << box.getSmallWidth() << endl;

    return 0;
}

