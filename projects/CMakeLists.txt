cmake_minimum_required(VERSION 3.13)

project(CMakeLists)

enable_testing()

add_subdirectory(lib/googletest ${CMAKE_BINARY_DIR}/googletest)

add_subdirectory(obuchaika)          
add_subdirectory(bubble_sort)
add_subdirectory(long_number)

set(CMAKE_SUPPRESS_REGENERATION true)
