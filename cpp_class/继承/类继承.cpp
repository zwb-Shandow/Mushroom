#include <iostream>

using namespace std;

// 基类
class Shape
{
public:
    void setWidth(int w);
    void setHeight(int h);

protected:
    int width;
    int height;
};

void Shape::setWidth(int w) {
    width = w;
}

void Shape::setHeight(int h) {
    height = h;
}

// 派生类
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return width * height;
    }
};

int main()
{
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    cout << "Total area: " << Rect.getArea() << endl;

    return 0;
}