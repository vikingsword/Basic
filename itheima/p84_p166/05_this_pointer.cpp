//#include "iostream"
//
//using namespace std;
//
///**
// *  this指针的用途：
// *  当形参和成员变量同名时，可用this指针来区分
// *  在类的非静态成员函数中返回对象本身，可使用return *this
// * @return
// */
//
//class Person1 {
//public:
//    int age;
//
//    Person1(int age) {
//        // this指针指定的是被调用的成员函数所属的对象
//        this->age = age;
//    }
//
//public:
//    void PersonAddAge(Person1 &p) {
//        this->age += p.age;
//    }
//
//    Person1 &PersonAddAge2(Person1 &p2) {
//        this->age += p2.age;
//        return *this;
//    }
//};
//
//void test1() {
//    Person1 p1(10);
//    cout << "p1 的年龄为： " << p1.age << endl;
//}
//
//void test1_2() {
//
//    Person1 p1(10);
//
//    Person1 p2(10);
//
//    p2.PersonAddAge(p1);
//
//    cout << "p2 = " << p2.age << endl;
//
//}
//
//void test1_3() {
//
//    Person1 p1(10);
//
//    Person1 p2(10);
//
//    // 链式编程
//    p2.PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1);
//
//    cout << "p2 = " << p2.age << endl;
//}
//
//class Person2 {
//public:
//    void showClassName() {
//        cout << "this is person class " << endl;
//    }
//
//    void showPerson() {
//        if (this == NULL) {
//            return;
//        }
//        // 报错原因是传入的指针为 null
//        cout << "this is person age = " << this->m_age << endl;
//    }
//
//    int m_age;
//
//};
//
//void test2() {
//
//    Person2 *p = NULL;
//
//    p->showClassName();
//
//    p->showPerson();
//
//}
//
//
//class Person3 {
//public:
//    // 在成员函数后加上 const ， 修饰的是 this 指向， 让指针指向的值也不可以修改
//    void showPerson() const {
////        this->m_age = 100;
//        // this 指针不可以修改指针的指向
////        this = NULL;
//        this->m_height = 200;
//    }
//
//    int m_age;
//    mutable int m_height;
//};
//
//void test3(){
//
////    // 加上 const 变为常对象
////    const Person3 p;
//////    p.m_age = 100;
//////    p.m_height = 100;
////
////    p.showPerson();
//
//
//}
//
//
//int main() {
//
////    test1();
//
////    test1_2();
//
////    test1_3();
//
////    test2();
//
//    test3();
//}