#include "iostream"
#include "headers/manager.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/12 21:43
* @description:  经理类
*/

Manager::Manager(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string Manager::getDeptName() {
    return string("经理");
}