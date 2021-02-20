/*
 * @Author: zwb 
 * @Date: 2021-01-25 22:09:00 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-25 22:32:42
 * @Description: 服务端
 */
#include <string>
#include <unistd.h>
#include <iostream>

#include <zmq.hpp>

int main()
{

    // initialize the zmq context with a signle IO thread
    zmq::context_t context{1};

    // construct a REP socket and bind to interface
    zmq::socket_t socket{context, ZMQ_REP};
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        // 等待客户端请求
        socket.recv (&request);
        std::cout << "收到 Hello" << std::endl;

        // 做一些处理
        sleep(1);

        // 应答World
        zmq::message_t reply(5);
        memcpy(reply.data(), "World", 5);
        socket.send (reply);
    }
    return 0;

}