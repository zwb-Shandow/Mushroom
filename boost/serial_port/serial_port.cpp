#include <string>
#include <vector>
#include "SerialCom.h"

MySerialPort::MySerialPort(const any_type& port_name) : pSerialPort(NULL)
{
    pSerialPort = new serial_port(m_ios);
    if (pSerialPort)
    {
        init_port(port_name, 8);
    }
}

MySerialPort::~MySerialPort()
{
    if (pSerialPort)
    {
        delete pSerialPort;
    }
}

bool MySerialPort::init_port(const any_type port, const unsigned int char_size)
{
    if (!pSerialPort)
    {
        return false;
    }

    pSerialPort->open(port, ec);

    pSerialPort->set_option(serial_port::baud_rate(115200), ec);
    pSerialPort->set_option(serial_port::flow_control(serial_port::flow_control::none), ec);
    pSerialPort->set_option(serial_port::parity(serial_port::parity::none), ec);
    pSerialPort->set_option(serial_port::stop_bits(serial_port::stop_bits::one), ec);
    pSerialPort->set_option(serial_port::character_size(char_size), ec);

    return true;
}

void MySerialPort::write_to_serial(const any_type data)
{
    size_t len = write(*pSerialPort, buffer(data), ec);
    cout << len << "\t" << data << "\n";
}

void MySerialPort::handle_read(char buf[], boost::system::error_code ec, std::size_t bytes_transferred)
{
    cout << "\nhandle_read: ";
    cout.write(buf, bytes_transferred);
}

void MySerialPort::read_from_serial()
{
    char v[10];
    async_read(*pSerialPort, buffer(v), boost::bind(&MySerialPort::handle_read, this, v, _1, _2));
}

void MySerialPort::call_handle()
{
    m_ios.run();
}