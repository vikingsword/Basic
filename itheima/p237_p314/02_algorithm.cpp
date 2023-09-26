#include "iostream"
#include "headers/function.hpp"
#include "vector"
#include "algorithm"
#include "ctime"
#include "numeric"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/26 16:03
* @description: 常用算法 algorithm numeric functional
*/

/**
 * for_each
 */
void printVector2(int val) {
    cout << val << " ";
}

class MyPrint {
public:
    void operator()(int value) {
        cout << value << " ";
    }
};

void test01() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    for_each(v.begin(), v.end(), [](int num) { cout << num << " "; });
    cout << endl;
    for_each(v.begin(), v.end(), printVector2);
    cout << endl;
    for_each(v.begin(), v.end(), printValue);
    cout << endl;
    // 仿函数要放入函数对象
    for_each(v.begin(), v.end(), MyPrint());

}

/**
 * transform
 * 功能描述：
 * 搬运容器到另一个容器中
 * 函数原型：
 * transform(iterator beg1, iterator end1, iterator beg2, _func);
 * beg1 源容器开始迭代器
 * end1 源容器结束迭代器
 * beg2 目标容器开始迭代器
 * _func 函数或者函数对象
 */
class Transform {
public:
    int operator()(int value) {
        // transform 搬运可以指定
        return value + 100;
    }
};

void test02() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }


    vector<int> v_target;
    // 一定要指定容器大小
    v_target.resize(v.size());
    transform(v.begin(), v.end(), v_target.begin(), Transform());
    for_each(v_target.begin(), v_target.end(), MyPrint());
}

/**
 * - find                //查找元素
 - find_if               //按条件查找元素
 - adjacent_find        //查找相邻重复元素
 - binary_search        //二分查找法
 - count                //统计元素个数
 - count_if             //按条件统计元素个数
 */
class Person {
public:
    string m_name;
    int m_age;

    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }

    bool operator==(const Person &p) {
        if (this->m_name == p.m_name && this->m_age == p.m_age) {
            return true;
        } else {
            return false;
        }
    }
};

void test03() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto res = find(v.begin(), v.end(), 3);
    if (res != v.end()) {
        cout << "找到了： " << *res << endl;
    } else {
        cout << "not found" << endl;
    }

    cout << "-----------" << endl;
    vector<Person> p;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    p = {p1, p2, p3, p4};

    Person p5("ccc", 30);

    auto res2 = find(p.begin(), p.end(), p5);
    if (res2 != p.end()) {
        cout << "找到姓名:" << res2->m_name << " 年龄: " << res2->m_age << endl;
    } else {
        cout << "没有找到!" << endl;
    }

}


/**
 * find_if
 * * 按条件查找元素
 *函数原型：
 * find_if(iterator beg, iterator end, _Pred);
 * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 * beg 开始迭代器
 * end 结束迭代器
 * _Pred 函数或者谓词（返回bool类型的仿函数）
 */
// 基本数据类型
class GreaterFive {
public:
    bool operator()(int value) {
        return value > 5;
    }
};

void test04() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    auto res = find_if(v.begin(), v.end(), GreaterFive());
    if (res != v.end()) {
        cout << "找到大于5的数字:" << *res << endl;
    } else {
        cout << "没有找到!" << endl;
    }
}

// 自定义数据类型
class Person2 {
public:
    string m_name;
    int m_age;

    Person2(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
};

class Greater20 {
public:
    bool operator()(Person2 &p) {
        return p.m_age > 20;
    }
};

void test05() {
    vector<Person2> p;
    Person2 p1("aaa", 10);
    Person2 p2("bbb", 20);
    Person2 p3("ccc", 30);
    Person2 p4("ddd", 40);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);

    Person2 p5("ccc", 30);

    auto res = find_if(p.begin(), p.end(), Greater20());
    if (res == p.end()) {
        cout << "not found " << endl;
    } else {
        cout << "找到姓名:" << res->m_name << "; 年龄: " << res->m_age << endl;
    }

}


/**
 * ## adjacent_find
 *  功能描述：
 * 查找相邻重复元素
 * 函数原型：
 * adjacent_find(iterator beg, iterator end);
 * 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
 * beg 开始迭代器
 * end 结束迭代器
 */
void test06() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    auto res = adjacent_find(v.begin(), v.end());
    if (res == v.end()) {
        cout << "找不到";
    } else {
        cout << "找到重复元素为： " << *res << endl;
    }
}


/**
 * #### binary_search
 * 功能描述：
 * 查找指定元素是否存在
 * 函数原型：
 * bool binary_search(iterator beg, iterator end, value);
 * 查找指定的元素，查到 返回true  否则false
 * 注意: 在**无序序列中不可用**
 * beg 开始迭代器
 * end 结束迭代器
 * value 查找的元素
 */
void test07() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    // 二分查找, 必须是有序序列,无序序列无法找到
    auto res = binary_search(v.begin(), v.end(), 4);
    if (res) {
        cout << "found " << endl;
    } else {
        cout << "not found " << endl;
    }
}


/**
 * #### count
 **功能描述：**
 * 统计元素个数
 **函数原型：**
 * count(iterator beg, iterator end, value);
 * 统计元素出现次数
 * beg 开始迭代器
 * end 结束迭代器
 * value 统计的元素
 */
class Person3 {
public:
    string m_name;
    int m_age;

    Person3(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }

    bool operator==(const Person3 &p) {
        if (this->m_age == p.m_age) {
            return true;
        } else {
            return false;
        }
    }
};

void test08() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);
    cout << "4的个数为： " << num << endl;
    cout << "---------------" << endl;

    vector<Person3> v2;

    Person3 p1("刘备", 35);
    Person3 p2("关羽", 35);
    Person3 p3("张飞", 35);
    Person3 p4("赵云", 30);
    Person3 p5("曹操", 25);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    v2.push_back(p5);

    Person3 p("诸葛亮", 35);

    int num2 = count(v2.begin(), v2.end(), p);
    cout << "num = " << num2 << endl;

}


/**
 * #### count_if
 **功能描述：**
 * 按条件统计元素个数
 **函数原型：**
 * count_if(iterator beg, iterator end, _Pred);
 * 按条件统计元素出现次数
 * beg 开始迭代器
 * end 结束迭代器
 * _Pred 谓词
 */
class Greater4 {
public:
    bool operator()(int val) {
        return val >= 4;
    }
};

void test09() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count_if(v.begin(), v.end(), Greater4());
    cout << "大于 4 的个数为： " << num << endl;

}

// 自定义数据类型
class Person4 {
public:
    string m_name;
    int m_age;

    Person4(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
};

class AgeLess35 {
public:
    bool operator()(const Person4 &p) {
        return p.m_age < 35;
    }
};

void test10() {
    vector<Person4> v;

    Person4 p1("刘备", 35);
    Person4 p2("关羽", 35);
    Person4 p3("张飞", 35);
    Person4 p4("赵云", 30);
    Person4 p5("曹操", 25);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), AgeLess35());
    cout << "num = " << num;
}


/**
 * ### 常用排序算法
 *学习目标：**
 * 掌握常用的排序算法
 * 算法简介：** *
 * sort             //对容器内元素进行排序
 * random_shuffle   //洗牌   指定范围内的元素随机调整次序
 * merge            // 容器元素合并，并存储到另一容器中
 * reverse       // 反转指定范围的元素
 */


/**
 * 对容器内元素进行排序
 * 函数原型：
 * sort(iterator beg, iterator end, _Pred);
 * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 *  beg    开始迭代器
 *  end    结束迭代器
 * _Pred  谓词
 */
void test11() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int num) { cout << num << " "; });
    cout << endl;

    // 从大到小
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int num) { cout << num << " "; });

}


/**
 * #### random_shuffle
 **功能描述：**
 * 洗牌   指定范围内的元素随机调整次序
 **函数原型：**
 * random_shuffle(iterator beg, iterator end);
 * 指定范围内的元素随机调整次序
 * beg 开始迭代器
 * end 结束迭代器
 */
void test12() {
    srand((unsigned int) time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int value) { cout << value << " "; });
    cout << endl;

    cout << "random shuffle" << endl;
    random_shuffle(v.begin(), v.end());
    for (auto i: v) { cout << i << " "; }
    cout << endl;
}


/**
 * #### merge
 **功能描述：**
 * 两个容器元素合并，并存储到另一容器中
 **函数原型：**
 * merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * 容器元素合并，并存储到另一容器中
 * 注意: 两个容器必须是**有序的**
 * beg1   容器1开始迭代器
 * end1   容器1结束迭代器
 * beg2   容器2开始迭代器
 * end2   容器2结束迭代器
 * dest    目标容器开始迭代器
 */
void test13() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 10);
    }

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    printVector(v3);
}


/**
 * #### reverse
 **功能描述：**
 * 将容器内元素进行反转
 **函数原型：**
 * reverse(iterator beg, iterator end);
 * 反转指定范围的元素
 * beg 开始迭代器
 * end 结束迭代器
 */
void test14() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "before reverse" << endl;
    printVector(v);

    cout << "after reverse" << endl;
    reverse(v.begin(), v.end());
    printVector(v);

}


/**
 * 常用拷贝和替换算法:
 * 学习目标：
 * 掌握常用的拷贝和替换算法
 * 算法简介：
 * copy                      // 容器内指定范围的元素拷贝到另一容器中
 * replace                  // 将容器内指定范围的旧元素修改为新元素
 * replace_if               // 容器内指定范围满足条件的元素替换为新元素
 * swap                     // 互换两个容器的元素
 */


/**
 * copy
 * 功能描述：
 * 容器内指定范围的元素拷贝到另一容器中
 * 函数原型：
 * copy(iterator beg, iterator end, iterator dest);
 * 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 * beg  开始迭代器
 * end  结束迭代器
 * dest 目标起始迭代器
 */
void test15() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    printVector(v2);
}


/**
 * #### replace
 **功能描述：**
 * 将容器内指定范围的旧元素修改为新元素
 **函数原型：**
 * replace(iterator beg, iterator end, oldvalue, newvalue);
 * 将区间内旧元素 替换成 新元素
 * beg 开始迭代器
 * end 结束迭代器
 * oldvalue 旧元素
 * newvalue 新元素
 */
void test16() {
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "before replace : " << endl;
    printVector(v);

    cout << "after replace : " << endl;
    replace(v.begin(),v.end(),20, 100);
    printVector(v);

}


/**
 * #### replace_if
 **功能描述:**
 * 将区间内满足条件的元素，替换成指定元素
 **函数原型：**
 * replace_if(iterator beg, iterator end, _pred, newvalue);
 * 按条件替换元素，满足条件的替换成指定元素
 * beg 开始迭代器
 * end 结束迭代器
 * _pred 谓词
 * newvalue 替换的新元素
 */
class ReplaceGreaterThan30 {
public:
    bool operator()(int value) {
        return value > 30;
    }
};
void test17() {
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "before replace : " << endl;
    printVector(v);

    cout << "after replace : " << endl;
    replace_if(v.begin(),v.end(),ReplaceGreaterThan30(), 100);
    printVector(v);

}


/**
 * #### swap
 **功能描述：**
 * 互换两个容器的元素
 **函数原型：**
 * swap(container c1, container c2);
 * 互换两个容器的元素
 * c1容器1
 * c2容器2
 */
void test18() {
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i + 1);
    }

    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(i + 11);
    }

    cout << "before swap: " << endl;
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    cout << "after swap: " << endl;
    swap(v1, v2);
    cout << "v1: " ;
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

}

/**
 * ### 常用算术生成算法
 * 学习目标：
 * 掌握常用的算术生成算法
 * 注意：
 * 算术生成算法属于小型算法，使用时包含的头文件为 #include <numeric>
 * 算法简介：
 * accumulate      // 计算容器元素累计总和
 * fill                 // 向容器中添加元素
 */


/**
 * #### accumulate
 * 功能描述：
 *  计算区间内 容器元素累计总和
 * 函数原型：
 * accumulate(iterator beg, iterator end, value);
 * 计算容器元素累计总和
 * beg 开始迭代器
 * end 结束迭代器
 * value 起始值
 */
void test19() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    int total = accumulate(v.begin(), v.end(), 0);
    cout << "total = " << total << endl;

}


/**
 * #### fill
 **功能描述：**
 * 向容器中填充指定的元素
 * 函数原型：
 * fill(iterator beg, iterator end, value);
 * 向容器中填充元素
 * beg 开始迭代器
 * end 结束迭代器
 * value 填充的值
 */
void test20() {
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end() , 1);
    printVector(v);
}


/**
 * ### 常用集合算法
 * 学习目标：
 * 掌握常用的集合算法
 * 算法简介：
 * set_intersection          // 求两个容器的交集
 * set_union                       // 求两个容器的并集
 * set_difference               // 求两个容器的差集
 */

/**
 * #### set_intersection
 **功能描述：**
 * 求两个容器的交集
 **函数原型：**
 * set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * 求两个集合的交集
 * **注意:两个集合必须是有序序列**
 * beg1 容器1开始迭代器
 * end1 容器1结束迭代器
 * beg2 容器2开始迭代器
 * end2 容器2结束迭代器
 * dest 目标容器开始迭代器
 *
 * set_intersection返回值既是交集中最后一个元素的位置
 */
void test21() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    vector<int> v3;
    //取两个里面较小的值给目标容器开辟空间
    v3.resize(min(v1.size(),v2.size()));
    //返回目标容器的最后一个元素的迭代器地址
    auto it = set_intersection(v1.begin(),v1.end(),v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), it, [](int value){cout << value << " ";});

}


/**
 * #### set_union
 * 功能描述：
 * 求两个集合的并集
 * 函数原型：
 * set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * 求两个集合的并集
 * **注意:两个集合必须是有序序列**
 * beg1 容器1开始迭代器
 * end1 容器1结束迭代器
 * beg2 容器2开始迭代器
 * end2 容器2结束迭代器
 * dest 目标容器开始迭代器
 */
void test22() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    vector<int> v3;
    v3.resize(v1.size() + v2.size());
    vector<int>::iterator  it_end = set_union(v1.begin(),v1.end(), v2.begin(), v2.end(),v3.begin());

    for_each(v3.begin(), it_end, [](int value){cout << value << " ";});
    cout << endl;
}


/**
 * #### set_difference
 **功能描述：**
 * 求两个集合的差集
 **函数原型：**
 * set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * 求两个集合的差集
 * **注意:两个集合必须是有序序列**
 * beg1 容器1开始迭代器
 * end1 容器1结束迭代器
 * beg2 容器2开始迭代器
 * end2 容器2结束迭代器
 * dest 目标容器开始迭代器
 */
void test23() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);

    vector<int> v3;
    v3.resize(max(v1.size(), v2.size()));

    cout << "v1与v2的差集为： " << endl;
    auto it_end = set_difference(v1.begin(), v1.end(), v2.begin(),v2.end(), v3.begin());
    for_each(v3.begin(), it_end ,[](int value){cout << value << " ";});
    cout << endl;

    cout << "------------" << endl;

    cout << "v1: ";
    printVector(v1);
    cout << "v2: ";
    printVector(v2);
    cout << "v2与v1的差集为： " << endl;
    auto it_end2 = set_difference(v2.begin(), v2.end(),v1.begin(),v1.end(), v3.begin());
    for_each(v3.begin(), it_end2, [](int value){cout << value << " ";});
    cout << endl;
}

void test() {}

int main() {

//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
//    test08();
//    test09();
//    test10();


//    test11();
//    test12();
//    test13();
//    test14();
//    test15();
//    test16();
//    test17();
//    test18();
//    test19();
//    test20();

//    test21();
//    test22();
    test23();


    return 0;
}