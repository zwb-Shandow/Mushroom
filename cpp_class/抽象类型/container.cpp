/*
 * @Author: zwb 
 * @Date: 2021-01-19 16:53:50 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-19 17:07:44
 * @Description: 抽象类，将接口与类实现细节分离
 */

class Container {
public:
    virtual double& operator[](int) = 0;  // 纯虚函数
    virtual int size() const = 0;  // 常量成员函数
    virtual ~Container() []  // 析构函数
};

class Vector_container : public Container {  // Vector_container实现了Container
public:
    Vector_container(int s) : v(s) {}  // 含有s个元素的Vector
    ~Vector_container() {}

    double& operator[](int i) override {return v[i];}
    int size() const override {return v.size();}
private:
    Vector v;
}
