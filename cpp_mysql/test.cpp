/***********************************************************  
* File name: test.cpp                                       
* Time: 2020/12/29                                           
* Author: trunk    
* Description: $description$                                      
***********************************************************/

#include <iostream>
#include <exception>
#include "MyDB.h"

using namespace std;

int main()
{
    MyDB db;
    //连接数据库
    try {
        db.initDB("localhost","root","123","test");
    }catch (...){
        cout << "init failed" << endl;
    };


    //将用户信息添加到数据库
    try {
        db.exeSQL("INSERT accounts values('zwb', '123');");
        db.exeSQL("INSERT accounts values('axin', '456');");
    }catch (...){
        cout << "exec failed" << endl;
    }


    //将所有用户信息读出，并输出
    db.exeSQL("SELECT * from accounts;");

    return 0;
}