/*
 * @Author: zwb 
 * @Date: 2021-01-11 23:23:31 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:27:12
 */
import Vector
#include <cmath>

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum += std::sqrt(v[i]);
    return sum;
}