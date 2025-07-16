cmake_minimum_required(VERSION 3.31)
project(firstC C)

set(CMAKE_C_STANDARD 11)

add_library(firstC STATIC library.c)
