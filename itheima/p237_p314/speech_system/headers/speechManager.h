#pragma once
#include "iostream"
#include "vector"
#include "map"
#include "../Speaker.cpp"

using namespace std;



class SpeechManage {
public:
    // 构造函数
    SpeechManage();

    // 析构函数
    ~SpeechManage();

    // 展示菜单
    void showMenu();

    // 退出程序
    void exitSystem();

    // 添加成员属性
    // 比赛选手编号 12人
    vector<int> v1;
    // 第一轮晋级 6人
    vector<int> v2;
    // 胜利 3人
    vector<int> v3;
    // 存放编号 以及对应的 具体选手 容器
    map<int, Speaker> m_speakers;
    // 比赛轮数
    int m_index;

    // 初始化属性
    void initSpeech();

    // 创建选手
    void createSpeaker();

    // 开始比赛 - 比赛流量控制
    void startSpeech();

    // 抽签
    void speechDraw();

    // 比赛
    void speechContest();

    // 显示比赛结果
    void showScore();

    // 保存分数
    void saveRecord();


    // 保存记录
    void loadRecord();

    // 文件为空的标志
    bool fileIsEmpty;

    // 往届记录
    map<int, vector<string>> m_Record;

    void showRecord();


    // 清空记录
    void clearRecord();


};
