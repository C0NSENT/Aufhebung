cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)

project(date)
add_executable(date date.cpp date.h
        month.cpp)
