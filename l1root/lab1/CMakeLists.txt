cmake_minimum_required(VERSION 3.15)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(lab1 main.cpp src/prime.h src/prime.cpp src/divisibility.h src/divisibility.cpp src/sequences.h src/sequences.cpp src/probe.cpp test/sequences_test.cpp test/prime_test.cpp)

include_directories(src)
add_subdirectory(src)


include_directories(test)
add_subdirectory(test)

