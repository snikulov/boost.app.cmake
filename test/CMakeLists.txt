cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(PROJECT_NAME boost_app_tests)
project(${PROJECT_NAME} CXX)

set(BOOST_APP_TEST_PATH ${BOOST_APP_ROOT_PATH}/test)

add_executable(args_aspect_test ${BOOST_APP_TEST_PATH}/args_aspect_test.cpp)
target_link_libraries(args_aspect_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(args_aspect_test args_aspect_test)

add_executable(aspect_map_test ${BOOST_APP_TEST_PATH}/aspect_map_test.cpp)
target_link_libraries(aspect_map_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(aspect_map_test aspect_map_test)

add_executable(ensure_single_instance_test ${BOOST_APP_TEST_PATH}/ensure_single_instance_test.cpp)
target_link_libraries(ensure_single_instance_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(ensure_single_instance_test ensure_single_instance_test)

add_executable(global_context_test ${BOOST_APP_TEST_PATH}/global_context_test.cpp)
target_link_libraries(global_context_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(global_context_test global_context_test)

add_executable(handler_test ${BOOST_APP_TEST_PATH}/handler_test.cpp)
target_link_libraries(handler_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(handler_test handler_test)

add_executable(launch_test ${BOOST_APP_TEST_PATH}/launch_test.cpp)
target_link_libraries(launch_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(launch_test launch_test)

add_executable(path_aspect_test ${BOOST_APP_TEST_PATH}/path_aspect_test.cpp)
target_link_libraries(path_aspect_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(path_aspect_test path_aspect_test)

add_executable(signal_binder_test ${BOOST_APP_TEST_PATH}/signal_binder_test.cpp)
target_link_libraries(signal_binder_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(signal_binder_test signal_binder_test)

add_executable(simple_common_application_test ${BOOST_APP_TEST_PATH}/simple_common_application_test.cpp)
target_link_libraries(simple_common_application_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(simple_common_application_test simple_common_application_test)

add_executable(simple_server_application_test ${BOOST_APP_TEST_PATH}/simple_server_application_test.cpp)
target_link_libraries(simple_server_application_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_test(simple_server_application_test simple_server_application_test)

add_library(test_library SHARED ${BOOST_APP_TEST_PATH}/test_library.cpp)
get_target_property(__loc_name test_library LOCATION)
get_filename_component(_out_name ${__loc_name} NAME)

add_executable(shared_library_get_symbol_test ${BOOST_APP_TEST_PATH}/shared_library_get_symbol_test.cpp)
target_link_libraries(shared_library_get_symbol_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_dependencies(shared_library_get_symbol_test test_library)
add_test(NAME shared_library_get_symbol_test
         COMMAND shared_library_get_symbol_test ./${_out_name})

add_executable(shared_library_load_test ${BOOST_APP_TEST_PATH}/shared_library_load_test.cpp)
target_link_libraries(shared_library_load_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_dependencies(shared_library_load_test test_library)
add_test(NAME shared_library_load_test
         COMMAND shared_library_load_test ./${_out_name})

add_executable(shared_library_search_symbol_test ${BOOST_APP_TEST_PATH}/shared_library_search_symbol_test.cpp)
target_link_libraries(shared_library_search_symbol_test
        ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY} ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_ATOMIC_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK}
	)
add_dependencies(shared_library_search_symbol_test test_library)
add_test(NAME shared_library_search_symbol_test
         COMMAND shared_library_search_symbol_test ./${_out_name})

