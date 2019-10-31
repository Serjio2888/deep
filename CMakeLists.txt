cmake_minimum_required(VERSION 3.10)
project(iz2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_C_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -Wall -Wextra -Werror --pedantic")

find_package(GTest REQUIRED)
set(GMock_INCLUDE_DIR "/usr/local/include")
set(GMock_LIBRARY "/usr/local/lib/libgmock.a")
set(GMock_BOTH_LIBRARIES ${GMock_LIBRARY} ${GMock_LIBRARY_MAIN})

# Add GoogleTest include directory
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMock_INCLUDE_DIR})

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(iz2
        main.c
        header.h
        structs.h
        do_statistic.c
        run_and_write.c )

add_executable(iz2_tests
        header.h
        structs.h
        do_statistic.c
        run_and_write.c
        tests/test.cpp
        tests/stress_test.c)

# Link GoogleTest
target_link_libraries(iz2_tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(iz2_tests pthread)

message("Gtests version ${GTEST_FOUND} found at ${GTEST_INCLUDE_DIRS} (might be set to notfound but that's ok)")
