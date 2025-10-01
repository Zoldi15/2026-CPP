cmake_minimum_required(VERSION 3.29)

project(lab3)

include_directories(Headers)

add_executable(lab3 main_03.cpp
        Headers/Point.h
        Headers/PointSet.h
        Sources/PointSet.cpp
        Sources/Point.cpp)