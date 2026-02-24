set(SOURCES
	test_bubble.cpp
)

set(TEST_SORT_LIB bubble_sort_lib)

add_executable(test_bubble ${SOURCES})
target_link_libraries(test_bubble
	gtest_main
	gmock_main
<<<<<<< HEAD:projects/bubble_sort/test/CMakeLists.txt
	${TEST_SORT_LIB}
=======
	${BUBBLE_SORT_LIB}
>>>>>>> dad66dc158347d3881d6f878d489e1e6a3623c73:projects/unit_test_example/test/CMakeLists.txt
)

add_test(test_bubble test_bubble)









