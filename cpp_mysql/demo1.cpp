/***********************************************************  
* File name: demo1.cpp                                       
* Time: 2020/12/30                                           
* Author: trunk    
* Description: mysql增删改查
***********************************************************/

#include <stdio.h>
#include <iostream>
#include <mysql/mysql.h>
using namespace std;

int main(int argc,char *argv[])
{
    MYSQL conn;
    int res;
    mysql_init(&conn);
    //"root":数据库管理员 "123":root密码 "test":数据库的名字
    if(mysql_real_connect(&conn, "localhost","root","123","mydb",3306,NULL,0))
    {
        cout << "connect success" << endl;
        res = mysql_query(&conn, "insert into user values('user','123456')");
    if(res)
    {
        printf("error\n");
    }
    else
    {
        printf("OK\n");
    }
    mysql_close(&conn);
    }else
    {
        cout << "connect failed" << endl;
    }
    return 0;
}