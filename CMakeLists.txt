cmake_minimum_required(VERSION 3.0)
project(checksum_benchmark C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-O2")

add_executable(checksum_benchmark main.c
        page_new.c
        page_new.h
        page.c
        page.h)
