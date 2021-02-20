/*
 * @Author: zwb 
 * @Date: 2021-01-11 23:09:15 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:11:56
 */
#include "Vector.h"  // 获得Vector的接口

Vector::Vector(int s)
    : elem{new double[s]}, sz{s}
{

}

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}
