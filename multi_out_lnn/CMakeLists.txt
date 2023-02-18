cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(
	MultiOutNN
	VERSION 1.0
	DESCRIPTION "A simple NN that has multiple outputs"
	LANGUAGES CXX)

# Check if this CMakeLists.txt in project root directory
if (CMAKE_PROJECT_NAME STREQUAL PROJET_NAME)
	# Force -std=c++20 rather than -std=g++20
	set(CMAKE_CXX_EXTENSIONS OFF)
endif()

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(src)
add_subdirectory(app)
