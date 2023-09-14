#pragma once
#include "iostream"
#include "worker.h"
#include "fstream"
#define FILENAME "employeeFile.txt"

using namespace std;

class WorkerManager{
public:

    // 构造函数
    WorkerManager();

    // 展示菜单
    void showMenu();

    // 退出系统
    void exit_system();

    // 增加职工信息
    void add_staff();

    // 保存职工信息
    void save();
    bool m_FileIsEmpty;
    // 统计人数
    int get_EmpNum();
    // 初始化员工
    void init_Emp();

    // 显示职工信息
    void show_staff();

    // 删除离职职工
    void delete_staff();
    // 按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);

    // 修改职工信息
    void modify_staff();

    // 查找职工信息
    void find_staff();

    // 按照编号排序
    void sort_staff();

    // 清空所有文档
    void clear_staff();




    // 析构函数
    ~WorkerManager();


    // 记录文件中的人数个数
    int m_EmpNum;

    // 员工数组的指针
    Worker ** m_EmpArray;



};