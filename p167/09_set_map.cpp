#include "iostream"
#include "set"
#include "map"
#include "vector"
#include "ctime"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/17 12:42
* @description:  集合和 map
*/

/**
 * 所有元素都会在插入时自动被排序
 * set/multiset属于关联式容器，底层结构是用二叉树实现。
 * set和multiset区别：
 *  set不允许容器中有重复的元素
 *  multiset允许容器中有重复的元素
 */
void printSet(set<int> &s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * 构造方法：
 * set<T> st;                        //默认构造函数：
 * set(const set &st);              //拷贝构造函数
 * 赋值：
 * set& operator=(const set &st);    //重载等号操作符
 */
void test01() {
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    printSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值构造
    set<int> s3 = s1;
    printSet(s3);


}

/**
 * 统计set容器大小以及交换set容器
 * size();          //返回容器中元素的数目
 * empty();        //判断容器是否为空
 * swap(st);       //交换两个集合容器
 */
void test02() {
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    printSet(s1);

    if (s1.empty()) {
        cout << "s1 为空" << endl;
    } else {
        cout << "s1 不为空" << endl;
        cout << "s1 的大小为： " << s1.size() << endl;
    }

    // 交换
    set<int> s2;
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    s2.insert(4);

    cout << "交换前： " << endl;
    printSet(s1);
    printSet(s2);
    cout << "交换后： " << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);

}


/**
 * set容器进行插入数据和删除数据
 * insert(elem);             //在容器中插入元素。
 * clear();                 //清除所有元素
 * erase(pos);              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
 * erase(beg, end);         //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
 * erase(elem);            //删除容器中值为elem的元素。
 */
void test03() {
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    printSet(s1);

    // 删除
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(3);
    printSet(s1);

//    // 清空
//    s1.erase(s1.begin(), s1.end());
//    cout << "s1 = ";
//    printSet(s1);

    // 清空
    s1.clear();
    cout << "s1 = ";
    printSet(s1);

}


/**
 * 对set容器进行查找数据以及统计数据
 * find(key);                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
 * count(key);                //统计key的元素个数
 */
void test04() {
    set<int> s1;
    // set 不能插入重复元素
    s1.insert(1);
    s1.insert(2);
    s1.insert(2);
    s1.insert(3);
    s1.insert(3);

    set<int>::iterator pos = s1.find(3);
    if (pos != s1.end()) {
        cout << "找到了元素： " << *pos << endl;
    } else {
        cout << "为找到元素：" << endl;
    }

    int num = s1.count(2);
    cout << "num = " << num << endl;

}


/**
 * 掌握set和multiset的区别
 * * set不可以插入重复数据，而multiset可以
 * set插入数据的同时会返回插入结果，表示插入是否成功
 * multiset不会检测数据，因此可以插入重复数据
 */
void test05() {
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second) {
        cout << "first insert successful" << endl;
    } else {
        cout << "first insert failed" << endl;
    }

    ret = s.insert(10);
    if (ret.second) {
        cout << "second insert successful" << endl;
    } else {
        cout << "second insert failed" << endl;
    }

    // multiset
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


/**
 * pair 对组创建
 * 成对出现的数据，利用对组可以返回两个数据
 * pair<type, type> p ( value1, value2 );
 * pair<type, type> p = make_pair( value1, value2 );
 */
void test06() {
    pair<string, int> p(string("Tom"), 20);
    cout << "姓名： " << p.first << "; 年龄： " << p.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 10);
    cout << "姓名： " << p.first << "; 年龄： " << p.second << endl;

}


/**
 * set 容器排序
 * set容器默认排序规则为从小到大  利用仿函数，可以改变排序规则
 */
class MyCompare {
public:
    // 重载()  这里要加 const
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};

void test07() {
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);
    printSet(s1);

    // 指定排序规则
    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);
    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// set 存放自定义数据类型
class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;

};

class comparePerson {
public:
    bool operator()(const Person &p1, const Person &p2) const {
        return p1.m_age > p2.m_age;
    }
};

void test07_2() {

    set<Person, comparePerson> s;
    Person p1("刘备", 23);
    Person p2("关羽", 27);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    // 要指定排序规则，因为插入 Person 对象，set容器不知道如何进行排序
    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
        cout << "姓名： " << it->m_name << " 年龄： " << it->m_age << endl;
    }

}


/**
 * map
 * map/multimap属于关联式容器，底层结构是用二叉树实现。
 * 可以根据key值快速找到value值
 * map和multimap区别：
 *   map不允许容器中有重复key值元素
 *   multimap允许容器中有重复key值元素
 */

/**
 * map 构造和赋值
 * 构造：
 * map<T1, T2> mp;                     //map默认构造函数:
 * map(const map &mp);             //拷贝构造函数
 * 赋值：
 * map& operator=(const map &mp);    //重载等号操作符
 */
void printMap(map<int, int> &m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << "; value = " << it->second << endl;
    }
    cout << endl;
}

void test08() {

    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    cout << "m1  : " << endl;
    printMap(m);

    map<int, int> m2(m);
    cout << "m2 : " << endl;
    printMap(m2);

    map<int, int> m3 = m;
    cout << "m3 = " << endl;
    printMap(m3);

}


/**
 * 统计map容器大小以及交换map容器
 * size();          //返回容器中元素的数目
 * empty();        //判断容器是否为空
 * swap(st);      //交换两个集合容器
 */
void test09() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    printMap(m);

    if (m.empty()) {
        cout << "map 为空！ " << endl;
    } else {
        cout << "map 的大小为： " << m.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 40));
    m2.insert(pair<int, int>(5, 50));
    m2.insert(pair<int, int>(6, 60));

    // 交换
    cout << "交换前： " << endl;
    printMap(m);
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    printMap(m);
    printMap(m2);

}


/**
 * map 的交换和删除
 * map容器进行插入数据和删除数据
 * insert(elem);            //在容器中插入元素。
 * clear();                 //清除所有元素
 * erase(pos);              //删除pos迭代器所指的元素，返回下一个元素的迭代器。
 * erase(beg, end);         //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
 * erase(key);              //删除容器中值为key的元素。
 */
void test10() {
    map<int, int> m;
    // 第一种插入方式
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    // 第二种插入方式
    m.insert(make_pair(4, 40));
    // 第三种
    m.insert(map<int, int>::value_type(5, 50));
    // 第四种
    m[6] = 60;
    cout << "init map: " << endl;
    printMap(m);


    map<int, int>::iterator it = m.begin();
    m.erase(it);
    printMap(m);

    m.erase(3);
    printMap(m);

    m.clear();
    printMap(m);

}


/**
 * 对map容器进行查找数据以及统计数据
 * find(key);                  //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
 * count(key);                //统计key的元素个数
 */
void test11() {
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    // 查找
    map<int, int>::iterator pos = m.find(3);
    if (pos != m.end()) {
        cout << "find the element: " << (*pos).first
             << "; value: " << (*pos).second << endl;
    } else {
        cout << "为找到元素" << endl;
    }

    // key 不重复
    int num = m.count(3);
    cout << "num = " << num << endl;
}


/**
 * map 容器排序
 * map容器默认排序规则为 按照key值进行 从小到大排序  利用仿函数，可以改变排序规则
 * * 利用仿函数可以指定map容器的排序规则
 * 对于自定义数据类型，map必须要指定排序规则,同set容器
 */
class MyCompare2 {
public:
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};

void test12() {

    // 默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare2> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }

}


/**
 * 案例： 员工分组
 * * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
 * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
 * 随机给10名员工分配部门和工资
 * 通过multimap进行信息的插入  key(部门编号) value(员工)
 * 分部门显示员工信息
 *
 * 步骤：
 * 1. 创建10名员工，放到vector中
 * 2. 遍历vector容器，取出每个员工，进行随机分组
 * 3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
 * 4. 分部门显示员工信息
 */

#define CEHUA 0
#define MEISHU 1
#define YANFA 3

// todo 如果类名是 Worker 会在第二次循环的时候退出程序
class Worker {
public:
    string m_name;
    int m_salary;
};

void createWorker(vector<Worker> &v) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        Worker worker;
        worker.m_name = "员工";
        worker.m_name += nameSeed[i];

        // salary between 10000 - 19999
        worker.m_salary = rand() % 10000 + 10000;
        v.push_back(worker);

    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        int deptId = rand() % 3;
        //将员工插入到分组中
        //key部门编号，value具体员工
//        m.insert(pair<int, Worker>(deptId, *it));
        m.insert(make_pair(deptId,(*it)));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部门： " << endl;

    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "name: " << pos->second.m_name
             << "; salary: " << pos->second.m_salary << endl;
    }

    cout << "------------------------" << endl;
    cout << "美术部门" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
    }

    cout << "----------------------" << endl;
    cout << "研发部门： " << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++) {
        cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
    }

}

void example() {

    srand((unsigned int) time(NULL));

    // 1. 创建员工
    vector<Worker> v;
    createWorker(v);

    // 2. 员工分组
    multimap<int, Worker> m;
    setGroup(v, m);

    // 3. 分组显示员工
    showWorkerByGroup(m);

    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名： " << it->m_name << " 工资： " << it->m_salary << endl;
    }

}


int main() {

//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test07_2();

//    test08();
//    test09();
//    test10();
//    test11();
//    test12();

    example();

    return 0;
}