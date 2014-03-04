cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME wait_for_termination)

project(${PROJECT_NAME} CXX)

find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    message("-- Boost version is: ${Boost_VERSION}")
else()
    message(FATAL "Boost required")
endif()

include_directories(hdr)
include_directories(hdr/application/include)
include_directories(hdr/singularity)
include_directories(hdr/type_index/include)

add_definitions(-DBOOST_APPLICATION_FEATURE_NS_SELECT_BOOST)

file(GLOB SRC_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})


