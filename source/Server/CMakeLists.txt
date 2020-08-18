cmake_minimum_required(VERSION 3.0.0)
project(ACA-Server VERSION 0.1.0)

include(CTest)
enable_testing()

set(MYLIBRARY_DIR ../../libraries/MyLibrary)

add_executable(ACA-Server main.cpp)

target_include_directories(ACA-Server PUBLIC
    ${MYLIBRARY_DIR}
)

target_link_libraries(ACA-Server MyLibrary)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
