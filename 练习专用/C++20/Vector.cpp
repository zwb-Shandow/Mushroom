/*
 * @Author: zwb 
 * @Date: 2021-01-11 23:18:16 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:23:05
 */
module;

export module Vector;

export class Vector
{
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};

Vector::Vector(int s)
    :elem{new double[s]}, sz{s}
{

}

double Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size()
{
    return sz;
}

export int size(const Vector& v) {return v.size();}