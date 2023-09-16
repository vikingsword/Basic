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
        p84_p166/01_memory_mode.cpp
        p84_p166/02_function_enhance.cpp
        p84_p166/03_object.cpp
        p84_p166/temp.cpp
        p84_p166/04_object_2.cpp
        p84_p166/05_this_pointer.cpp
        p84_p166/06_friend.cpp
        p84_p166/07_operators_reload.cpp
        p84_p166/08_extends.cpp
        p84_p166/09_polymorphic.cpp
        p84_p166/10_file.cpp
        p84_p166/worker_manager/employee_management.cpp
        p84_p166/worker_manager/headers/WorkerManager.h
        p84_p166/worker_manager/worker_manager.cpp
        p84_p166/worker_manager/headers/worker.h
        p84_p166/worker_manager/headers/employee.h
        p84_p166/worker_manager/employee.cpp
        p84_p166/worker_manager/headers/manager.h
        p84_p166/worker_manager/manager.cpp
        p84_p166/worker_manager/headers/boss.h
        p84_p166/worker_manager/boss.cpp
        p84_p166/worker_manager/test.cpp
        p167/01_template_func.cpp
        p167/temp.cpp
        p167/02_template_class.cpp
        p167/headers/person.h
        p167/headers/person.hpp
        p167/02_template_example.cpp
        p167/headers/myArray.hpp
        p167/03_stl.cpp
        p167/04_string.cpp
        p167/05_vector.cpp
        p167/06_deque.cpp
        p167/07_example.cpp
        p167/08_stack_queue_list.cpp
)
