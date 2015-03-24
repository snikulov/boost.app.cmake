cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME} CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

option(WITH_SAMPLES "Build boost::app samples" OFF)
option(WITH_TESTS   "Build boost::app tests"   OFF)

if (NOT DEPS_LOCATION)
    set(DEPS_LOCATION "${CMAKE_BINARY_DIR}/deps")
endif()
add_subdirectory(ext/log4cplus)

include_directories(${DEPS_LOCATION}/include)
link_directories(${DEPS_LOCATION}/lib)

# we will use static libs
#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost
   COMPONENTS thread system date_time chrono regex
   filesystem atomic program_options unit_test_framework REQUIRED)

if (NOT Boost_FOUND)
    message(FATAL "Boost not found")
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(BOOST_APP_ROOT "hdr/application")
get_filename_component(__abs_path ${BOOST_APP_ROOT} ABSOLUTE)
file(TO_CMAKE_PATH ${__abs_path} BOOST_APP_ROOT_PATH)

include_directories(hdr)
include_directories(${BOOST_APP_ROOT}/include)
include_directories(${BOOST_APP_ROOT}/example)
if (Boost_VERSION LESS 105600)
    include_directories(hdr/type_index/include)
endif()

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

