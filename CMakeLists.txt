cmake_minimum_required(VERSION 3.10)
project(iz2 C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_C_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -Wall -Wextra -Werror --pedantic")

add_executable(iz2
        main.c
        header.h
        do_statistic.c
        test.c
        run_and_write.c structs.h work_test.c)