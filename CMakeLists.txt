cmake_minimum_required(VERSION 3.22)
project(ft_malloc C)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Wextra -Werror -g)

#ifeq ($(HOSTTYPE),)
#    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
#endif

if(NOT DEFINED ENV{HOSTTYPE})
    find_program(UNAME uname)
    # Execute uname -m and uname -s, store the output in variables
    execute_process(COMMAND ${UNAME} -m OUTPUT_VARIABLE UNAME_MACHINE OUTPUT_STRIP_TRAILING_WHITESPACE)
    execute_process(COMMAND ${UNAME} -s OUTPUT_VARIABLE UNAME_SYSTEM OUTPUT_STRIP_TRAILING_WHITESPACE)

    # Set the HOSTTYPE environment variable
    set(ENV{HOSTTYPE} "${UNAME_MACHINE}_${UNAME_SYSTEM}")
endif()

set(LIBRARY_NAME "ft_malloc_$ENV{HOSTTYPE}")

add_library(ft_malloc SHARED src/ft_malloc.c
        inc/ft_malloc.h)
set_target_properties(ft_malloc PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})

include_directories(./inc)
#compile executable with ft_malloc library
link_libraries(ft_malloc)
add_executable(test test/test.c)
