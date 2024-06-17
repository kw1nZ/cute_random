cmake_minimum_required(VERSION 3.23)
project(cute_random)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

option(${PROJECT_NAME}_BUILD_EXAMPLES "Build examples" ON)

if(${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()