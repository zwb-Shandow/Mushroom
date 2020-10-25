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

// 基类
class PaintCost
{
public:
    int getConst(int area)
    {
        return area * 70;
    }
};

// 派生类
class Rectangle: public Shape, public PaintCost
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
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    cout << "Total area: " << Rect.getArea() << endl;

    cout << "Total paint cost: " << Rect.getConst(area) << endl;

    return 0;
}