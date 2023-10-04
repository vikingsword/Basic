#pragma once
#include "iostream"
#include "Identity.h"

using namespace std;

/**
 * 管理员类定义
 */
class Manager : public Identity {
public:
    Manager();

    Manager(string name, string pwd);


    virtual void operateMenu();

    void addPerson();

    void showPerson();

    void showComputer();

    void clearFile();

};