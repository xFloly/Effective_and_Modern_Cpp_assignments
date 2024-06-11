include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        String_Test.cpp
        ../../impl/String.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)
#target_link_libraries(Google_Tests_run impl)
