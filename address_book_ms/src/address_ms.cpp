#include<iostream>
using namespace std;

// 声明显示菜单函数
void showMenu();

void showMenu()
{
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出联系人  *****" << endl;
}

int main()
{
    // 调用显示菜单
    showMenu();
    return 0;
}