cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME server)

project(${PROJECT_NAME} CXX)

set(SRC_FILES server_app.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS "_WIN32_WINNT=_WIN32_WINNT_VISTA")

set(EXT_LOG4CPLUS_NAME debug "log4cplusSD" optimized "log4cplusS" CACHE STRING "Log4cplus Libraries")

target_link_libraries(${PROJECT_NAME} ${EXT_LOG4CPLUS_NAME})

target_link_libraries(${PROJECT_NAME}
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${LIBZMQ_LIBRARIES}
	)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} ws2_32)
endif()

add_cppcheck(${PROJECT_NAME})
