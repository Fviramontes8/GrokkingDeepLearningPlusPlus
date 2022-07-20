cmake_minimum_required(VERSION 3.8..3.20)

add_executable(test_inner_product inner_prod.cpp)
add_test(inner_product test_inner_product)
