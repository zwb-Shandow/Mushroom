#include <vector>
#include <string>
#include "SerialCom.h"

int main()
{
    try
    {
        MySerialPort()
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
