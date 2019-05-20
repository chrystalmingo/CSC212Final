cmake_minimum_required (VERSION 3.0)

project (CSC_212_Final_Project)

set(HEADER_FILES hash.h)
add_library(hash hash.cpp ${HEADER_FILES}) 
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(main hash)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)