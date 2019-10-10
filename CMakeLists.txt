cmake_minimum_required(VERSION 3.15)
project(project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(project
        main.c
        proj.h
        calc.c
        structs.h
        calc.h
        tests.h
        tests.c)

target_link_libraries(project m)

enable_testing()

add_test(NAME MainTest
        COMMAND project)

set_tests_properties(MainTest PROPERTIES
        PASS_REGULAR_EXPRESSION "OK")
