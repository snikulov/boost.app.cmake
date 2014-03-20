#include <iostream>
#include <zmqapp/zmqapp.hpp>
#include <boost/application.hpp>
#include <boost/thread/thread.hpp>

using namespace boost::application;

zmqapp::zmqapp()
    : context_(1)
{
}

zmqapp::~zmqapp()
{
}

int zmqapp::operator()(boost::application::context& context)
{
    boost::thread t(boost::bind(&zmqapp::work_thread, this));
    context.find<wait_for_termination_request>()->wait();
    return 0;
}

bool zmqapp::stop(boost::application::context &context)
{
    std::cout << "Terminate requested!!!" << std::endl;
    socket_ptr_.reset();
    return true;
}


void zmqapp::work_thread()
{
    socket_ptr_.reset(new zmq::socket_t(context_, ZMQ_REQ));
    std::cout << "Connecting on 5555 port... Press <Ctrl>+<C> to interrupt" << std::endl;
    socket_ptr_->connect("tcp://localhost:5555");
    unsigned int request_nbr = 0;
    while(1)
    {
        request_nbr++;
        zmq::message_t request (6);
        memcpy ((void *) request.data (), "Hello", 5);
        std::cout << "Sending Hello " << request_nbr << "…" << std::endl;
        socket_ptr_->send (request);

        //  Get the reply.
        zmq::message_t reply;
        socket_ptr_->recv (&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }
}

