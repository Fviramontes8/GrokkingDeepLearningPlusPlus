cmake_minimum_required(VERSION 3.14)

add_executable(test_sum sum_test.cpp ../src/vector_utils_impl.cpp)
add_test(vector_sum test_sum)

add_executable(test_avg avg_test.cpp ../src/vector_utils_impl.cpp)
add_test(vector_avg test_avg)

add_executable(test_ele_add ele_add.cpp ../src/vector_utils_impl.cpp)
add_test(vector_element_add test_ele_add)

add_executable(test_ele_mult ele_mult.cpp ../src/vector_utils_impl.cpp)
add_test(vector_element_mult test_ele_mult)

add_executable(test_dot_product dot_product_test.cpp ../src/vector_utils_impl.cpp)
add_test(vector_dot_product test_dot_product)
