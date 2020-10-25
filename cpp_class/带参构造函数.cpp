#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength( void );
    Line(double len); // 构造函数

private:
    double length;
};

// 成员函数定义，包括构造函数
Line::Line(double len) {
    cout << "Object is being created" << endl;
    length = len;
}
// 等同于初始化列表的方式
//Line::Line(double len): length(len)
//{
//    cout << "Object is being created" << endl;
//}

double Line::getLength() {
    return length;
}

int main()
{
    Line line(10);

    // 获取默认设置的长度
    cout << "Length of line: " << line.getLength() << endl;
    // 再次设置长度
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}

