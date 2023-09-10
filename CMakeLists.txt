cmake_minimum_required(VERSION 3.26)
project(Basic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Basic main.cpp
        p1_p83/02_variable.cpp
        p1_p83/03_const.cpp
        p1_p83/01_keywords.cpp
        p1_p83/04_data_structure.cpp
        p1_p83/05_input.cpp
        p1_p83/06_operators.cpp
        p1_p83/07_process_control.cpp
        p1_p83/08_array.cpp
        p1_p83/09_function.cpp
        p1_p83/10_function_with_file.cpp
        p1_p83/11_pointer.cpp
        p1_p83/12_struct.cpp
        p1_p83/temp.cpp
        p1_p83/13_address_manager.cpp
        p84/01_memory_mode.cpp
        p84/02_function_enhance.cpp
        p84/03_object.cpp
        p84/temp.cpp
        p84/04_object_2.cpp
        p84/05_this_pointer.cpp
        p84/06_friend.cpp
        p84/07_operators_reload.cpp
        p84/08_extends.cpp
)
