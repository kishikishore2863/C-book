cmake_minimum_required(VERSION 3.21)
project(firstC C)

set(CMAKE_C_STANDARD 11)

include_directories(include)


add_executable(firstC
    library.c
        src/recursion/factorial.c
        src/logicalOperation.c
        src/questions/q1.c
        src/questions/q2.c
        src/questions/q3.c
        src/questions/q4.c
        src/questions/q5.c
        src/questions/q6.c
        src/questions/q7.c
        src/chapter-2/t1.c
        src/chapter-2/t2.c
        src/chapter-2/t3.c
        src/chapter-2/t4.c
        src/chapter-2/t5.c
        src/chapter-2/t6.c
        src/chapter-2/t7.c
        src/chapter-2/t8.c
        src/chapter-2/t9.c
        src/chapter-2/t10.c
        src/chapter-2/t11.c
        src/chapter-2/t12.c
        src/chapter-2/t13.c
        src/chapter-2/t14.c
        src/chapter-2/t15.c
        src/chapter-2/t16.c
        src/chapter-2/t17.c
        src/chapter-2/t18.c
        src/chapter-2/t19.c
        src/chapter-2/t20.c
        src/chapter-2/t21.c
        src/chapter-2/t22.c
        src/chapter-2/t23.c
        src/chapter-2/t24.c
)

target_link_libraries(firstC m)
