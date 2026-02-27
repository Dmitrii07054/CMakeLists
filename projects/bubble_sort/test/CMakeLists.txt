set(SOURCES
	test_bubble.cpp
)

set(TEST_SORT_LIB bubble_sort_lib)

add_executable(test_bubble ${SOURCES})
target_link_libraries(test_bubble
	gtest_main
	gmock_main
	${TEST_SORT_LIB}
)

add_test(test_bubble test_bubble)

