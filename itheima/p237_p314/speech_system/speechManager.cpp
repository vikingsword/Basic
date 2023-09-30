#include "iostream"
#include "headers/speechManager.h"
#include "algorithm"
#include "vector"
#include "deque"
#include "map"
#include "numeric"
#include "fstream"
#include "ctime"

#define FILEPATH "./itheima/p237_p314/speech_system/speech.csv"

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
    // 获取往届记录
    this->loadRecord();
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

    // 初始化记录容器
    this->m_Record.clear();
}

/**
 * 开始比赛
 */
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
        for (auto elem: v1) {
            cout << elem << " ";
        }
        cout << endl;
    } else {
        random_shuffle(v2.begin(), v2.end());
        for (auto elem: v2) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;

}

void SpeechManage::speechContest() {
    cout << "-------------第" << this->m_index << "轮正式比赛开始： ----------" << endl;
    // 临时容器，保存key分数 value 选手编号
    multimap<double, int, greater<int>> groupScore;
    int num = 0;

    vector<int> v_Src;
    if (this->m_index == 1) {
        v_Src = v1;
    } else {
        v_Src = v2;
    }

    // 遍历所有参赛选手
    for (auto elem: v_Src) {
        num++;
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; ++i) {
            double score = (rand() % 401 + 600) / 10.f;
//            cout << score << " ";
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double) d.size();

        //每个人平均分
        //cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
        this->m_speakers[elem].m_score[this->m_index - 1] = avg;

        // 6 个人一组， 用临时容器保存
        groupScore.insert(make_pair(avg, elem));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
                cout << "编号: " << it->second << " 姓名： " << this->m_speakers[it->second].m_name << " 成绩： "
                     << this->m_speakers[it->second].m_score[this->m_index - 1] << endl;
            }
            int count = 0;
            // 取前三名
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (this->m_index == 1) {
                    v2.push_back((*it).second);
                } else {
                    v3.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "------------- 第" << this->m_index << "轮比赛完毕  ------------- " << endl;
}

void SpeechManage::showScore() {
    cout << "---------第" << this->m_index << "轮晋级选手信息如下：-----------" << endl;
    vector<int> v;
    if (this->m_index == 1) {
        v = v2;
    } else {
        v = v3;
    }
    for (auto elem: v) {
        cout << "选手编号： " << elem << "姓名： " << m_speakers[elem].m_name
             << "得分： " << m_speakers[elem].m_score[this->m_index - 1] << endl;
    }
    cout << endl;

    system("cls");
}

void SpeechManage::saveRecord() {
    ofstream ofs;
    ofs.open(FILEPATH, ios::out | ios::app);

    for (auto elem: v3) {
        ofs << elem << "," << m_speakers[elem].m_score[1] << ",";
    }
    ofs << endl;

    ofs.close();

    cout << "记录已经保存" << endl;

    // 有记录了， 文件不为空
    this->fileIsEmpty = false;
}


/**
 * 查看记录
 */
void SpeechManage::loadRecord() {
    ifstream ifs(FILEPATH, ios::in);
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空！ " << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;

    ifs.putback(ch);

    string data;
    int index = 0;
    while (ifs >> data) {
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }
            string temp = data.substr(start, pos - start);
            v.push_back(temp);
            start = pos + 1;
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}

void SpeechManage::showRecord() {
    if (this->fileIsEmpty) {
        cout << "文件不存在， 或记录为空！" << endl;
    } else {
        for (int i = 0; i < this->m_Record.size(); i++) {
            cout << "第" << i + 1 << "届 " <<
                 "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
                                                                                            "亚军编号："
                 << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
                                                                                "季军编号：" << this->m_Record[i][4]
                 << " 得分：" << this->m_Record[i][5] << endl;
        }
    }

    system("cls");
}


/**
 * 清空记录
 */
void SpeechManage::clearRecord() {
    cout << "确认清空？ " << endl;
    cout << "1. 确认" << endl;
    cout << "2. 返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
        ofstream ofs(FILEPATH, ios::trunc);
        ofs.close();

        // 初始化属性
        this->initSpeech();

        // 创建选手
        this->createSpeaker();

        // 获取往届记录
        this->loadRecord();

        cout << "clear successfully " << endl;
    }

    system("cls");
}





void SpeechManage::startSpeech() {
    //第一轮比赛
    //1、抽签
    speechDraw();

    //2、比赛
    speechContest();

    //3、显示晋级结果
    showScore();


    //第二轮比赛
    this->m_index++;
    //1、抽签
    speechDraw();

    //2、比赛
    speechContest();

    //3、显示最终结果
    showScore();

    //4、保存分数
    saveRecord();
    // 重置比赛，初始化属性
    this->initSpeech();
    // 创建选手
    this->createSpeaker();
    // 获取往届记录
    this->loadRecord();

    cout << "本届比赛完毕！" << endl;
    system("cls");
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