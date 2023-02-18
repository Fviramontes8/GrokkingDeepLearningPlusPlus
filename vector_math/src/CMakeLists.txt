set(HEADER_VECTOR_UTILS "${VectorMath_SOURCE_DIR}/include/vector_utils/vector_utils.hpp")

add_library(vector_utils_library vector_utils_impl.cpp ${HEADER_VECTOR_UTILS})

target_include_directories(vector_utils_library PUBLIC ../include)

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_VECTOR_UTILS})
