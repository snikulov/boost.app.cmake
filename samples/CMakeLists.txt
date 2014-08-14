cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME} CXX)

set(BOOST_APP_EXAMPLE_PATH ${BOOST_APP_ROOT_PATH}/example)

add_executable(simple_application ${BOOST_APP_EXAMPLE_PATH}/simple_application.cpp)

add_executable(simple_server ${BOOST_APP_EXAMPLE_PATH}/simple_server_application.cpp)

add_executable(server_with_auto_handler ${BOOST_APP_EXAMPLE_PATH}/simple_server_application_with_auto_handler.cpp)

add_executable(server_with_auto_handler_and_global_context.cpp ${BOOST_APP_EXAMPLE_PATH}/simple_server_application_with_auto_handler_and_global_context.cpp)


