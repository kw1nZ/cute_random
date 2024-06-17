# example/CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(cute_random_examples LANGUAGES CXX)

if(NOT TARGET cute_random)
    # Stand-alone build
    find_package(cute_random REQUIRED)
endif()

# Example of using the header-only library
add_executable(example main.cpp)
target_link_libraries(example PRIVATE cute_random)
