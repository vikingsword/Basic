//#include "iostream"
//#include "headers/person.hpp"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/24 15:36
//* @description: temp4
//*/
//
//class Animal {
//public:
//    virtual void yell() = 0;
//};
//class Cat : public Animal {
//    void yell() override {
//        cout << "cat yell" << endl;
//    }
//};
//class Dog : public Animal {
//    void yell() override {
//        cout << "dog yell" << endl;
//    }
//};
//void doYell(Animal & animal) {
//    animal.yell();
//}
//void doYell2(Animal * animal) {
//    animal->yell();
//}
//void temp01() {
//    Cat cat;
//    doYell(cat);
//
//    Dog dog;
//    doYell(dog);
//}
//void temp02() {
//    Cat cat;
//    doYell2(&cat);
//
//    Dog dog;
//    doYell2(&dog);
//
//    doYell2(new Cat);
//
//    Animal * a = &cat;
//    doYell2(a);
////    Cat *cat2 = new Cat;
////    doYell2(cat2);
//}
//
//
//class Animal2 {
//public:
//    virtual void yell() = 0;
//};
//class Cat2 : public Animal2 {
//    void yell() override {
//        cout << "cat yell" << endl;
//    }
//};
//class Dog2 : public Animal2 {
//    void yell() override {
//        cout << "dog yell" << endl;
//    }
//};
//
//void doYell(Animal * animal) {
//    animal->yell();
//}
//
//void temp03() {
//    Cat cat;
//
//    doYell(&cat);
//    doYell(new Cat);
//}
//
//class Demo1{
//public:
//    int m_a;
//};
//void temp04() {
//    int a = 10;
//    int * p = &a;
//    int arr[] = {1,2,3};
//    // arr在这里已经被隐式转换为指向数组首元素的指针
//    int * p1 = arr;
//
//    cout << "-----------" << endl;
//    Demo1 demo1;
//    Demo1 * p2 = &demo1;
//
//    int (*p3)[3] = &arr;
//    for (int i = 0; i < 3; ++i) {
//        cout << (*p3)[i] << " ";
//    }
//
//    Demo1 *p4 = new Demo1;
//    cout << "p2 = " << p2 << endl;
//    cout << "p4 = " << p4 << endl;
//
//}
//
//
///**
// * 子类模板继承
// */
//template<typename T>
//class Base1 {
//    T m;
//};
//class Son1 : public Base1<int> {
//public:
//    int m_a;
//};
//void test01() {
//    Son1 s;
//}
//
//template<typename T, typename R>
//class Son2 : public Base1<R> {
//public:
//    R m_a;
//    Son2() {
//        cout << typeid(T).name() << endl;
//        cout << typeid(R).name() << endl;
//    }
//};
//
//void temp05() {
//    Son2<int, char> child1;
//}
//
//
///**
// * 类模板中成员函数类外实现
// * 类模板中成员函数类外实现时，需要加上模板参数列表
// */
//template<typename T1, typename T2>
//class Person{
//public:
//    T1 m_name;
//    T2 m_age;
//    Person(T1 name, T2 age);
//    void showPerson();
//};
//
//// 构造函数类外实现
//template<typename T1, typename T2>
//Person<T1,T2>::Person(T1 name,T2 age) {
//    this->m_name = name;
//    this->m_age = age;
//}
//// 成员函数类外实现
//template<typename T1, typename T2>
//void Person<T1,T2>::showPerson() {
//    cout << "name = " << this->m_name << "; age = " << m_age << endl;
//}
//void temp06() {
//    Person<string,int> p("tom", 38);
//    p.showPerson();
//}
//
//
///**
// * 类模板分文件编写
// */
//void temp07() {
//    Person<string, int> p = {"zs", 38};
//    p.showPerson();
//}
//
//
///**
// * 模板和友元
// */
//template<typename T, typename R>
//class Person3 {
//public:
//    friend void printPerson3(Person3<T,R> &p) {
//        cout << "name = " << p.m_name << "; age = " << p.m_age << endl;
//    }
//    Person3(T name, R age)
//    {
//        this->m_name = name;
//        this->m_age = age;
//    }
//private:
//    T m_name;
//    R m_age;
//};
//void temp08() {
//    Person3<string,int> p {"zs",33};
//    printPerson3(p);
//}
//
//
//
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
//    temp08();
//
//    return 0;
//}