cmake_minimum_required(VERSION 3.0.0)

project(JiPPLab5)

include_directories(./include ./src)

add_executable(output ./src/main.cpp ./src/hrms.cpp ./src/employee.cpp)

