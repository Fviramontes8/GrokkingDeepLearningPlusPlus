cmake_minimum_required(VERSION 3.8..3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
	MatrixNN
	VERSION 1.0
	DESCRIPTION "A simple neural network taking multiple inputs and outputs"
	LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(app)
