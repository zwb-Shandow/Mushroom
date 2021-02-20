/*
 * @Author: zwb 
 * @Date: 2021-01-30 20:22:30 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 20:24:44
 */
#ifndef SIMPLESERIAL_H
#define SIMPLESERIAL_H

#include <boost/asio.hpp>

class SimpleSerial
{
public:
    SimpleSerial(std::string port, unsigned int baud_rate)
    : io(), serial(io, port)
    {
        serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
    }

    void writeString(std::string s)
    {
        boost::asio::write(serial, boost::asio::buffer(s.c_str(), s.size()));
    }

    std::string readLine()
    {
        using namespace boost;
        char c;
        std::string result;
        for(;;)
        {
            asio::read(serial, asio::buffer(&c, 1));
            switch(c)
            {
                case '\r':
                    break;
                case '\n':
                    return result;
                default:
                    result+=c;
            }
        }
    }

private:
    boost::asio::io_service io;
    boost::asio::serial_port serial;


};

#endif