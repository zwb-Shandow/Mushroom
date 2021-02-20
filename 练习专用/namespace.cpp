/*
 * @Author: zwb 
 * @Date: 2021-01-11 23:27:42 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-11 23:31:26
 */
#include <iostream>
namespace Mycode{
    class Complex{
        // ..
    };

    Complex sqrt(Complex);

    int main();
}

int My_code::main()
{
    Complex z{1,2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << '}\n';
}

int main()
{
    return My_code::main();
}
