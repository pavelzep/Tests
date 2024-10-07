cmake_minimum_required(VERSION 3.0.0)
project (FMT_Example)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${CMAKE_MODULE_PATH}")

set(PROJECT_NAME "fmt_example")

add_executable(${PROJECT_NAME} main.cpp)

find_package(fmt REQUIRED)
if(fmt_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${fmt_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${fmt_LIBRARIES})
endif()