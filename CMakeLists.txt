cmake_minimum_required(VERSION 3.24)
project(Ex5ab)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ex5ab Test.cpp sources/MagicalContainer.cpp sources/MagicalContainer.hpp Test.cpp Demo.cpp myDemo.cpp)

