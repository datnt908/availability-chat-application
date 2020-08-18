cmake_minimum_required(VERSION 3.9.0)
project(ACA-Server VERSION 0.1.0)

include(CTest)
enable_testing()

set(MYLIBRARY_DIR ../../libraries/MyLibrary)
set(cpprestsdk_DIR /usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}/cmake/)

find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

add_executable(ACA-Server main.cpp
    RestServer/RestServerController.h
    RestServer/RestServerController.cpp
    RestServer/Controllers/BaseController.h
    RestServer/Controllers/BaseController.cpp
)

target_include_directories(ACA-Server PUBLIC
    ${MYLIBRARY_DIR}
    RestServer
    RestServer/Controllers
)

target_link_libraries(ACA-Server PRIVATE
    MyLibrary
    cpprestsdk::cpprest
    Boost::system
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
