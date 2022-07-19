# Based off of 'https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/CMakeLists.txt'
cmake_minimum_required(VERSION 3.14..3.8)

# Force C++20 on project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(
	VectorMath 
	VERSION 1.0 
	DESCRIPTION "Vector support functions for vector math"
	LANGUAGES CXX)

# Check for main project name (here it should always trigger)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# Ensuring '-std=c++xx' rather than '-std=g++xx'
	set(CMAKE_CXX_EXTENSIONS OFF)

	# Create 'Docs' folder if Doxygen is found
	find_package(Doxygen)
	if(Doxygen_FOUND)
		add_subdirectory(docs)
	else()
		message(STATUS "Doxygen not found, not building docs")
	endif()
endif()

include_directories(${PROJECT_SOURCE_DIR})


enable_testing()
add_subdirectory(tests)

add_subdirectory(src)
add_subdirectory(app)
