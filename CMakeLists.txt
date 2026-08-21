cmake_minimum_required(VERSION 3.10)
project(CustomLibraries)

set(CMAKE_CXX_STANDARD 23)

add_library(my_lib
    src/myVector.cpp
)

target_include_directories(my_lib PUBLIC include)

add_executable(test_runner
    tests/vector_tests/simple_test.cpp
)

target_link_libraries(test_runner my_lib)