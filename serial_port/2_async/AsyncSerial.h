/*
 * @Author: zwb 
 * @Date: 2021-01-30 21:57:32 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-30 22:59:09
 */

#ifndef ASYNCSERIAL_H
#define ASYNCSERIAL_H

#include <vector>
#include <memory>
#include <functional>
#include <boost/asio.hpp>
#include <boost/utility.hpp>

class AsyncSerialImpl;

class AsyncSerial: private boost::noncopyable
{
public:
    AsyncSerial();
    AsyncSerial(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=boost::asio::serial_port_base::parity(boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=boost::asio::serial_port_base::flow_control(
            boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=boost::asio::serial_port_base::stop_bits(
            boost::asio::serial_port_base::stop_bits::one
        ));

    void open(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=
            boost::asio::serial_port_base::parity(
                boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=
            boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=
            boost::asio::serial_port_base::flow_control(
                boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=
            boost::asio::serial_port_base::stop_bits(
                boost::asio::serial_port_base::stop_bits::one));

    bool isOpen() const;

    bool errorStatus() const;

    void close();

    void write(const char* data, size_t size);

    void write(const std::vector<char>& data);

    void writeString(const std::string& s);

    virtual ~AsyncSerial()=0;

    static const int readBufferSize=512;
private:
    void doRead();

    void readEnd(const boost::system::system_error& error, 
        size_t bytes_transferred);

    void doWrite();

    void writeEnd(const boost::system::system_error& error);

    void doClose();

    std::shared_ptr<AsyncSerialImpl> pimpl;
protected:
    void setErrorStatus(bool e);

    void setReadCallback(const std::function<void (const char*, size_t)>& callback);

    void clearReadCallback();
};

class CallbackAsyncSerial: public AsyncSerial
{
public:
    CallbackAsyncSerial();

    CallbackAsyncSerial(const std::string& devname, unsigned int baud_rate,
        boost::asio::serial_port_base::parity opt_parity=
            boost::asio::serial_port_base::parity(
                boost::asio::serial_port_base::parity::none),
        boost::asio::serial_port_base::character_size opt_csize=
            boost::asio::serial_port_base::character_size(8),
        boost::asio::serial_port_base::flow_control opt_flow=
            boost::asio::serial_port_base::flow_control(
                boost::asio::serial_port_base::flow_control::none),
        boost::asio::serial_port_base::stop_bits opt_stop=
            boost::asio::serial_port_base::stop_bits(
                boost::asio::serial_port_base::stop_bits::one));
    
    void setCallback(const std::function<void (const char*, size_t)>& callback);

    void clearCallback();

    virtual ~CallbackAsyncSerial();
};

#endif