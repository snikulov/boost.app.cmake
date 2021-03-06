cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

option(WITH_SAMPLES "Build boost::app samples" OFF)
option(WITH_UT   "Build boost::app tests"   ON)

if (NOT DEPS_LOCATION)
    set(DEPS_LOCATION "${CMAKE_BINARY_DIR}/deps")
endif()
add_subdirectory(ext/log4cplus)

include_directories(${DEPS_LOCATION}/include)
link_directories(${DEPS_LOCATION}/lib)
link_directories(${DEPS_LOCATION}/lib64)

find_package(Threads REQUIRED)
find_package(CppCheck)

# we will use static libs
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost
   COMPONENTS thread system date_time chrono regex
   filesystem atomic program_options unit_test_framework REQUIRED)

if (Boost_VERSION LESS 105600)
    message(FATAL "Required Boost version >= 1.56.0")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(BOOST_APP_ROOT "hdr/application")
get_filename_component(__abs_path ${BOOST_APP_ROOT} ABSOLUTE)
file(TO_CMAKE_PATH ${__abs_path} BOOST_APP_ROOT_PATH)

include_directories(hdr)
include_directories(${BOOST_APP_ROOT}/include)
include_directories(${BOOST_APP_ROOT}/example)

add_subdirectory(src)
if(WITH_SAMPLES)
    add_subdirectory(samples)
endif()

if(WITH_UT)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif()

