cmake_minimum_required(VERSION 3.9.0)
project(MyLibrary VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(MyLibrary 
    MyLibrary.h
    MyLibrary.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
