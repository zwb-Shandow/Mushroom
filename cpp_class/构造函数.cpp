#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength( void );
    Line(); // 构造函数

private:
    double length;
};

// 成员函数定义，包括构造函数
Line::Line() {
    cout << "Object is being created" << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength() {
    return length;
}

int main()
{
    Line line;

    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}