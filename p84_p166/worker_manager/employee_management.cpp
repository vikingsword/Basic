#include "iostream"
#include "headers/workManagement.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/12 17:18
* @description:  职工管理系统
*/
int main() {

    while(true){
        WorkerManager wm;
        wm.showMenu();

        int choice = 0;
        cout << "请输入您的选择( 0 - 7): ";
        cin >> choice;
        switch (choice) {
            case 0:
                wm.exit_system();
                break;
//            case 1:
//                wm.add_staff();
//                break;
//            case 2:
//                show_staff();
//                break;
//            case 3:
//                delete_staff();
//                break;
//            case 4:
//                modify_staff();
//                break;
//            case 5:
//                find_staff();
//                break;
//            case 6:
//                clear_staff();
//                break;
            default:
                cout << "您输入的数字不正确，请重新输入: " << endl;
                break;

        }
    }



    return 0;
}