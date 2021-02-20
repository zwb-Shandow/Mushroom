/*
 * @Author: zwb 
 * @Date: 2021-02-08 16:55:25 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-08 17:04:34
 */
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    Student s = {"张三", 19, 90};

    Student* p = &s;
    
    cout << "姓名： " << p->name << "\n"
         << "年龄： " << p->age << "\n"
         << "分数： " << p->score << endl;
         return 0; 
}