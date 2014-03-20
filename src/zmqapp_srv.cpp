#include <iostream>
#include <zmqapp/zmqapp.hpp>
#include <boost/application.hpp>
#include <boost/thread/thread.hpp>

using namespace boost::application;

zmqapp::zmqapp()
    : context_(1), socket_ptr_(nullptr)
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
    socket_ptr_->close();
    return true;
}


void zmqapp::work_thread()
{
    socket_ptr_.reset(new zmq::socket_t(context_, ZMQ_REP));
    socket_ptr_->bind ("tcp://*:5555");
    std::cout << "Server thread is running on 5555 port... Press <Ctrl>+<C> to interrupt" << std::endl;
    while(1)
    {
        zmq::message_t request;
        socket_ptr_->recv(&request);

        std::cout << "Received Hello" << std::endl;

        boost::this_thread::sleep(boost::posix_time::seconds(1));

        zmq::message_t reply(5);
        memcpy((void *) reply.data (), "World", 5);
        socket_ptr_->send(reply);
    }
}

