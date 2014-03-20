cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME console_server)

project(${PROJECT_NAME} CXX)

set(SRC_SRV_FILES console_server_app.cpp zmqapp_srv.cpp)
set(SRC_CLN_FILES console_server_app.cpp zmqapp_clnt.cpp)

add_executable(${PROJECT_NAME} ${SRC_SRV_FILES})
target_link_libraries(${PROJECT_NAME}
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${LIBZMQ_LIBRARIES}
	)

if(UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif()

add_executable(clnt ${SRC_CLN_FILES})
target_link_libraries(clnt
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${LIBZMQ_LIBRARIES}
	)

if(UNIX)
    target_link_libraries(clnt pthread)
endif()
