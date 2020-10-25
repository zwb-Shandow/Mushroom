#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength();
    Line();  // 构造函数声明
    ~Line(); // 析构函数声明
private:
    double length;
};

Line::Line() {
    cout << "Object is being created" << endl;
}

Line::~Line() {
    cout << "Object is being deleted" << endl;
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

    line.setLength(10.0);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}
