//#include "iostream"
//#include "vector"
//#include "list"
//#include "map"
//#include "set"
//#include "deque"
//#include "algorithm"
//#include "ctime"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/24 15:51
//* @description: stl : standard template library
//*/
//
//void temp01() {
//    vector v{1, 2, 3};
//    for_each(v.begin(), v.end(), [&v](int num) {
//        cout << num << " ";
//    });
//    cout << endl;
//
//    vector<int> v2{1, 2, 3};
//    for_each(v.begin(), v.end(), [&v](int num) {
//        cout << num << " ";
//    });
//    cout << endl;
//}
//
//class Animal {
//public:
//    virtual void yell() = 0;
//};
//
//class Dog : public Animal {
//public:
//    virtual void yell();
//};
//
//void Dog::yell() {
//    cout << "www" << endl;
//}
//
//void temp02() {
//    Dog dog;
//    dog.yell();
//}
//
//
//void temp03() {
//    cout << "aaaaaaa\tbbb" << endl;
//    cout << "aaaa\tbb" << endl;
//}
//
//class Person {
//    void printPerson(Person *p) {
//        cout << "hello person" << endl;
//    }
//};
//
//void temp04() {
//    Person *per = NULL;
//    cout << per << endl;
//    int a = 10;
//    int *p = &a;
//    int *q = &a;
//    cout << *q << endl;
//
//
//}
//
//void printPerson(Person *p) {
//    cout << "hello person" << endl;
//}
//
//void printPerson3(Person &p) {
//    cout << "add person" << endl;
//}
//
//void temp05() {
//    Person *p = new Person;
//    printPerson(p);
//
//    Person q;
//    // *p = &q;
//    printPerson(&q);
//
//    printPerson3(q);
//}
//
//
//void log(const char *message) {
//    cout << message << endl;
//}
//
//void temp06() {
//    log("hello world");
//    cin.get();
//}
//
//class Person2 {
//public:
//    string m_name;
//    int m_age;
//
//    Person2(string name, int age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//};
//
//void temp07() {
//    vector<int> v{1, 2, 3};
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl << "--------------" << endl;
//
//    for_each(v.begin(), v.end(), [](int num) { cout << num << " "; });
//    cout << "-----------" << endl;
//
//    vector<Person2 *> v2;
//    //创建数据
//    Person2 p1("aaa", 10);
//    Person2 p2("bbb", 20);
//    Person2 p3("ccc", 30);
//    Person2 p4("ddd", 40);
//    Person2 p5("eee", 50);
//    v2.push_back(&p1);
//    v2.push_back(&p2);
//    v2.push_back(&p3);
//    v2.push_back(&p4);
//    v2.push_back(&p5);
//
//    for_each(v2.begin(), v2.end(), [](Person2 *p) {
//        cout << "name = " << (*p).m_name << "; age =  " << (*p).m_age << endl;
//    });
//
//    cout << "---------------" << endl;
//
//}
//
//void temp08() {
//    vector<vector<int>> v;
//    vector<int> v1;
//    vector<int> v2;
//    vector<int> v3;
//    vector<int> v4;
//    for (int i = 0; i < 4; ++i) {
//        v1.push_back(i + 1);
//        v2.push_back(i + 2);
//        v3.push_back(i + 3);
//        v4.push_back(i + 4);
//    }
//
//    v = {v1, v2, v3, v4};
//    for_each(v.begin(), v.end(), [](vector<int> ve) {
//        for_each(ve.begin(), ve.end(), [](int num) {
//            cout << num << " ";
//        });
//        cout << endl;
//    });
//}
//
//void temp09() {
//    string s1;
//    cout << s1 << endl;
//
//    string s2 = "abc";
//    cout << "s2 = " << s2 << endl;
//
//    const char *str = "hello";
//    string s3(str);
//    cout << "s3 = " << s3 << endl;
//
//    string s4(10, 'a');
//    cout << "s4 = " << s4 << endl;
//}
//
//void temp10() {
//    string s1 = "hello";
//    for (int i = 0; i < s1.size(); ++i) {
//        if (i == 1) {
//            cout << s1[i] << endl;
//        }
//    }
//    s1.insert(5, "world");
//    cout << "s1 = " << s1 << endl;
//
//    string email = "vikingar@gmail.com";
//    int pos = email.find('@');
//    string str = email.substr(0, pos);
//    cout << "str = " << str << endl;
//    string str2 = email.substr(pos + 1, email.find('.') - pos - 1);
//    cout << "str2 = " << str2 << endl;
//    string str3 = email.substr(email.find('.') + 1, 3);
//    cout << "str3 = " << str3 << endl;
//
//}
//
//
//void temp11() {
//    vector<int> v{1, 4, 3, 5, 8, 2, 6};
//    std::sort(v.begin(), v.end());
//    std::for_each(v.begin(), v.end(), [](int num) {
//        cout << num << " ";
//    });
//    cout << endl << "------------" << endl;
//}
//
//
///**
// * 评委打分
// */
//class Player {
//public:
//    string m_name;
//    // 平均分
//    int m_score;
//
//    Player(string name, int score) {
//        this->m_name = name;
//        this->m_score = score;
//    }
//};
//
//int getAverageScore() {
//    deque<int> d;
//    for (int i = 0; i < 10; ++i) {
//        int score = rand() % 41 + 60;
//        d.push_back(score);
//    }
//    // remove max and min
//    d.pop_front();
//    d.pop_back();
//
//    int sum = 0;
//    for_each(d.begin(), d.end(), [&sum](int num) {
//        sum += num;
//    });
//    int average_num = sum / 8;
//
//    return average_num;
//}
//
//void createPlayer(vector<Player> &v) {
//    string name_num = "ABCDE";
//    for (int i = 0; i < name_num.size(); ++i) {
//        string name = "选手";
//        name += name_num[i];
//        cout << name << " ";
//        int score = getAverageScore();
//        Player p = {name, score};
//        v.push_back(p);
//    }
//    cout << endl;
//}
//
//void printInfo(vector<Player> &v) {
//    for_each(v.begin(), v.end(), [](Player p) {
//        cout << "name: " << p.m_name << "; score: " << p.m_score << endl;
//    });
//    cout << endl;
//}
//
//void temp12() {
//    srand((unsigned int) time(NULL));
//    // create players vector
//    vector<Player> v;
//    createPlayer(v);
//
//    printInfo(v);
//
//}
//
//class Animal2 {
//public:
//    string m_name;
//    int m_age;
//
//    Animal2(string name, int age) : m_name(name), m_age(age) {}
//};
//
//void temp13() {
//    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
//
//    sort(v.begin(), v.end(), [](int num1, int num2) {
//        return num1 > num2;
//    });
//    sort(v.begin(), v.end(), [](int a, int b) {
//        return false;
//    });
//
//    for (auto elem: v) {
//        cout << elem << " ";
//    }
//    cout << endl;
//}
//
//
//void temp14() {
//    list<int> l = {1, 23, 4, 5, 45, 6, 2, 12};
//    for (auto elem: l) {
//        cout << elem << " ";
//    }
//    cout << endl;
//    cout << l.size() << endl;
//
//    cout << l.empty() << endl;
//    cout << (l.empty() == 0 ? "not empty" : "empty") << endl;
////    sort(l.begin(), l.end(), [](int a, int b){
////        return a < b;
////    });
//
//    l.insert(l.end(), 1);
//    for (auto elem: l) {
//        cout << elem << " ";
//    }
//    cout << endl << "--------------" << endl;
//
//    cout << "after sort:" << endl;
//    l.sort([](int a, int b) { return a < b; });
//    for (auto elem: l) { cout << elem << " "; }
//
//    cout << endl << "-----------------" << endl;
//    l.reverse();
//    for (auto elem: l) { cout << elem << " "; }
//
//}
//
///**
// * 排序案例
// * 将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// * 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
// */
//class Person3 {
//public:
//    string m_name;
//    int m_age;
//    int m_height;
//
//    Person3(string name, int age, int height) : m_name(name), m_age(age), m_height(height) {}
//};
//
//void temp15() {
//    list<Person3> l;
//
//    Person3 p1("刘备", 35, 175);
//    Person3 p2("曹操", 45, 180);
//    Person3 p3("孙权", 40, 170);
//    Person3 p4("赵云", 25, 190);
//    Person3 p5("张飞", 35, 160);
//    Person3 p6("关羽", 35, 200);
//
//    l = {p1, p2, p3, p4, p5, p6};
//
//    l.sort([](Person3 p1, Person3 p2) {
//        if (p1.m_age == p2.m_age) {
//            return p1.m_height > p2.m_height;
//        }
//        return p1.m_age < p2.m_age;
//    });
//
//    for (auto elem: l) {
//        cout << "name = " << elem.m_name << "; age = " << elem.m_age
//             << "; height = " << elem.m_height << endl;
//    }
//
//}
//
//void temp16() {
//    set<int> s = {3, 23, 2, 5, 6, 7, 8, 12, 23};
//    for (auto elem: s) {
//        cout << elem << " ";
//    }
//    cout << endl;
//
//    set<int>::iterator it = s.find(3);
//    cout << *it << endl;
//
//    cout << s.count(3);
//
//    cout << "\n----------------" << endl;
//
//    std::set<int> mySet = {5, 2, 9, 3, 6, 1, 8, 4, 7};
//    auto customSort = [](int a, int b) {
//        return a < b;
//    };
//    vector<int> sortedVector(mySet.begin(), mySet.end());
//    sort(sortedVector.begin(), sortedVector.end(), customSort);
//
//    for (auto num: sortedVector) { cout << num << " "; }
//
//    cout << endl;
//
//
//}
//
//void printMap(map<int, int> &map) {
//    for_each(map.begin(), map.end(), [](pair<int, int> p) {
//        cout << "key = " << p.first << "; value = " << p.second << endl;
//    });
//}
//
//void temp17() {
//    pair<int, int> p1(1, 2);
//    pair<int, int> p2 = make_pair(3, 4);
//    cout << "p1.first = " << p1.first << "; p1.second = " << p1.second << endl;
//
//    cout << "-------------" << endl;
//
//    map<int, int> map = {pair<int, int>(1, 2), pair<int, int>(3, 4), pair<int, int>(5, 6)};
//    printMap(map);
//
//}
//
//void temp18() {
//    map<int, int> m1;
//    m1.insert(make_pair(1, 2));
//    printMap(m1);
//
//    map<int, int> m2;
//    m2.insert(pair<int, int>(3, 4));
//    printMap(m2);
//
//    cout << "after swap: " << endl;
//    m1.swap(m2);
//    printMap(m1);
//    printMap(m2);
//
//    m1.erase(m1.begin(), m1.end());
//    printMap(m1);
//
//}
//
//void temp19() {
//    map<int, int>m;
//    m.insert(pair<int, int>(1, 10));
//    m.insert(pair<int, int>(2, 20));
//    m.insert(pair<int, int>(3, 30));
//    m.insert(make_pair(4, 40));
//    m.insert(make_pair(5, 50));
//
//    map<int,int>::iterator pos = m.find(3);
//    if (pos != m.end()) {
//        cout << "find element! " << endl;
//    } else {
//        cout << "not found" << endl;
//    }
//
//    int num = m.count(3);
//    cout << "num = " << num << endl;
//
//    cout << "-------------" << endl;
//
//
//}
//
//
//class MyCompare {
//public:
//    bool operator() (int a, int b) const{
//        return a > b;
//    }
//};
//void temp20() {
//    map<int, int, MyCompare> m;
//    m.insert(make_pair(1, 10));
//    m.insert(make_pair(2, 20));
//    m.insert(make_pair(3, 30));
//    m.insert(make_pair(4, 40));
//    m.insert(make_pair(5, 50));
//
//    for (auto p : m) {
//        cout << "key = " << p.first << "; value = " << p.second << endl;
//    }
//}
//
//
//
//int main() {
//
//
////    temp01();
////    temp02();
////    temp03();
////    temp04();
////    temp05();
////    temp06();
////    temp07();
////    temp08();
////    temp09();
////    temp10();
////    temp11();
////    temp12();
////    temp13();
////    temp14();
////    temp15();
////    temp16();
////    temp17();
////    temp18();
////    temp19();
//    temp20();
//
//
//    return 0;
//}