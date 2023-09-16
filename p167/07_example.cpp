//#include "iostream"
//#include "vector"
//#include "deque"
//#include "algorithm"
//#include "ctime"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/16 20:31
//* @description:  有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//*/
//
//class Person {
//public:
//    string m_name;
//    int m_score;
//
//    Person(string name, int score) {
//        this->m_name = name;
//        this->m_score = score;
//    }
//};
//
//void createPerson(vector<Person> &v) {
//    string nameSeed = "ABCDE";
//    for (int i = 0; i < 5; ++i) {
//        string name = "选手";
//        name += nameSeed[i];
////        cout << "name" << i + 1 << " = " << name << endl;
//
//        int score = 0;
//        Person p(name, score);
//        v.push_back(p);
//    }
//}
//
//// 打分
//void setScore(vector<Person> &v) {
//    for (vector<Person>::iterator it=v.begin(); it != v.end(); it++) {
//        // 将评委的分数放到 deque 容器中
//        deque<int> d;
//        for (int i = 0; i < 10; ++i) {
//            int score = rand() % 41 + 60;
//            d.push_back(score);
//        }
//        // 排序
//        sort(d.begin(), d.end());
//
//        // 去除最高分、最低分
//        d.pop_front();
//        d.pop_back();
//
//        // 取平均分
//        int sum = 0;
//        for (deque<int>::iterator de=d.begin();de!=d.end();de++) {
//            sum += *de;
//        }
//        int avg = sum / d.size();
//        it->m_score = avg;
//
//    }
//
//}
//
//void showScore(vector<Person> &v) {
//    for (vector<Person>::iterator it=v.begin(); it != v.end(); it++) {
//        cout << "姓名： " << it->m_name << "\t平均分： " << it->m_score << endl;
//    }
//}
//
//int main() {
//
//    // 随机数种子
//    srand((unsigned int)time(NULL));
//
//    // 1. 创建 5 名选手
//    vector<Person> v;
//    createPerson(v);
//
//    // 2. 给 5 名选手打分
//    setScore(v);
//
//    // 3. 显示最后得分
//    showScore(v);
//
//    return 0;
//}