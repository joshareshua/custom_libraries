cmake_minimum_required(VERSION 3.10)
project(CustomLibraries)

set(CMAKE_CXX_STANDARD 17)
add_library(my_lib
    src/MyVector.cpp
)

target_include_directories(my_lib PUBLIC include)

add_executable(test_runner
    tests/simple_test.cpp
)