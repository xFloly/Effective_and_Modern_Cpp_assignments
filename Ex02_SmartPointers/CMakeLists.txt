cmake_minimum_required(VERSION 3.27)
project(SmartPointers)

set(SOURCE_FILES_4 impl/Ex4_String.cpp)

add_executable(smart_pointer_run_4 ${SOURCE_FILES_4})

include_directories(impl)

add_subdirectory(impl)
add_subdirectory(Google_tests)

target_link_libraries(smart_pointer_run_4 gtest gtest_main)