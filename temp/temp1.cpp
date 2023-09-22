#include "iostream"
#include "vector"
#include "list"
#include "map"
#include "algorithm"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/22 10:31
* @description:  test
*/

void temp01() {
    int **arr = new int *[2];
    for (int i = 0; i < 2; ++i) {
        arr[i] = new int[2];
    }
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete arr[i];
    }
    delete arr;
}

void temp02() {
    vector<vector<int>> v(2, vector<int>(2));
    v[0][0] = 1;
    v[0][1] = 2;
    v[1][0] = 3;
    v[1][1] = 4;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

class Person {
public:
    string m_name;
    int m_age;

    Person(string name, int age) {
        this->m_age = age;
        this->m_name = name;
    }
};

void temp03() {
    Person p1("zs", 19);
    Person p2("ls", 20);
    Person p3("wu", 21);
    vector<Person> v{p1, p2, p3};
    for_each(v.begin(), v.end(), [](Person p) {
        cout << "name = " << p.m_name << "\tage = " << p.m_age << endl;
    });

    cout << "-----------------" << endl;
    list<Person> l{p1, p2, p3};
    for_each(l.begin(), l.end(), [](Person p) {
        cout << "name = " << p.m_name << "\tage = " << p.m_age << endl;
    });

    cout << "----------------\nmap1" << endl;
    map<int, Person> m;
    m.insert(pair<int, Person>(1, p1));
    m.insert(make_pair(2, p2));
    m.insert(pair<int, Person>(3, p3));
    // map中的元素实际上是pair<const Key, T>类型，其中Key是键的类型，T是值的类型。因此，你应该使用const修饰elem来匹配map的元素类型
    for_each(m.begin(),m.end(),[](pair<const int,Person> &elem){
        cout << "index = " << elem.first << "\tname = " << elem.second.m_name << "; age = " << elem.second.m_age << endl;
    });

    cout << "---------------\nmap2" << endl;
    int index = 1;
    map<int, Person> m2 = {{index++,p1},{index++,p2},{index++, p3}};
    for_each(m2.begin(),m2.end(), [&m](pair<const int, Person> &elem){
        cout << "index = " << elem.first << "\tname = " << elem.second.m_name << "; age = " << elem.second.m_age << endl;
    });

    cout << "---------------\nlist" << endl;
    list<Person> l1 = {p1, p2, p3};


}
class Person2{
public:
    static int a;
    int b;
};
int Person2::a = 1;
void temp04() {
    Person2 p;
    p.b = 2;
    cout << Person2::a << endl;
}

int main() {

//    temp01();
//    temp02();
//    temp03();
    temp04();

    return 0;
}