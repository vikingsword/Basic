#include "iostream"
#include "headers/person.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/15 14:12
* @description:  person class
*/

template<class T1, class T2>
Person7<T1,T2>::Person7(T1 name, T2 age) {
    this->m_name = name;
    this->m_age = age;
}
template<class T1,class T2>
void Person7<T1, T2>::showPerson() {
    cout << "name: " << this->m_name << " age: " << this->m_age << endl;
}
