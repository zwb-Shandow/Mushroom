/*
 * @Author: zwb 
 * @Date: 2021-02-15 09:10:04 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-15 10:11:17
 * @Desc: 封装
 */
#include <iostream>
using namespace std;

// 设计一个圆类，求圆的周长
class Circle
{
    double PI = 3.14;
private:
    int m_r;

public:
    double calculate(int r)
    {
        m_r = r;
        return 2 * PI * m_r;
    }
};

int main()
{
    Circle c;
    double m = c.calculate(3);
    cout << "周长： " << m << endl;
    
    return 0;
}