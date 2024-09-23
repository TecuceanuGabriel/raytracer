cmake_minimum_required(VERSION 3.30)

project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False )

file(GLOB RAY_SOURCES src/*.cpp)
file(GLOB RAY_HEADERS src/*.hpp)

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID}) 
message (STATUS "Release flags: " ${CMAKE_CXX_FLAGS_RELEASE}) 
message (STATUS "Debug flags: " ${CMAKE_CXX_FLAGS_DEBUG})

add_compile_options(-Werror -Wall -Wextra -Wpedantic)
add_executable(${PROJECT_NAME} ${RAY_SOURCES} ${RAY_HEADERS})
