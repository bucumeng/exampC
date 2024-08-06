cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MyExecutable src/main.cpp src/cesb_database.cpp)
