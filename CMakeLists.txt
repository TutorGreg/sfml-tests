# Current reference:
# https://github.com/eliasdaler/imgui-sfml-fetchcontent/blob/master/dependencies/CMakeLists.txt
# Rewrite using subdirectories with these guides:
# https://edw.is/using-cmake/
# https://github.com/eliasdaler/cmake-fetchcontent-tutorial-code

cmake_minimum_required(VERSION 3.31.4)
project(sfml-tests LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

### SFML

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)

### IMGUI

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.7
)
FetchContent_MakeAvailable(imgui)

### IMGUI-SFML

FetchContent_Declare(
  IMGUI-SFML
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
  GIT_TAG v3.0
)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)

add_executable(main src/main.cpp src/Button.cpp) 
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
