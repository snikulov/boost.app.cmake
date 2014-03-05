// -----------------------------------------------------------------------------
// limit_single_instance_callback.cpp : examples that show how use 
// Boost.Application to make a simplest interactive (terminal) application 
//
// Note 1: The Boost.Application (Aspects v4) and this sample are in 
//         development process.
// -----------------------------------------------------------------------------

// Copyright 2011-2013 Renato Tegon Forti
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying 
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// -----------------------------------------------------------------------------

#include <iostream>
#include <boost/application.hpp>
//#include <boost/uuid/string_generator.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

using namespace boost::application;

class myapp
{
public:

   ~myapp()
   {
      std::cout << "~myapp()" << std::endl;
   }

   void work_thread()
   {
      while(1)
      {
         boost::this_thread::sleep(boost::posix_time::seconds(2));
      }
   }

   // param
   int operator()(context& context)
   {
      boost::thread thread(boost::bind(&myapp::work_thread, this));
      context.find<wait_for_termination_request>()->wait();
      return 0;
   }

   bool stop(context &context)
   {

      return true;
   }

};

// main

int main(int argc, char *argv[])
{   
   myapp app;
   context app_context;
   handler<>::parameter_callback callback = boost::bind<bool>(&myapp::stop, &app, _1);
   app_context.insert<termination_handler>(boost::make_shared<termination_handler_default_behaviour>(callback));
   return launch<common>(app, app_context);
}
