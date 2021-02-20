/*
 * @Author: zwb 
 * @Date: 2021-02-08 21:18:51 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-08 21:29:49
 */
#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

// 将函数中的形参改为指针，可以减少内存空间使用，而且不会复制新的副本出来
void print(const student* p)
{
    // p->score = 90;  // 错误，不可修改
    cout << "姓名： " << p->name << "\n"
         << "年龄： " << p->age << "\n"
         << "分数： " << p->score << endl;
}

int main()
{
    student s = {"张三", 20, 100};
    print(&s);
    cout << "分数： " << s.score << endl;
    return 0;
}