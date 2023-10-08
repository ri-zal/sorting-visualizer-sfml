cmake_minimum_required(VERSION 3.25)
project(Sorting_Visualizer___SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting_Visualizer___SFML main.cpp Visualizer.cpp Visualizer.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/SFML/include/SFML)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)