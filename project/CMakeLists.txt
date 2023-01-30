cmake_minimum_required(VERSION 3.16)
project(project C)

set(CMAKE_C_COMPILER "xcc")
set(CMAKE_CXX_COMPILER "xcc")

add_compile_options(-target=XCORE-200-EXPLORER)

set(CMAKE_C_FLAGS_DEBUG   "-g -report -O0")
set(CMAKE_C_FLAGS_RELEASE "-g -report -O3")

include_directories(./)
include_directories(./lib/)

file(GLOB src_map     ./src/mapfile.xc)
file(GLOB src_main    ./src/main.c)
file(GLOB src_libs    )

message(STATUS ${src_libs})

set_source_files_properties(${src_map} PROPERTIES LANGUAGE C)

add_executable(main  ${src_map} ${src_libs} ${src_main})
