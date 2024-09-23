cmake_minimum_required(VERSION 3.30)

project(raytracer LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB RAY_SOURCES src/*.cpp)
file(GLOB RAY_HEADERS src/*.hpp)

add_compile_options( -Werror -Wall -Wextra)
add_executable(${PROJECT_NAME} ${RAY_SOURCES} ${RAY_HEADERS})
