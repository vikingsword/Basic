//#include "iostream"
//
//// 1. 第一种解决方式，直接包含源文件
////#include "02_person.cpp"
//
//// 2. 第二种解决方式： 将.h和.cpp文件写到一起，改成.hpp文件
//#include "headers/person.hpp"
//
//#define T T
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/15 12:38
//* @description:  c++中的模板： 类模板
//*/
//
//
///**
// * 类模板
// */
//template<typename T, typename R>
//class Person {
//public:
//    T m_name;
//    R m_age;
//
//    Person(T name, R age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//    void showPerson() {
//        cout << "name: " << this->m_name << " age: " << this->m_age << endl;
//    }
//};
//
//void test01() {
//    Person p1("zs", 18);
//    Person p2("ls", 12);
//    p1.showPerson();
//    p2.showPerson();
//}
//
//
///**
// * 类模板和函数模板的区别
// * 1. 类模板没有自动类型推导的使用方式
// * 2. 类模板在模板参数列表中可以有默认参数
// */
//template<class NameType, class AgeType = int>
//class Person2 {
//public:
//    NameType m_name;
//    AgeType m_age;
//
//    Person2(NameType name, AgeType age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//    void showPerson() {
//        cout << "name: " << this->m_name << " age: " << this->m_age << endl;
//    }
//
//};
//
//void test02() {
//    // 不能这么写，类模板没有自动类型推导
////    Person3 p1("zs", 10);
////    p1.showPerson();
//
//    // 只能用显示类型
//    Person2<string, int> p2("zs", 12);
//    p2.showPerson();
//}
//
//void test02_2() {
//    Person2<string> p3("ls", 100);
//    p3.showPerson();
//}
//
//
///**
// * 类模板中成员函数的创建时机
// * * 普通类中的成员函数一开始就可以创建
// * 类模板中的成员函数在调用时才创建
// */
//class Person3 {
//public:
//    void showPerson4() {
//        cout << "this is person4" << endl;
//    }
//};
//
//class Person4 {
//public:
//    void showPerson5() {
//        cout << "this is person5" << endl;
//    }
//};
//
//template<class T>
//class MyClass {
//public:
//    T obj;
//
//    // 类模板中的成员函数
//    void function1() {
//        obj.showPerson4();
//    }
//
//    void function2() {
//        obj.showPerson5();
//    }
//};
//
//void test03() {
//    MyClass<Person4> m;
////    m.function1();
//    m.function2();
//}
//
//
///**
// * 类模板对象做函数参数
// * 1. 指定传入的类型   --- 直接显示对象的数据类型
// * 2. 参数模板化      --- 将对象中的参数变为模板进行传递
// * 3. 整个类模板化    --- 将这个对象类型 模板化进行传递
// */
//template<class T1, class T2>
//class Person5 {
//public:
//    T1 m_name;
//    T2 m_age;
//
//    Person5(T1 name, T2 age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//    void showPerson() {
//        cout << "name: " << this->m_name << " age: " << this->m_age << endl;
//    }
//};
//
//// 1. 指定传入的数据类型 (最常用)
//void printPerson1(Person5<string, int> &p) {
//    p.showPerson();
//}
//
//void test04() {
//    Person5<string, int> p1("zs", 10);
//    printPerson1(p1);
//}
//
//// 2. 参数模板化
//template<typename T1, typename T2>
//void printPerson2(Person5<T1, T2> &p) {
//    p.showPerson();
//    cout << "T1 的类型为： " << typeid(T1).name() << endl;
//    cout << "T2 的类型为： " << typeid(T2).name() << endl;
//}
//
//void test04_2() {
//    Person5<string, int> p1("zs", 22);
//    printPerson2(p1);
//}
//
//// 3. 整个类的模板化
//template<typename T>
//void printPerson3(T &p) {   // 直接传入 person5
//    p.showPerson();
//    cout << "T的数据类型为： " << typeid(T).name() << endl;
//}
//
//void test04_3() {
//    Person5<string, int> p("zs", 223);
//    printPerson3(p);
//}
//
//
///**
// * 类模板与继承
// * 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// * 如果不指定，编译器无法给子类分配内存
// * 如果想灵活指定出父类中T的类型，子类也需变为类模板
// */
//template<typename T>
//class Base {
//public:
//    T m;
//};
//
//// 必须要知道父类中的数据类型才能继承给子类
//class Son : public Base<int> {
//
//};
//
//void test05() {
//    Son s1;
//}
//
//template<typename T1, typename T2>
//class Son2 : public Base<T2> {
//public:
//    T1 obj;
//};
//
//void test05_2() {
//    Son2<int, char> s2;
//    s2.m = 'z';
//    s2.obj = 1;
//    cout << "s2.m = " << s2.m << endl;
//    cout << "s2.obj = " << s2.obj << endl;
//}
//
//
///**
// * 类模板成员函数的类外实现
// */
//template<typename T1, typename T2>
//class Person6 {
//public:
//    T1 m_name;
//    T2 m_age;
//
//    Person6(T1 name, T2 age);
//
//    void showPerson();
//
//};
//
//// 构造函数类外实现
//template<typename T1, typename T2>
//Person6<T1, T2>::Person6(T1 name, T2 age) {
//    this->m_name = name;
//    this->m_age = age;
//}
//
//// 成员函数的类外实现
//template<class T1, class T2>
//void Person6<T1, T2>::showPerson() {
//    cout << "name: " << this->m_name << " age: " << this->m_age << endl;
//}
//
//void test06() {
//    Person6<string, int> p("zs", 19);
//    p.showPerson();
//}
//
//
///**
// * 类模板分文件编写的问题及解决
// */
//void test07() {
//    Person7<string,int> p("ss", 22);
//    p.showPerson();
//}
//
//
///**
// * 类模板与友元
// * 全局函数类内实现 - 直接在类内声明友元即可
// * 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
// */
//template<class T1,class T2>
//class Person8;
//// 类外实现，全局函数不用加作用域
//template<class T1, class T2>
//void printPerson2(Person8<T1,T2> p){
//    cout << "类外实现----姓名： " << p.m_name << "; 年龄： " << p.m_age << endl;
//}
//
//template<class T1,class T2>
//class Person8{
//public:
//    // 全局函数，类内实现
//    friend void printPerson(Person8<T1,T2> p) {
//        cout << "类内实现----姓名： " << p.m_name << "; 年龄： " << p.m_age << endl;
//    }
//
//    // 全局函数 类外实现
//    // 要加空模板的参数列表，表示是模板函数而不是普通函数
//    // 全局函数如果是类外实现的，需要让编译器知道这个函数的存在，要把实现放在上面
//    friend void printPerson2<>(Person8<T1, T2> p);
//
//    Person8(T1 name, T2 age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//private:
//    T1 m_name;
//    T2 m_age;
//};
//
//
//void test08() {
//    Person8<string,int> p("zs",33);
//    printPerson(p);
//}
//void test08_1() {
//    Person8<string,int> p("zs",25);
//    printPerson2(p);
//}
//
//
//int main() {
//
////    test01();
//
////    test02();
//
////    test02_2();
//
////    test03();
//
////    test04();
//
////    test04_2();
//
////    test04_3();
//
////    test05_2();
//
////    test06();
//
////    test07();
//
////    test08();
//
//    test08_1();
//
//    return 0;
//}