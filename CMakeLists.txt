cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME} CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

option(WITH_SAMPLES "Build boost::app samples" OFF)
option(WITH_TESTS   "Build boost::app tests"   OFF)

# we will use static libs
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost
   COMPONENTS thread system date_time chrono regex
   filesystem atomic program_options unit_test_framework REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})
    message("-- Boost version is: ${Boost_VERSION}")
else()
    message(FATAL "Boost required")
endif()

find_package(ZMQ)
if(NOT LIBZMQ_FOUND)
    message(FATAL "LibZMQ not found")
endif()

include_directories(hdr)
include_directories(hdr/application/include)
include_directories(hdr/singularity)
include_directories(hdr/type_index/include)

add_definitions(-DBOOST_APPLICATION_FEATURE_NS_SELECT_BOOST)

add_subdirectory(src)
if(WITH_SAMPLES)
    add_subdirectory(samples)
endif()

if(WITH_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif()

