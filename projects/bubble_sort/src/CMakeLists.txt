add_library(sort_lib STATIC
    bubble_sort.cpp
	bubble_sort.hpp
)

target_include_directories(sort_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)