/*
 * @Author: zwb 
 * @Date: 2021-01-11 22:03:56 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:09:12
 */
#include <iostream>
using namespace std;

// struct Vector
// {
//     int sz;        // 元素数目
//     double* elem;  // 指向元素的指针
// };

// void vector_init(Vector& v, int s)
// {
//     v.elem = new double[s];  // 分配一个数组，包含s个double
//     v.sz = s;
// }

// double read_and_sum(int s)
// {
//     Vector v(s);
//     vector_init(v, s);

//     for (int i=0; i!=0; ++i)
//         cin >> v.elem[i];

//     double sum = 0;
//     for (int i=0; i!=s; ++i)
//         sum += v.elem[i];
//     return sum;
// }

// void f(Vector v, Vector& rv, Vector* pv)
// {
//     int i1 = v.sz;   // 通过名字访问
//     int i2 = rv.sz;  // 通过引用访问
//     int i3 = pv->sz; // 通过指针访问 
// }

class Vector
{
public:
    Vector(int s): elem{new double[s]}, sz{s} {}  //构造一个Vector，初始化列表
    double& operator[](int i){return elem[i]};
    int size() {return sz;}
private:
    double* elem;  // 指向元素的指针
    int sz;        // 元素数目
};

double read_and_sum(int s)
{
    Vector v(s);
    for (int i=0; i!=v.size();++i)
        cin >> v[i];

    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += v[i];
    return sum;
}