#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/15 16:36
* @description:  
*/

// vector 容器存放内置数据类型
void myPrint(int val) {
    cout << val << endl;
}

void test01() {
    // 创建一个 vector 容器，就是一个数组
    vector<int> v;
    // 想容器中插入数据
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // 通过迭代器访问容器中的数据
    // v.begin()起始迭代器，指向容器中第一个元素
    vector<int>::iterator itBegin = v.begin();
    // v.end() 结束迭代器，指向容器中最后一个元素的下一个位置
    vector<int>::iterator itEnd = v.end();

    // 1. 遍历方式 while
    while (itBegin != itEnd) {
        cout << *itBegin << "\t";
        itBegin++;
    }
    cout << endl;

    // 2. 遍历方式 for
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;

    // 3. 遍历方式 stl 提供的遍历算法
    for_each(v.begin(), v.end(), myPrint);

}


/**
 * vector 存放自定义数据类型
 */
class Person {
public:
    string m_name;
    int m_age;

    Person(string name, int age) {
        this->m_name = name;
        this->m_age = age;
    }
};

void test02() {
    vector<Person> v;
    Person p1("zs", 10);
    Person p2("ls", 12);
    Person p3("wu", 14);
    // 向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    // 遍历容器中的数据
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << (*it).m_name << "; 年龄： " << (*it).m_age << endl;
//        cout << "姓名：" << it->m_name << "; 年龄： " << it->m_age << endl;
    }
}

void test03() {
    vector<Person *> v;
    Person p1("zs", 10);
    Person p2("ls", 12);
    Person p3("wu", 14);
    // 向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "name = " << (*it)->m_name << "; age = " << (*it)->m_age << endl;
    }
}


/**
 * 容器嵌套容器
 */
void test04() {
    // 容器嵌套容器
    vector<vector<int>> v;

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    // 小容器中添加数据, 要放在下面的前面
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
    }

    // 大容器中添加小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);


    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout << (*vit) << " ";
        }
        cout << endl;
    }


}


void test() {}

int main() {

//    test01();

//    test02();

//    test03();

    test04();

    return 0;
}