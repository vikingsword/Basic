#include "headers/WorkerManager.h"
#include "headers/employee.h"
#include "headers/manager.h"
#include "headers/boss.h"


WorkerManager::WorkerManager() {
    // 记录文件中的人数的个数
    this->m_EmpNum = 0;
    // 初始化指针数据
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
    }
}

void WorkerManager::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exit_system() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}


void WorkerManager::add_staff() {
    cout << "请输入增加职工的数量" << endl;

    int add_Num = 0;
    cin >> add_Num;
    if (add_Num > 0) {

        // 计算新空间大小
        int newSize = this->m_EmpNum + add_Num;

        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];

        // 将原空间下内容存放到新空间下
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        // 输入新数据
        for (int i = 0; i < add_Num; i++) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
            cin >> id;


            cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;


            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1: //普通员工
                    worker = new Employee(id, name, 1);
                    break;
                case 2: //经理
                    worker = new Manager(id, name, 2);
                    break;
                case 3:  //老板
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }


            newSpace[this->m_EmpNum + i] = worker;

            //释放原有空间
            delete[] this->m_EmpArray;

            //更改新空间的指向
            this->m_EmpArray = newSpace;

            //更新新的个数
            this->m_EmpNum = newSize;

            //提示信息
            cout << "成功添加" << add_Num << "名新职工！" << endl;

            this->save();

        }

    } else {
        cout << "输入有误" << endl;
    }

    system("pause");
    system("cls");
}






















