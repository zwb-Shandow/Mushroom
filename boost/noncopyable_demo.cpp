/*
 * @Author: zwb 
 * @Date: 2021-01-27 22:05:01 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-28 08:43:42
 * @Desc: noncopyable介绍
 */

/*
 * 通常情况下, 要写一个单例类就要在类的声明把它们的构造函数, 赋值函数, 析构函数, 
 * 复制构造函数隐藏* 到private或者protected之中, 每个类都这么做麻烦.
 * 有noncopyable类, 只要让单例类直接继承noncopyable. 
 * class noncopyable的基本思想是把构造函数和析构函数设置protected权限，这样子类可以调用，
 * 但是外面的类不能调用，那么当子类需要定义构造函数的时候不至于通不过编译。
 * 但是最关键的是noncopyable把复制构造函数和复制赋值函数做成了private，
 * 这就意味着除非子类定义自己的copy构造和赋值函数，否则在子* 类没有定义的情况下，
 * 外面的调用者是不能够通过赋值和copy构造等手段来产生一个新的子类对象的
 */
 

#include <boost/noncopyable.hpp>

class myclass : public boost::noncopyable
{
public:
    myclass(){};
    myclass(int i){};
};

int main()
{
    myclass cl1();
    myclass cl2(1);

    // myclass cl3(cl1); // error，禁止拷贝

    return 0;
}