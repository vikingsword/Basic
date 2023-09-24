#include "headers/employee.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/12 21:16
* @description:  职工类
*/
Employee::Employee(int id, std::string name, int depId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = depId;
}

void Employee::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
    return string("员工");
}