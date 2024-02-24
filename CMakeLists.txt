cmake_minimum_required(VERSION 3.27)
project(CPrograms C)

set(CMAKE_C_STANDARD 11)

add_executable(CPrograms dereferencingExample.c
        LeetCodeRotatedSortedArrayBinarySearch.c
        dynamicNodeCreationTest.c
        test.c
        DFS.c
        LeetCodeAddTwoNumbers.c)
