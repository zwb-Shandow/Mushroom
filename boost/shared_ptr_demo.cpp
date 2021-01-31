/*
 * @Author: zwb 
 * @Date: 2021-01-28 15:20:30 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-28 15:44:04
 * @Description: 共享指针
 */
#include <boost/shared_ptr.hpp>
#include <vector>
#include <iostream>

using namespace std;

class X
{
public:
    X()
    {
        cout << "X..." << endl;
    }
    ~X()
    {
        cout << "~X..." << endl;
    }
};

int main()
{
    cout << "Entering main ..." << endl;
    boost::shared_ptr<X> p1(new X);
    cout << p1.use_count() << endl;
    boost::shared_ptr<X> p2=p1;

    cout << p2.use_count() << endl;
    p1.reset();
    cout << p2.use_count() << endl;
    p2.reset();
    cout << "Exiting main ..." << endl;
    
    return 0;
}