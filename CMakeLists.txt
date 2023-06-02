cmake_minimum_required(VERSION 3.23)
project(file_comp__)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "*.cpp")


add_executable(file_comp__ main.cpp read_from_file.cpp compression.cpp)
