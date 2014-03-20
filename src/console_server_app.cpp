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
#include <boost/bind.hpp>

#include "zmqapp/zmqapp.hpp"

using namespace boost::application;

// main
int main(int argc, char *argv[])
{
    zmqapp app;
    context app_context;
    handler<>::parameter_callback callback = boost::bind<bool>(&zmqapp::stop, &app, _1);
    app_context.insert<termination_handler>(boost::make_shared<termination_handler_default_behaviour>(callback));
    return launch<common>(app, app_context);
}
