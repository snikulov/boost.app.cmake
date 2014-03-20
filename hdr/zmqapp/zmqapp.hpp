#include <cppzmq/zmq.hpp>
#include <boost/application.hpp>

class zmqapp
{
    public:
        zmqapp();

        ~zmqapp();

        void work_thread();

        int operator()(boost::application::context& context);

        bool stop(boost::application::context& context);

    private:
        zmq::context_t context_;
        boost::shared_ptr<zmq::socket_t> socket_ptr_;

};
