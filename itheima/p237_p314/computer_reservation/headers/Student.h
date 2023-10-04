#pragma once
#include "iostream"
#include "Identity.h"

using namespace std;

/**
 * 学生类定义
 */
class Student : public Identity {
public:
    Student();

    Student(int id, string name, string pwd);

    // 菜单页面
    virtual void operateMenu();

    void applyOrder();

    void showOrder();

    void showAllOrder();

    void cancelOrder();

    int m_id;
};