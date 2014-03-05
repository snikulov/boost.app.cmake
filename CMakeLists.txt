cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME} CXX)

# we will use static libs
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost
   COMPONENTS thread system date_time chrono regex
   filesystem atomic program_options REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIRS})
    message("-- Boost version is: ${Boost_VERSION}")
else()
    message(FATAL "Boost required")
endif()

include_directories(hdr)
include_directories(hdr/application/include)
include_directories(hdr/singularity)
include_directories(hdr/type_index/include)

add_definitions(-DBOOST_APPLICATION_FEATURE_NS_SELECT_BOOST)

add_subdirectory(src)
add_subdirectory(samples)
