cmake_minimum_required(VERSION 3.30)
project(OJ_practice)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "*.cpp")

add_executable(OJ_practice ${SOURCES})
