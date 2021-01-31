/***********************************************************  
* File name: demo.cpp                                       
* Time: 2020/12/29                                           
* Author: trunk    
* Description: $description$                                      
***********************************************************/
#include <iostream>
#include <string>

#include <mysql/mysql.h>

#pragma comment(lib,"libmysql.lib")

using namespace std;

//全局变量声明
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
unsigned int num_fields;


//连接数据库
bool ConnectDatabase()
{
    //初始化数据库
    mysql_init(&mysql);

    //连接到mysql server
    if ((mysql_real_connect(&mysql, "localhost","root","123","mydb",3306,NULL,0))){
        cout << "conn failed" << endl;
        return false;
    } else{
        cout << "conn success" << endl;
        cout << "mysql is: " << &mysql << endl;
        return true;
    }
}

//查询数据
void QueryData(string& query_sql_string){
    const char* query_buffer=query_sql_string.c_str();

    if (mysql_query(&mysql, query_buffer)){
        cout << "Query failed: " << mysql_error(&mysql) << &query_buffer << endl;
    } else{
        cout << "Query success" << endl;
//        res = mysql_store_result(&mysql);
//        num_fields = mysql_num_fields(res);
//        while ((row = mysql_fetch_row(res)) != NULL){
//            if (row[6] != NULL){
////                string temp_string = ResultConvertToJson(row);
////                ConvertUTF8ToGBK(temp_string);
//                cout << row << endl;
//            }
//        }
//        mysql_free_result(res);
    }
}

int main(){
    ConnectDatabase();
    string query_string = "select * from user";
    QueryData(query_string);
//    mysql_close(&mysql);
    return 0;
}