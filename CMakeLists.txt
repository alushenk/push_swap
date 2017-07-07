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
        src/three_two_sortings.c
        src/split_functions.c
        src/instructions.c
        src/simultaneous_sort/simultaneous_sort.c
        src/simultaneous_sort/merge_functions.c
        src/simultaneous_sort/rename_functions.c
        src/wrappers/wrappers.c
        src/wrappers/wrappers_a.c
        src/wrappers/wrappers_b.c
        src/stack_operations/stack_operations.c
        src/stack_operations/create_functions.c
        src/stack_operations/push_functions.c
        src/stack_operations/rotate_functions.c
        )

file(GLOB SOURCES_LIB externals/get_next_line/libft/*.c)
add_library(ft STATIC ${SOURCES_LIB})       # Создание статической библиотеки с именем libft

target_link_libraries(push_swap ft)	        # Линковка программы с библиотекой


project(checker)
set(CMAKE_C_STANDARD 99)

add_executable(checker
        src/checker.c
        externals/get_next_line/get_next_line.c
        src/stack_operations/stack_operations.c
        src/stack_operations/create_functions.c
        src/stack_operations/push_functions.c
        src/stack_operations/rotate_functions.c
        src/errors.c
        src/parsing.c
        src/simple_sorting.c
        src/display.c
        src/instructions.c
        src/wrappers/wrappers.c
        src/wrappers/wrappers_a.c
        src/wrappers/wrappers_b.c
        )

target_link_libraries(checker ft)	        # Линковка программы с библиотекой