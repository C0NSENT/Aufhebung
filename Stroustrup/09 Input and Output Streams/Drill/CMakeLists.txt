cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 23)

project(drill9_1)
add_executable(drill9_1 test_output.cpp)

project (Drill9_9)
add_executable(${PROJECT_NAME} drill9_9.cpp)

project(Drill9_10 VERSION 1.0)
add_executable(${PROJECT_NAME} drill9_10.cpp)

project(Drill9_10_2)
add_executable(${PROJECT_NAME} Drill9_10_2/table_output.h Drill9_10_2/table_output.cpp)