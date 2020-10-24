#include <iostream>

using namespace std;

// 函数声明
int hls(int& a1, int& a2, int& b1, int& b2);

int main()
{
    int x1 = 11;
    int x2 = 9;
    int y1 = 15;
    int y2 = 14;
    int result;
    result = hls(x1, x2, y1, y2);
    cout << result << endl;

    return 0;
}

// 函数定义
int hls(int& a1, int& a2, int& b1, int& b2)
{
    int temp;
    temp = a1 * b2 - a2 * b1;
    return temp;
}

