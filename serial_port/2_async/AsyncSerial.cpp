/*
 * @Author: zwb 
 * @Date: 2021-01-30 22:59:43 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-31 00:59:27
 */

#include "AsyncSerial.h"

#include <string>
#include <algorithm>
#include <thread>
#include <mutex>
#include <boost/bind.hpp>
#include <boost/shared_array.hpp>

using namespace std;
using namespace boost;

class AsyncSerialImpl: private boost::noncopyable
{
public:
    AsyncSerialImpl(): io(), port(io), backgroundThread(), open(false), error(false) {}

    boost::asio::io_service io;
    boost::asio::serial_port port;
    std::thread backgroundThread;
    bool open;
    bool error;
    mutable std::mutex errorMutex;

    std::vector<char> writeQueue;
    boost::shared_array<char> writeBuffer;
    size_t writeBufferSize;
    std::mutex writeQueueMutex;
    char readBuffer[AsyncSerial::readBufferSize];

    std::function<void (const char*, size_t)> callback;
};

AsyncSerial::AsyncSerial(const std::string& devname, unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity,
        asio::serial_port_base::character_size opt_csize,
        asio::serial_port_base::flow_control opt_flow,
        asio::serial_port_base::stop_bits opt_stop)
        : pimpl(new AsyncSerialImpl)
{
    open(devname,baud_rate,opt_parity,opt_csize,opt_flow,opt_stop);
}

void AsyncSerial::open(const std::string& devname, unsigned int baud_rate,
        asio::serial_port_base::parity opt_parity,
        asio::serial_port_base::character_size opt_csize,
        asio::serial_port_base::flow_control opt_flow,
        asio::serial_port_base::stop_bits opt_stop)
{
    if(isOpen()) close();

    setErrorStatus(true);
    pimpl->port.open(devname);
    pimpl->port.set_option(asio::serial_port_base::baud_rate(baud_rate));
    pimpl->port.set_option(opt_parity);
    pimpl->port.set_option(opt_csize);
    pimpl->port.set_option(opt_flow);
    pimpl->port.set_option(opt_stop);

    pimpl->io.post(boost::bind(&AsyncSerial::doRead, this));

    thread t(boost::bind(&asio::io_service::run, &pimpl->io));
    pimpl->backgroundThread.swap(t);
    setErrorStatus(false);
    pimpl->open=true;
}

bool AsyncSerial::isOpen() const
{
    return pimpl->open;
}

bool AsyncSerial::errorStatus() const
{
    lock_guard<mutex> l(pimpl->errorMutex);
    return pimpl->error;
}

void AsyncSerial::close()
{
    if(!isOpen()) return;

    pimpl->open=false;
    pimpl->io.post(boost::bind(&AsyncSerial::doClose, this));
    pimpl->backgroundThread.join();
    pimpl->io.reset();
    if(errorStatus())
    {
        throw(boost::system::system_error(boost::system::error_code(),
            "Error while closing the device"));
    }
}

void AsyncSerial::write(const char* data, size_t)
{
    lock_guard<mutex> l(pimpl->writeQueueMutex);
    pimpl->writeQueue.insert(pimpl->writeQueue.end(), data, data+size);
    pimpl->io.post(boost::bind(&AsyncSerial::doWrite, this));
}

void AsyncSerial::write(const std::vector<char>& data)
{
    lock_guard<mutex> l(pimpl->writeQueueMutex);
    pimpl->writeQueue.insert(pimpl->writeQueue.end(), data.begin(), data.end());
    pimpl->io.post(boost::bind(&AsyncSerial::doWrite, this));
}

void AsyncSerial::writeString(const std::string& s)
{
    lock_guard<mutex> l(pimpl->writeQueueMutex);
    pimpl->writeQueue.insert(pimpl->writeQueue.end(), s.begin(), s.end());
    pimpl->io.post(boost::bind(&AsyncSerial::doWrite, this));
}

AsyncSerial::~AsyncSerial()
{
    if(isOpen())
    {
        try {
            close();
        } catch(...){

        }
    }
}

void AsyncSerial::doRead()
{
    pimpl->port.async_read_some(asio::buffer(pimpl->readBuffer, readBufferSize),
            boost::bind(&AsyncSerial::readEnd, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}



