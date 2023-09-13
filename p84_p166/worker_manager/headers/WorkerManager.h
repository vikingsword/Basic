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

    // 显示职工信息

    // 删除离职职工

    // 修改职工信息

    // 查找职工信息

    // 按照编号排序

    // 清空所有文档






    // 析构函数
    ~WorkerManager();


    // 记录文件中的人数个数
    int m_EmpNum;

    // 员工数组的指针
    Worker ** m_EmpArray;



};