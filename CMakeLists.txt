# Current reference:
# https://github.com/eliasdaler/imgui-sfml-fetchcontent/blob/master/dependencies/CMakeLists.txt
# Rewrite using subdirectories with these guides:
# https://edw.is/using-cmake/
# https://github.com/eliasdaler/cmake-fetchcontent-tutorial-code

cmake_minimum_required(VERSION 3.31.4)
project(
  sfml-tests 
  LANGUAGES CXX
  VERSION 0.1.0)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif(CCACHE_FOUND)

add_subdirectory(src)
add_subdirectory(dependencies)