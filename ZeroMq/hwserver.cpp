/*
 * @Author: zwb 
 * @Date: 2021-01-19 22:13:15 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-19 22:33:00
 * @Description: 服务端
 */
#include <zmq.hpp>
#include <string.h>
#include <iostream>
#include <unistd.h>

int main() {
    // 准备上下文和套接字
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true)
    {
        zmq::message_t request;

        // 等待客户端请求
        socket.recv (&request);
        std::cout << "收到 Hello" << std::endl;

        // 做一些“处理”
        sleep(1);

        // 应答World
        zmq::message_t reply (5);
        memcpy ((void *) reply.data(), "World", 5);
        socket.send(reply);
    }
    return 0;
    
}
