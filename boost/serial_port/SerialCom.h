#ifndef SERIALCOM
#define SERIALCOM

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;

typedef string any_type;

class MySerialPort
{
private:
    bool init_port(const any_type port, const unsigned int char_size);
public:
    MySerialPort(const any_type& port_name){};
    ~MySerialPort(){};

    void write_to_serial(const any_type data);

    void read_from_serial();

    void handle_read(char buf[], boost::system::error_code ec, std::size_t bytes_transferred);

    void call_handle();

private:
    io_service m_ios;

    serial_port *pSerialPort;

    any_type m_port;

    boost::system::error_code ec;
};


#endif