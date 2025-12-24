target_sources(${BUBBLE_SORT_LIB}
	PRIVATE
		bubble_sort.cpp
	PUBLIC
		bubble_sort.hpp
)

target_include_directories(${BUBBLE_SORT_LIB} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)