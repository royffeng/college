cmake_minimum_required(VERSION 3.16)
project(maxheap)

set(CMAKE_CXX_STANDARD 14)

add_executable(maxheap main.cpp Heap.cpp Heap.h PrintJob.cpp PrintJob.h)
