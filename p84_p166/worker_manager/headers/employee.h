#pragma once
#include "iostream"
#include "worker.h"

using namespace std;

class Employee : public Worker{
public:
    // 构造函数
    Employee(int id, string name, int depId);

    // 显示个人信息
    void showInfo();

    // 获取岗位名称
    string getDepName();


};