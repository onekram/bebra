cmake_minimum_required(VERSION 3.26)
project(labwork3_onekram)

set(CMAKE_CXX_STANDARD 14)

add_executable(labwork3_onekram
        main.cpp
        parser.h
        parser.cpp
        file_io.cpp
        file_io.h
        data.tsv
        PointNet.h
        PointNet.cpp
        bmp_make.cpp
)
