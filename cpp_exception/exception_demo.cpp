#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main()
{
    string str = "http://c.biancheng.net";
    try{
        char ch1 = str[100];  //下标越界，ch1为垃圾值
        cout << ch1 << endl;
    }catch(exception e){
        cout << "[1] out of bound!" << endl;
    }
    try{
        char ch2 = str.at(100);
        cout << ch2 << endl;
    }catch(exception &e){
        cout << "[2] out of bound!" << endl;
    }
    // char ch2 = str.at(100);  //下标越界，抛出异常
    // cout << ch2 << endl;

    return 0;
}