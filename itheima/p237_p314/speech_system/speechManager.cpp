#include "iostream"
#include "headers/speechManager.h"
#include "algorithm"
#include "numeric"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/27 10:14
* @description:  演讲管理系统
*/

SpeechManage::SpeechManage() {
    // 初始化属性
    this->initSpeech();
    // 创建选手
    this->createSpeaker();
}

SpeechManage::~SpeechManage() {

}

void SpeechManage::showMenu() {
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManage::exitSystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManage::initSpeech() {
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m_speakers.clear();
    this->m_index = 1;
}

void SpeechManage::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_name = name;

        for (int j = 0; j < 2; ++j) {
            sp.m_score[j] = 0;
        }

        int id = i + 10001;
        v1.push_back(id);

        m_speakers.insert(make_pair(id, sp));
    }
}

void SpeechManage::speechDraw() {
    cout << "第 << " << this->m_index << " >> 轮比赛选手正在抽签";
    cout << "------------" << endl;
    cout << "抽签后顺序如下： " << endl;
    if (this->m_index == 1) {
        random_shuffle(this->v1.begin(), this->v1.end());
    }
}

void SpeechManage::startSpeech() {
    //第一轮比赛
    //1、抽签


    //2、比赛

    //3、显示晋级结果

    //第二轮比赛

    //1、抽签

    //2、比赛

    //3、显示最终结果

    //4、保存分数
}

void test() {
    SpeechManage sm;

    for (map<int, Speaker>::iterator it = sm.m_speakers.begin(); it != sm.m_speakers.end(); it++) {
        cout << "选手编号：" << it->first
             << " 姓名： " << it->second.m_name
             << " 成绩： " << it->second.m_score[0] << endl;
    }

}

int main() {

    SpeechManage sm;

    test();

    int choice = 0;

    while (true) {
        sm.showMenu();

        cout << "请输入您的选择： " << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                // 开始比赛
                break;
            case 2:
                // 查看记录
                break;
            case 3:
                // 清空比赛记录
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

    return 0;
}