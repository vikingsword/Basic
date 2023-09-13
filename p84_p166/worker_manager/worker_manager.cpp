#include "headers/WorkerManager.h"
#include "headers/employee.h"
#include "headers/manager.h"
#include "headers/boss.h"


WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 文件不存在
    if (!ifs.is_open()) {
//        cout << "file not exist" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        // 初始化文件为空标志
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在并且无记录
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
//        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在并有记录
    int num  = this->get_EmpNum();
    cout << "职工个数为： " << num << endl;
    this->m_EmpNum = num;
    // 根据职工数创建数组
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    // 设置文件存在标记
    this->m_FileIsEmpty = false;
    // 初始化职工
    init_Emp();

//    // 测试代码
//    for (int i = 0; i < m_EmpNum; i++) {
//        cout << "职工号： " << this->m_EmpArray[i]->m_Id
//            << "\t职工姓名：" << this->m_EmpArray[i]->m_Name
//            << "\t部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
//    }


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

            // 判断当前输入的职工编号是否存在
            if (this->IsExist(id)) {
                cout << "当前职工已经存在，请重新输入： " << endl;
                continue;
            }


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

            // 更新职工不为空的标志
            this->m_FileIsEmpty = false;

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

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        // 记录人数
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::init_Emp() {
    ifstream ifs;

    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker * worker = NULL;
        if (dId == 1){
            worker = new Employee(id, name, dId);
        } else if (dId == 2) {
            worker = new Manager(id, name, dId);
        } else {
            worker = new Boss(id, name, dId);
        }
        // 存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
}

// 显示职工
void WorkerManager::show_staff() {
    if (this->m_FileIsEmpty){
        cout << "文件不存在或者记录为空！ " << endl;
    } else {
        for (int i = 0; i < m_EmpNum; i++) {
            // 利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

// 判断职工是否存在
int WorkerManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

// 删除职工
void WorkerManager::delete_staff() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或者记录为空！ " << endl;
    } else {
        // 按职工编号删除
        cout << "请输入想删除的职工编号： " << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1) {
            // 删除
            for (int i = index; i < this->m_EmpNum; ++i) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            this->save();
            cout << "删除成功！ " << endl;
        } else {
            cout << "删除失败， 未找到改职工" << endl;
        }
    }

    system("pause");
    system("cls");

}

void WorkerManager::modify_staff() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
    } else {
        cout << "请输入修改职工的编号： " << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1) {
            // 找到该职工，可以修改(先删除在添加)
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到" << id << "号职工，请输入新职工号： " << endl;
            cin >> newId;

            cout << "请输入姓名" << endl;
            cin >> newName;

            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId, newName, dSelect);
                    break;
                case 2:
                    worker = new Manager(newId, newName, dSelect);
                    break;
                case 3:
                    worker = new Boss(newId, newName, dSelect);
                    break;
                default:
                    break;
            }

            // 更改数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功" << endl;

            this->save();
        } else {
            cout << "修改失败，查无此人" << endl;
        }
    }

    system("pause");
    system("cls");

}













