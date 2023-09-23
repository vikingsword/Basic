#include "iostream"

using namespace std;


void temp01() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p = arr;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        cout << *p++ << endl;
    }
    cout << len << endl;


    int arr2[2][3] = {
            {1, 2, 3},
            {4, 5, 6},
    };

}


void showValue(const int &v) {
    cout << v << endl;
}

void temp02() {

    const int &ref = 1;
    showValue(ref);

    cout << ref << endl;
}


int &test03(int &v) {
    v++;
    cout << v << endl;
    return v;
}

void temp03() {
    int a = 1;
    int &ref = a;
    int &temp = test03(ref);
    cout << temp << endl;
}


//函数重载注意事项
//1、引用作为重载条件
void func(int &a) {
    cout << "func (int &a) 调用 " << endl;
}
void func(const int &a) {
    cout << "func (const int &a) 调用 " << endl;
}
//2、函数重载碰到函数默认参数
void func2(int a, int b = 10) {
    cout << "func2(int a, int b = 10) 调用" << endl;
}
void func2(int a) {
    cout << "func2(int a) 调用" << endl;
}
void temp04() {
    int a = 10;
    const int b = 20;
    int c = 30;
//    func(a);
//    func(b);
    func2(a, c);
//    func2(static_cast<int>(3));
    //func2(10); //碰到默认参数产生歧义，需要避免
}

class Animal{
public:
    string m_name;
    int m_age;
    virtual void yell() {}
};
class Dog : public Animal{
public:
    void yell(){
        cout << "dog yell" << endl;
    }
};
class Cat : public Animal{
public:
    void yell() {
        cout << "cat yell" << endl;
    }
};
void temp05() {
    Dog dog;
    dog.yell();
    Cat cat;
    cat.yell();
}

const double PI = 3.14;
class Circle{
public:
    int m_r;
    double getPerimeter() {
        return 2 * PI * this->m_r;
    }
};
void temp06() {
    Circle c1;
    c1.m_r = 10;
    double len = c1.getPerimeter();
    cout << "len = " << len << endl;
}

class Student {
private:
    string m_name;
    string m_id;

public:
    void set_name(string name) {
        this->m_name = name;
    }
    void set_id(string id) {
        this->m_id = id;
    }
    void show_name() {
        cout << this->m_name << endl;
    }
    void show_id() {
        cout << this->m_id << endl;
    }
};
void temp07() {
    Student s;
    s.set_name("zs");
    s.set_id("a1");
    s.show_name();
    s.show_id();
}

class Person{
public:
    static int m_a;
private:
    static int m_b;
};
int Person::m_a = 10;
int Person::m_b = 20;
void temp08() {
    Person p;
    p.m_a = 100;
    cout << "p.m_a = " << p.m_a << endl;

    Person p2;
    p2.m_a = 200;
    cout << "p2.m_a = " << p2.m_a << endl;

    cout << "Person::m_a = " << Person::m_a << endl;
}


int main() {

//    temp01();
//    temp02();
//    temp03();
//    temp04();
//    temp05();
//    temp06();
//    temp07();
    temp08();
//    temp09();
//    temp10();


    return 0;

}