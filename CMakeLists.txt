cmake_minimum_required(VERSION 3.7)
project(push_swap)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES src/*.c)
add_executable(push_swap ${SOURCE_FILES})

file(GLOB SOURCES_LIB externals/get_next_line/libft/*.c)
add_library(ft STATIC ${SOURCES_LIB})       # Создание статической библиотеки с именем libft

target_link_libraries(push_swap ft)	        # Линковка программы с библиотекой