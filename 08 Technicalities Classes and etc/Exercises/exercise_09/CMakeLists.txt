cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(library
        VERSION 1.0)

file(GLOB SRC_FILES "src/*.cpp")
file(GLOB HEADER_FILES "headers/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

