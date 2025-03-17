cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)

project(exercise_02)
add_executable(exercise_02 exercise_02.cpp)

project(exercise_03)
add_executable(exercise_03 exercise_03.cpp)
target_compile_options(exercise_03 PRIVATE "-finput-charset=UTF-8" "-fexec-charset=UTF-8")


project(exercise_05)
add_executable(exercise_05 library_v1/src/book_v1.cpp library_v1/src/date.cpp
        library_v1/headers/date.h library_v1/headers/book_v1.h)

add_executable(test test.cpp)

project (exercise_08)
add_executable(exercise_08 exercise_08/patron_v1.cpp exercise_08/patron_v1.h)



