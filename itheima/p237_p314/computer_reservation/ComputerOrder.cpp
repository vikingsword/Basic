#include "iostream"
#include "headers/globalFile.h"
#include "headers/Identity.h"
#include "headers/Manager.h"
#include "headers/Student.h"
#include "headers/Teacher.h"
#include "fstream"

using namespace std;

/**
* @author: vikingar
* @time: 2023/10/4 14:49
* @description:  机房预约系统
*/

void printMenu() {
    cout << "======================  欢迎来到传智播客机房预约系统  ====================="
         << endl;
    cout << endl << "请输入您的身份" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1.学生代表             |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2.老    师            |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3.管 理 员            |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0.退    出            |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
    cout << "输入您的选择: ";
}

void login(string filename, int type) {
    Identity * person = NULL;

    ifstream ifs;

    ifs.open(filename, ios::in);

    // file not exist
    if (!ifs.is_open()) {
        cout << "file not exist" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;
    if (type == 1) {
        cout << "input your student id: ";
        cin >> id;
    } else if (type == 2) {
        cout << "input your teacher id: ";
        cin >> id;
    }
    cout << "input username: ";
    cin >> name;
    cout << "input password: ";
    cin >> pwd;

    if (type == 1) {
        // student login
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (id == fId && name == fName && pwd == fPwd) {
                cout << "学生验证成功！ " << endl;
                system("cls");
                person = new Student(id, name, pwd);
                return;
            }
        }
    } else if (type == 2) {
        // teacher login
    } else if (type == 3) {
        // admin login
    }

    cout << "验证登陆失败! " << endl;
    system("cls");

}


int main() {

    int select;

    while(true) {

        printMenu();

        cin >> select;

        switch (select) {
            case 1:
                // 学生代表
                login(STUDENT_FILE, 1);
                break;
            case 2:
                // 老师
                login(TEACHER_FILE, 2);
                break;
            case 3:
                // 管理员
                login(ADMIN_FILE, 3);
                break;
            case 0:
                // 退出
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                cout << "输入有误，请重新输入!" << endl;
                system("cls");
                break;
        }
    }

    return 0;
}