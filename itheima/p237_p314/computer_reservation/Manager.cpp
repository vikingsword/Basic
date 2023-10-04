#include "iostream"
#include "headers/Manager.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/10/4 15:52
* @description:  管理员类的具体实现
*/

Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
    this->m_name = name;
    this->m_pwd = pwd;
}

void Manager::operateMenu() {
    cout << "欢迎管理员： " << this->m_name << " 登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

void Manager::addPerson() {

}

void Manager::showPerson() {

}

void Manager::showComputer() {

}

void Manager::clearFile() {

}