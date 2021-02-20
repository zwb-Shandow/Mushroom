/*
 * @Author: zwb 
 * @Date: 2021-01-31 12:11:33 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-31 13:22:30
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Base
{
public:
    int PublicBase;
    void PublicPrint(int num) 
    {
        PublicBase = num;
        std::cout << "PublicPrint(): " << PublicBase << std::endl;
    }
protected:
    int ProtectedBase;
    void ProtectedPrint(int num)
    {
        ProtectedBase = num;
        std::cout << "ProtectedPrint(): " << ProtectedBase << std::endl;

    }
private:
    int PrivateBase;
    void PrivatePrint(int num)
    {
        PrivateBase = num;
        std::cout << "PrivatePrint" << PrivateBase << std::endl;
    }
};

// 公有继承
class Derived : public Base
{
public:
    void DerivedPrint(int num)
    {
        std::cout << "DerivedPrint()" << std::endl;
        std::cout << "PublicBase: " <<PublicBase << std::endl;
        ProtectedPrint(num);
        std::cout << "ProtectedBase: " <<ProtectedBase << std::endl;
        // PublicPrint(num);

    }
};

// 保护继承
class Derived1 : protected Base
{
public:
    void DerivedPrint(int num)
    {
        std::cout << "Derived1Print()" << std::endl;
        std::cout << ProtectedBase << std::endl;
        PublicPrint(num);
        ProtectedPrint(num);
    }
};

// 私有继承
class Derived2 : private Base
{
public:
    void DerivedPrint()
    {
        std::cout << "Derived2Print()" << std::endl;
    }
};

int main()
{
    Derived der;
    der.PublicPrint(3);
    std::cout << der.PublicBase << std::endl;
    der.DerivedPrint(4);
    return 0;
}