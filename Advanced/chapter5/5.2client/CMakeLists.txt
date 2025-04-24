cmake_minimum_required(VERSION 3.19)
project(5_2client C)

set(CMAKE_C_STANDARD 99)
link_libraries(ws2_32)
add_executable(5_2client main.c)