cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp file/File_.h file/File_.cpp classes/Point.cpp classes/Point.h classes/GraphList.cpp classes/GraphList.h classes/MyThread.cpp classes/MyThread.h)