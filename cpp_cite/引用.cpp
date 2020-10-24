#include <iostream>

using namespace std;

/* 1.不存在空引用，引用必须链接到一块合法内存
*  2.引用具有绑定关系
*  3.创建引用时必须初始化 
*/

int main()
{
    //变量声明
    int i;
    double d;

    //声明引用变量
    int& r = i;
    double& s = d;

    i = 5;
    cout << "Value of i: " << i << endl;
    cout << "Value of i reference: " << r << endl;

    d = 11.7;
    cout << "Value of d: " << d << endl;
    cout << "Value of d reference: " << s << endl;

    return 0;
}
