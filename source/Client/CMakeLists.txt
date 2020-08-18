cmake_minimum_required(VERSION 3.9.0)
project(ACA-Client VERSION 0.1.0)

include(CTest)
enable_testing()

set(MYLIBRARY_DIR ../../libraries/MyLibrary)

add_executable(ACA-Client main.cpp)

target_include_directories(ACA-Client PUBLIC
    ${MYLIBRARY_DIR}
)

target_link_libraries(ACA-Client MyLibrary)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
