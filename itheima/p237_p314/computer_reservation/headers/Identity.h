#pragma once
#include "iostream"

using namespace std;

/**
 * 学生类、教师类、管理员类的抽象基类
 */
class Identity {
public:
    virtual void operateMenu() = 0;

    string m_name;
    string m_pwd;

};

