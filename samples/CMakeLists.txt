cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME boost_app_samples)

project(${PROJECT_NAME} CXX)

file(GLOB SRC_FILES *.cpp)

# create samples targets
foreach(SAMPLE_FILE ${SRC_FILES})

    get_filename_component(TARGET_NAME ${SAMPLE_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${SAMPLE_FILE})
    target_link_libraries(${TARGET_NAME}
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
	)
    if(UNIX)
        target_link_libraries(${TARGET_NAME} pthread)
    endif()
endforeach()

