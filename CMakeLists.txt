cmake_minimum_required(VERSION 3.22)
project(ft_malloc C)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Wextra -Werror -g)
add_library(ft_malloc SHARED src/ft_malloc.c
        inc/ft_malloc.h)

include_directories(./inc)
#compile executable with ft_malloc library
link_libraries(ft_malloc)
add_executable(test test/test.c)
