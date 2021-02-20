/*
 * @Author: zwb 
 * @Date: 2021-02-08 17:39:07 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-08 17:59:20
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

void print1(student s)
{
    cout << "姓名： " << s.name << "\n"
         << "年龄： " << s.age << "\n"
         << "分数： " << s.score << endl;
}

void print2(student* p)
{
    cout << "姓名： " << p->name << "\n"
         << "年龄： " << p->age << "\n"
         << "分数： " << p->score << endl;
}

int main()
{
    student s = {"张三", 19, 90};

    print1(s);
    print2(&s);
    return 0;
    
}
