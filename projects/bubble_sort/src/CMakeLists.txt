
set(TEST_SORT_LIB "bubble_sort_lib")
add_library(${TEST_SORT_LIB}
	bubble_sort.cpp
	bubble_sort.hpp
)

target_include_directories(${TEST_SORT_LIB} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)