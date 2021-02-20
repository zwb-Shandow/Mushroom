/*
 * @Author: zwb 
 * @Date: 2021-02-08 21:31:51 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-09 10:42:54
 */
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string sName;
    int score;
};

struct Teacher
{
    string tName;
    Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
}

int main()
{
    // 创建3名老师的数组
    Teacher tArray[3];
    // 通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
}