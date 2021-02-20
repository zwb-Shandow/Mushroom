/*
 * @Author: zwb 
 * @Date: 2021-01-28 08:46:25 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-28 09:24:28
 * @Description: 建立结构体数组时，只写带参的构造函数会出现无法初始化的错误
 */
#include <iostream>
#include <string>

using namespace std;

struct node
{
    int data;
    string str;
    char x;

    // 自定义的初始化函数
    void init(int a, string b, char c){
        this->data = a;
        this->str = b;
        this->x = c;
    }
    node() : data(), str(), x() {}
    node(int a, string b, char c) : data(a), str(b), x(c){}
}N[10];

int main()
{
    N[0] = {1, "hello", 'c'};
    N[1] = {2, "C++", 'd'};
    N[2].init(3, "Java", 'e');
    N[3] = node(4, "Python", 'f');
    N[4] = {5, "Python3", 'p'};

    for (int i = 0; i < 5; i++)
    {
        cout << N[i].data << " " << N[i].str << " " << N[i].x << endl;
    }
    return 0;
    
}
