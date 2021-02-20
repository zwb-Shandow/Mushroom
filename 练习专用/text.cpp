/*
 * @Author: zwb 
 * @Date: 2021-01-10 21:35:26 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-10 22:44:25
 */
#include <iostream>
using namespace std;

int main()
{
    int i1 = 2.3;
    // int i2 {2.3};  // error
    int v1[10] = {1,2,3,4,5,6,7,8,9,10};
    // for (auto x: v1)  // 会将v1的值拷贝到x
    //     cout << x << endl;

    for (auto& x : v1)
        cout << ++x << endl;

    return 0;
}