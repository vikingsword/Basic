#pragma once
#include "iostream"
#include "Identity.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/**
 * 教师类定义
 */
class Teacher : public Identity {
public:
    Teacher();

    Teacher(int empId, string name, string pwd);

    // 菜单页面
    virtual void operateMenu();

    // 查看所有预约
    void showAllOrder();

    // 审核预约
    void validOrder();

    // 教师编号
    int m_empid;

};