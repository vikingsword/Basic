#include "iostream"

using namespace std;

class Person {

public:
    int m_a;
    int m_b;

public:
    int add_param() {
        return m_a + m_b;
    }

    Person add_person_param(Person &p) {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }

    Person add_person_param2(Person p) {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }

//    Person operator+(Person &p) {
//        Person temp;
//        temp.m_a = this->m_a + p.m_a;
//        temp.m_b = this->m_b + p.m_b;
//        return temp;
//    }

};


Person operator+(Person &p1, Person &p2) {
    Person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

// operator+ 重载
Person operator+(Person &p1, int num) {
    Person temp;
    temp.m_a = p1.m_a + num;
    temp.m_b = p1.m_b + num;
    return temp;
}

Person operator-(Person &p1, Person &p2) {
    Person temp;
    temp.m_a = p1.m_a - p2.m_a;
    temp.m_b = p1.m_b - p2.m_b;
    return temp;
}

Person operator*(Person &p1, Person &p2) {
    Person temp;
    temp.m_a = p1.m_a * p2.m_a;
    temp.m_b = p1.m_b * p2.m_b;
    return temp;
}

void test01() {

    Person p1;
    p1.m_a = 10;
    p1.m_b = 10;

    Person p2;
    p2.m_a = 10;
    p2.m_b = 10;

//    p1.add_person_param(p2);
//    cout << "p1.m_a = " << p1.m_a << endl;
//    cout << "p2.m_a = " << p2.m_a << endl;

//    p1.add_person_param2(p2);
//    cout << "p1.m_a = " << p1.m_a << endl;
//    cout << "p2.m_a = " << p2.m_a << endl;

//    Person p3 = p1.operator+(p2);
//    cout << "p3.m_a = " << p3.m_a << endl;

    // 通过成员函数重载 + 号
//    Person p4 = p1 + p2;
//    cout << "p4.m_a = " << p4.m_a << endl;

//    Person p5 = operator+(p1,p2);
//    cout << "p4.m_a = " << p5.m_a << endl;

//    // 成员函数、全局函数重载
//    // 原式分别为 p1.operator+(p2)   operator+(p1,p2)
//    Person p6 = p1 + p2;
//    cout << "p6.m_a = " << p6.m_a << endl;
//    cout << "p6.m_b = " << p6.m_b << endl;

//    // operator+ 重载
//    Person p7 = p1 + 11;
//    cout << "p7.m_a = " << p7.m_a << endl;

//    Person p8 = p1 - p2;
//    cout << "p8.m_a = " << p8.m_a << endl;

//    Person p9 = p1 * p2;
//    cout << "p9.m_a = " << p9.m_a << endl;

}


/**
 * 左移运算符重载
 * @return
 */
class Person2 {
    friend ostream &operator<<(ostream &cout, Person2 &p);

public:
    Person2(int a, int b) {
        m_a = a;
        m_b = b;
    }

private:
    int m_a;
    int m_b;
};

// ostream 全局只能有一个，所以要通过引用的方式传递进来
// 重载左移运算符，输出自定义数据类型
ostream &operator<<(ostream &cout, Person2 &p) {
    cout << "m_a = " << p.m_a << "; m_b = " << p.m_b;
    return cout;
}

void test02() {

    Person2 p(10, 10);

    cout << p << " hello " << endl;

}


/**
 * 递增运算符重载
 * @return
 */
class MyInteger{
    // 让全局函数访问类中的私有成员变量
    friend ostream& operator<<(ostream &cout, MyInteger myInteger);
public:
    MyInteger(){
        m_num = 0;
    }

    // 重载前置递增
    MyInteger& operator++(){
        m_num++;
        return *this;
    }

    // 重载后置递增
    // int 代表占位参数，可以用于输出前置和后置递增
    MyInteger operator++(int){
        // 记录当前结果
        MyInteger temp = *this;
        // 递增
        m_num++;
        // 将记录结果做返回
        return temp;
    }

private:
    int m_num;


};

// 先重载左移运算符
ostream& operator<<(ostream &cout, MyInteger myInteger) {
    cout << myInteger.m_num;
    return cout;
}

void test03(){
    MyInteger myInteger;
    cout << ++myInteger << endl;
}

void test04(){
    MyInteger myInteger;
    cout << "myInteger = " << myInteger++ << endl;
    cout << "myInteger = " << myInteger << endl;
}



int main() {

//    test01();

//    test02();

//    test03();

    test04();


}