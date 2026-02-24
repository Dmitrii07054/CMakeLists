include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include)

add_executable(test_long_number test_long_number.cpp)

target_link_libraries(test_long_number
    long_number
    gtest_main
    gmock_main
)

add_test(NAME test_long_number COMMAND test_long_number)