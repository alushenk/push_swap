cmake_minimum_required(VERSION 3.7)
project(push_swap)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap
        src/algorithm.c
        src/cases.c
        src/display.c
        src/errors.c
        src/main.c
        src/parsing.c
        src/simple_sorting.c
        src/stack_operations.c
        src/three_two_sortings.c
        src/wrappers.c
        )

file(GLOB SOURCES_LIB externals/get_next_line/libft/*.c)
add_library(ft STATIC ${SOURCES_LIB})       # Создание статической библиотеки с именем libft

target_link_libraries(push_swap ft)	        # Линковка программы с библиотекой


project(checker)
set(CMAKE_C_STANDARD 99)

add_executable(checker
        src/checker.c
        externals/get_next_line/get_next_line.c
        src/wrappers.c
        src/stack_operations.c
        src/errors.c src/parsing.c
        src/simple_sorting.c
        src/display.c
        )

target_link_libraries(checker ft)	        # Линковка программы с библиотекой