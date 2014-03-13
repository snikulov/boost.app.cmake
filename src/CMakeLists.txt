cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME console_server)

project(${PROJECT_NAME} CXX)

set(SRC_FILES console_server_app.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME}
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
	)

if(UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif()
