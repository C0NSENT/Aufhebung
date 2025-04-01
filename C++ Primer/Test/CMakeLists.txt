cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test_1)
add_executable(${PROJECT_NAME} test_1.cpp)

project(aggregate_class)
add_executable(${PROJECT_NAME} aggregate_class.cpp)

project(static_class)
add_executable(${PROJECT_NAME} static_class.cpp)