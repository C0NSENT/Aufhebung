cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 23)

project(fstream)
add_executable(${PROJECT_NAME} fstream.cpp)

project(stream_states)
add_executable(${PROJECT_NAME} stream_states.cpp)