#include "iostream"
#include "headers/speechManager.h"
#include "ctime"

using namespace std;

/**
* @author: vikingar
* @time: 2023/10/2 20:34
* @description:
*/
int main() {

    srand((unsigned int)time(NULL));

    SpeechManage sm;

//    test();

    int choice = 0;

    while (true) {
        sm.showMenu();

        cout << "请输入您的选择： " << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                // 开始比赛
                sm.startSpeech();
                break;
            case 2:
                // 查看记录
                sm.showRecord();
                break;
            case 3:
                // 清空比赛记录
                sm.clearRecord();
                break;
            case 0:
                // 退出比赛程序
                sm.exitSystem();
                break;
            default:
                system("cls");
                break;
        }
    }

}