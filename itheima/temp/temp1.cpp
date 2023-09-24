//#include "iostream"
//#include "vector"
//#include "list"
//#include "map"
//#include "algorithm"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/22 10:31
//* @description:  test
//*/
//
//void temp01() {
//    int **arr = new int *[2];
//    for (int i = 0; i < 2; ++i) {
//        arr[i] = new int[2];
//    }
//    arr[0][0] = 1;
//    arr[0][1] = 2;
//    arr[1][0] = 3;
//    arr[1][1] = 4;
//
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < 2; ++i) {
//        delete arr[i];
//    }
//    delete arr;
//}
//
//void temp02() {
//    vector<vector<int>> v(2, vector<int>(2));
//    v[0][0] = 1;
//    v[0][1] = 2;
//    v[1][0] = 3;
//    v[1][1] = 4;
//
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//class Person {
//public:
//    string m_name;
//    int m_age;
//
//    Person(string name, int age) {
//        this->m_age = age;
//        this->m_name = name;
//    }
//};
//
//void temp03() {
//    Person p1("zs", 19);
//    Person p2("ls", 20);
//    Person p3("wu", 21);
//    vector<Person> v{p1, p2, p3};
//    for_each(v.begin(), v.end(), [](Person p) {
//        cout << "name = " << p.m_name << "\tage = " << p.m_age << endl;
//    });
//
//    cout << "-----------------" << endl;
//    list<Person> l{p1, p2, p3};
//    for_each(l.begin(), l.end(), [](Person p) {
//        cout << "name = " << p.m_name << "\tage = " << p.m_age << endl;
//    });
//
//    cout << "----------------\nmap1" << endl;
//    map<int, Person> m;
//    m.insert(pair<int, Person>(1, p1));
//    m.insert(make_pair(2, p2));
//    m.insert(pair<int, Person>(3, p3));
//    // map中的元素实际上是pair<const Key, T>类型，其中Key是键的类型，T是值的类型。因此，你应该使用const修饰elem来匹配map的元素类型
//    for_each(m.begin(),m.end(),[](pair<const int,Person> &elem){
//        cout << "index = " << elem.first << "\tname = " << elem.second.m_name << "; age = " << elem.second.m_age << endl;
//    });
//
//    cout << "---------------\nmap2" << endl;
//    int index = 1;
//    map<int, Person> m2 = {{index++,p1},{index++,p2},{index++, p3}};
//    for_each(m2.begin(),m2.end(), [&m](pair<const int, Person> &elem){
//        cout << "index = " << elem.first << "\tname = " << elem.second.m_name << "; age = " << elem.second.m_age << endl;
//    });
//
//    cout << "---------------\nlist" << endl;
//    list<Person> l1 = {p1, p2, p3};
//
//
//}
//class Person2{
//public:
//    static int a;
//    int b;
//};
//int Person2::a = 1;
//void temp04() {
//    Person2 p;
//    p.b = 2;
//    cout << Person2::a << endl;
//}
//
///**
// * c++ 中的链式调用
// */
//class Person3{
//public:
//    string m_name;
//    int m_age;
//
//    Person3 & personAddAge(Person3 &p) {
//        this->m_age = p.m_age;
//        return *this;
//    }
//
//    Person3 & personAddName(Person3 &p) {
//        this->m_name = p.m_name;
//        return *this;
//    }
//
//    void printPerson() {
//        cout << "name = " << this->m_name << endl;
//        cout << "age = " << this->m_age << endl;
//    }
//
//    Person3(string name, int age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//};
//void temp05() {
//    Person3 p1("zs", 28);
//    Person3 p("ls",1);
//    p.personAddAge(p1).personAddName(p1).printPerson();
//
//}
//
//class Person4{
//public:
//    int m_age;
//    void func() {
//        cout << this << endl;
//    }
//};
//void temp06() {
//    Person4 p;
////    p.func();
//    Person4 * p2 = new Person4();
//    cout << p2->m_age << endl;
//    delete p2;
//
//    // 野指针
////    Person4 * p3;
////    cout << "p3.age = " << p3->m_age << endl;
//
//}
//
///**
// * reload operator
// */
//class Person5 {
//public:
//    int m_value;
//    Person5(int value) : m_value(value){};
//
//    // 重载 + 运算符
//    Person5 operator+(Person5 & p) {
//        Person5 res(m_value + p.m_value);
//        return res;
//    }
//};
//void temp07() {
//    Person5 p1(1);
//    Person5 p2(2);
//    Person5 res = p1 + p2;
//    cout << "result: " << res.m_value << endl;
//}
//
//
//void mySwap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    cout << "first = " << a << "; second = " << b << endl;
//}
//void temp08() {
//    int a = 10;
//    int &b = a;
//    cout << "b = " << b << endl;
//
//    int c = 10;
//    int d = 20;
//    mySwap(&c, &d);
//}
//
//
//int& test01() {
//    int a = 10;
//    // 不要返回局部变量的引用
//    return a;
//}
//int & test02() {
//    static int a = 10;
//    return a;
//}
//void temp09() {
//    int a = test02();
//    cout << "a = " << a << endl;
//
//    // 这一行创建了一个对 test02() 返回的静态变量 a 的引用 ref2。这是安全的，因为静态变量会持续存在，您可以使用 ref2 来访问和修改 a 的值。
//    int& ref = test02();
//    cout << "ref = " << ref << endl;
//
//    // 这一行将值 100 赋给 test02() 中的静态变量 a。由于 test02() 返回对 a 的引用，您可以以这种方式修改它的值。
//    test02() = 100;
//    cout << "ref = " << ref << endl;
//
//}
//
//void func(int& ref) {
//    ref = 100;
//}
//void temp10() {
//    int a = 10;
//    // 自动转化为 int * const ref = &a;
//    // 指针常量是指针指向不可改，也说明为什么引用不可更改
//    int &ref = a;
//    // 内部发现 ref 是引用，自动帮我们转化为： *ref = 20;
//    ref = 20;
//
//    cout << "a: " << a << endl;
//    cout << "ref: " << ref << endl;
//
//    func(a);
//
//}
//
//int main() {
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
//    temp10();
//
//    return 0;
//}