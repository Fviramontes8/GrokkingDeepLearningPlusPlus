set(HEADER_LINEAR_NN "${MultiOutNN_SOURCE_DIR}/include/linear_nn/linear_nn.hpp")
add_library(linear_nn_library linear_nn_impl.cpp ${HEADER_LINEAR_NN})
target_include_directories(linear_nn_library PUBLIC ../include)

source_group(
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LINEAR_NN})
