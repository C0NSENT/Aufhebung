 cmake_minimum_required(VERSION 3.30)

 set(CMAKE_CXX_STANDARD 23)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)

 file(GLOB SRC_FILES "")

 project(example_10.3)
 add_executable(example_10.3 example_10.3.cpp)