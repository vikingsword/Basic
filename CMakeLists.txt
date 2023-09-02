cmake_minimum_required(VERSION 3.26)
project(Basic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Basic main.cpp
        demo1/02_variable.cpp
        demo1/03_const.cpp
        demo1/01_keywords.cpp
        demo1/04_data_structure.cpp
        demo1/05_input.cpp
        demo1/06_operators.cpp
        demo1/07_process_control.cpp
        demo1/08_array.cpp
        demo1/09_function.cpp
        demo1/10_finction_with_file.cpp
        demo1/11_pointer.cpp
)
