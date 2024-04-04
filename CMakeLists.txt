cmake_minimum_required(VERSION 3.23)
project(ThrowQuick)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)

include_directories(include/)

add_executable(ThrowQuick main.cpp src/RenderWindow.cpp include/Player.h src/Player.cpp)
target_link_libraries(ThrowQuick PRIVATE SDL2::SDL2)
