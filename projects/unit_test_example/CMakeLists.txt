project(unit_test_example)

set(BUBBLE_SORT_LIB "bubble_sort_lib55555")
add_library(${BUBBLE_SORT_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
