#include "iostream"
using namespace std;

/**
 *  this指针的用途：
 *  当形参和成员变量同名时，可用this指针来区分
 *  在类的非静态成员函数中返回对象本身，可使用return *this
 * @return
 */

class Person1{
public:
    int age;
    Person1(int age){
        // this指针指定的是被调用的成员函数所属的对象
        this->age = age;
    }
public:
    void PersonAddAge(Person1 &p){
        this->age += p.age;
    }

    Person1& PersonAddAge2(Person1 &p2){
        this->age += p2.age;
        return *this;
    }
};

void test1(){
    Person1 p1(10);
    cout << "p1 的年龄为： " << p1.age << endl;
}

void test1_2(){

    Person1 p1(10);

    Person1 p2(10);

    p2.PersonAddAge(p1);

    cout << "p2 = " << p2.age << endl;

}

void test1_3(){

    Person1 p1(10);

    Person1 p2(10);

    // 链式编程
    p2.PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1);

    cout << "p2 = " << p2.age << endl;
}

int main(){

//    test1();

//    test1_2();

    test1_3();


}