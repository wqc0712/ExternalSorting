cmake_minimum_required(VERSION 3.3)
project(ExternalSorting)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Buffer.cpp FileManager.cpp)
add_executable(Sorting ${SOURCE_FILES})
