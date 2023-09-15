#pragma once
#include "iostream"
using namespace std;

/**
 * 同时写声明和实现
 */

template<typename T1, typename T2>
class Person7 {
public:
    T1 m_name;
    T2 m_age;

    Person7(T1 name, T2 age);

    void showPerson();
};


template<class T1, class T2>
Person7<T1,T2>::Person7(T1 name, T2 age) {
    this->m_name = name;
    this->m_age = age;
}
template<class T1,class T2>
void Person7<T1, T2>::showPerson() {
    cout << "name: " << this->m_name << " age: " << this->m_age << endl;
}

