cmake_minimum_required(VERSION 3.15)
project(fmt_test)

find_package(fmt REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} fmt::fmt)