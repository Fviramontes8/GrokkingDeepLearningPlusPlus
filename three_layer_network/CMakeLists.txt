cmake_minimum_required(VERSION 3.8..3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
	ThreeLayerNetwork
	VERSION 1.0
	DESCRIPTION "A simple implementation of a three layer neural network"
	LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(app)

