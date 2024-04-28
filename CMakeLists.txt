cmake_minimum_required(VERSION 3.23)
project(ThrowQuick)

set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(include/ assets/)

add_executable(ThrowQuick main.cpp src/Player.cpp src/Game.cpp)
target_link_libraries(ThrowQuick PRIVATE SDL2::SDL2 ${SDL_IMAGE_LIBRARIES})
