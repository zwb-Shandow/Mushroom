/*
 * @Author: zwb 
 * @Date: 2021-01-20 12:09:33 
 * @Last Modified by: zwb
 * @Last Modified time: 2021-01-20 13:43:04
 */
#include <zmq.hpp>
#include <string>
#include <iostream>

int main()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to hello world server ..." << std::endl;
    socket.connect("tcp://localhost:5555");

    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (5);
        memcpy(request.data(), "Hello", 5);
        std::cout << "Sending Hello " << request_nbr << "..." << std::endl;
        socket.send(request);

        zmq::message_t reply;
        socket.recv(&reply);
        std::cout << "Receive World " << request_nbr << std::endl;
    }
    return 0;
}