cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 23)

project(fstream)

add_executable(${PROJECT_NAME} fstream.cpp)

project(stream_states)
add_executable(${PROJECT_NAME} stream_states.cpp)

project(ignore_function)
add_executable(${PROJECT_NAME} ignore_function.cpp)

project(number_system)
add_executable(${PROJECT_NAME} number_system.cpp)

project(cases_difference)
add_executable(${PROJECT_NAME} cases_difference.cpp)

project(format)
add_executable(${PROJECT_NAME} format.cpp)

project(sstream)
add_executable(${PROJECT_NAME} sstream.cpp)

project(utf-8_rofls)
add_executable(${PROJECT_NAME} utf-8_rofls.cpp)