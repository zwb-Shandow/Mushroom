/*
 * @Author: zwb 
 * @Date: 2021-01-30 21:13:37 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 21:45:54
 */
#include <iostream>
#include "SimpleSerial.h"

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
    try{
        SimpleSerial serial("dev/pts/6", 115200);
         serial.writeString("Hello world\n");
         while (true)
         {
             cout << "Received : " << serial.readLine() << " : end" << endl;
         } 
         
    } catch(boost::system::system_error& e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
