cmake_minimum_required(VERSION 3.10)
project(project C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)


add_executable(project
        main.c
        proj.h
        calc.c
        structs.h
        calc.h
        tests.h
        tests.c)

target_link_libraries(project m)




