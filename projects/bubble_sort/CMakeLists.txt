project(bubble_sort)

add_executable(${PROJECT_NAME} main.cpp bubble_sort.cpp)

add_subdirectory(src)

target_link_libraries(bubble_sort PRIVATE sort_lib)

target_include_directories(bubble_sort PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

