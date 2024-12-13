cmake_minimum_required(VERSION 3.10)
project(A)

file(GLOB files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*)

foreach(file ${files})
    get_filename_component(FILENAME "${file}" NAME)
    message(${FILENAME})
    add_executable(${FILENAME}-tar ${file})
endforeach()