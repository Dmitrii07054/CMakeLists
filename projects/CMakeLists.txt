cmake_minimum_required(VERSION 3.13)

project(CMakeLists)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(obuchaika)
add_subdirectory(bubble_sort)
add_subdirectory(unit_test_example)

set(CMAKE_SUPPRESS_REGENERATION true)

