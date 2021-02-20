/*
 * @Author: zwb 
 * @Date: 2021-01-11 23:04:44 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:06:12
 */

class Vector
{
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};