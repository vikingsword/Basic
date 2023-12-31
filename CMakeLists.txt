cmake_minimum_required(VERSION 3.26)
project(Basic)

set(CMAKE_CXX_STANDARD 17)

add_executable(Basic main.cpp
        itheima/p1_p83/02_variable.cpp
        itheima/p1_p83/03_const.cpp
        itheima/p1_p83/01_keywords.cpp
        itheima/p1_p83/04_data_structure.cpp
        itheima/p1_p83/05_input.cpp
        itheima/p1_p83/06_operators.cpp
        itheima/p1_p83/07_process_control.cpp
        itheima/p1_p83/08_array.cpp
        itheima/p1_p83/09_function.cpp
        itheima/p1_p83/10_function_with_file.cpp
        itheima/p1_p83/11_pointer.cpp
        itheima/p1_p83/12_struct.cpp
        itheima/temp/temp2.cpp
        itheima/p1_p83/13_address_manager.cpp
        itheima/p84_p166/01_memory_mode.cpp
        itheima/p84_p166/02_function_enhance.cpp
        itheima/p84_p166/03_object.cpp
        itheima/temp/temp3.cpp
        itheima/p84_p166/04_object_2.cpp
        itheima/p84_p166/05_this_pointer.cpp
        itheima/p84_p166/06_friend.cpp
        itheima/p84_p166/07_operators_reload.cpp
        itheima/p84_p166/08_extends.cpp
        itheima/p84_p166/09_polymorphic.cpp
        itheima/p84_p166/10_file.cpp
        itheima/p84_p166/worker_manager/employee_management.cpp
        itheima/p84_p166/worker_manager/headers/WorkerManager.h
        itheima/p84_p166/worker_manager/worker_manager.cpp
        itheima/p84_p166/worker_manager/headers/worker.h
        itheima/p84_p166/worker_manager/headers/employee.h
        itheima/p84_p166/worker_manager/employee.cpp
        itheima/p84_p166/worker_manager/headers/manager.h
        itheima/p84_p166/worker_manager/manager.cpp
        itheima/p84_p166/worker_manager/headers/boss.h
        itheima/p84_p166/worker_manager/boss.cpp
        itheima/p84_p166/worker_manager/test.cpp
        itheima/p167_p236/01_template_func.cpp
        itheima/p167_p236/test/temp.cpp
        itheima/p167_p236/02_template_class.cpp
        itheima/p167_p236/headers/person.h
        itheima/p167_p236/headers/person.hpp
        itheima/p167_p236/02_template_example.cpp
        itheima/p167_p236/headers/myArray.hpp
        itheima/p167_p236/03_stl.cpp
        itheima/p167_p236/04_string.cpp
        itheima/p167_p236/05_vector.cpp
        itheima/p167_p236/06_deque.cpp
        itheima/p167_p236/07_example.cpp
        itheima/p167_p236/08_stack_queue_list.cpp
        itheima/p167_p236/09_set_map.cpp
        itheima/p167_p236/test/temp2.cpp
        itheima/p167_p236/test/temp.cpp
        itheima/p237_p314/01_function_object.cpp
        itheima/temp/temp1.cpp
        itheima/temp/temp3.cpp
        itheima/temp/temp4.cpp
        itheima/temp/temp5.cpp
        cherno/p1_p25/demo1.cpp
        cherno/p1_p25/log.cpp
        itheima/temp/temp6.cpp
        itheima/p237_p314/02_algorithm.cpp
        itheima/temp/temp7.cpp
        itheima/p237_p314/speech_system/speechManager.cpp
        itheima/p237_p314/speech_system/Speaker.cpp
        tools/math/demo1.cpp
        tools/math/test.cpp
        tools/math/0.618.cpp
        itheima/p237_p314/speech_system/speechManagerMain.cpp
        itheima/temp/temp8.cpp
        tools/trick/01_lambda.cpp
        itheima/p237_p314/computer_reservation/ComputerOrder.cpp
        itheima/p237_p314/computer_reservation/headers/Student.h
        itheima/p237_p314/computer_reservation/Student.cpp
        itheima/p237_p314/computer_reservation/headers/Teacher.h
        itheima/p237_p314/computer_reservation/Teacher.cpp
        itheima/p237_p314/computer_reservation/headers/Manager.h
        itheima/p237_p314/computer_reservation/Manager.cpp
        itheima/p237_p314/computer_reservation/headers/globalFile.h
)
