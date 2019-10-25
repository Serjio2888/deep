cmake_minimum_required(VERSION 3.10)
project(iz2 C)

set(CMAKE_C_STANDARD 99)

add_executable(iz2
        main.c
        header.h
        do_statistic.c
        test_10000.c run_and_write.c structs.h)