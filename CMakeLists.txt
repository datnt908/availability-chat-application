cmake_minimum_required(VERSION 3.9.0)
project(ACA VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(libraries/MyLibrary)
add_subdirectory(source/Client)
add_subdirectory(source/Server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
