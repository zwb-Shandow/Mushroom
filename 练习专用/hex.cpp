/*
 * @Author: zwb 
 * @Date: 2021-02-02 08:20:29 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-02-02 08:40:46
 * @Desc: 16进制
 */

#include <iostream>
#include <iomanip>

const uint8_t DATA_HEADER[] = {0xBD, 0xDB, 0x0B};

int main()
{
    // std::cout <<  std::hex << int(DATA_HEADER[0]) << std::endl;
    std::cout << DATA_HEADER[0] << std::endl;

    return 0;
}
