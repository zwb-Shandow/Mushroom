/***********************************************************  
* File name: asio.threadpool.hpp                                       
* Time: 2021/2/5                                           
* Author: trunk    
* Description: $description$                                      
***********************************************************/
#pragma once

#include <memory>
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

class AsioThreadPool{
public:
    explicit AsioThreadPool(int threadNum = 1)
        : work_(new boost::asio::io_service::work(service_))
    {
        for (int i = 0; i < threadNum; ++i) {
            threads_.create_thread(
                    boost::bind(&boost::asio::io_service::run, &service_));
        }
    }
    explicit AsioThreadPool(const AsioThreadPool &) = delete;

    AsioThreadPool &operator = (const AsioThreadPool &) = delete;

    virtual ~AsioThreadPool() {
        stop();
    }

    boost::asio::io_service &getIOService() {
        return service_;
    }

    void stop() {
        service_.stop();
        threads_.join_all();
    }

private:
    boost::asio::io_service service_;
    std::unique_ptr<boost::asio::io_service::work> work_;
    boost::thread_group threads_;
};