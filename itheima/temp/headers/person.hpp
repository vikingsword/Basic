#pragma once
#include "iostream"

using namespace std;

template<typename T, typename R>
class Person2 {
public:
    string m_name;
    int m_age;
    Person(T name, R age) {
        this->m_age = age;
        this->m_name = name;
    }
    void showPerson() {
        cout << "name: " << this->m_name << "; age = " << this->m_age << endl;
    }
};