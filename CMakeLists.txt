cmake_minimum_required(VERSION 4.1)
project(LangtonsAnt)

find_package(glfw3 REQUIRED)

add_executable(LangtonsAnt src/window.c)

target_link_libraries(LangtonsAnt PRIVATE glfw3)
