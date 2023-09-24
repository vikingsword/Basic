#include "iostream"
#include "vector"
#include "list"
#include "map"
#include "deque"
#include "algorithm"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/24 15:51
* @description: stl : standard template library
*/

void temp01() {
    vector v{1, 2, 3};
    for_each(v.begin(), v.end(), [&v](int num) {
        cout << num << " ";
    });
    cout << endl;

    vector<int> v2{1, 2, 3};
    for_each(v.begin(), v.end(), [&v](int num) {
        cout << num << " ";
    });
    cout << endl;
}

class Animal {
public:
    virtual void yell() = 0;
};
class Dog : public Animal{
public:
    virtual void yell();
};

void Dog::yell() {
    cout << "www" << endl;
}
void temp02() {
    Dog dog;
    dog.yell();
}


void temp03() {
    cout << "aaaaaaa\tbbb" << endl;
    cout << "aaaa\tbb" << endl;
}
class Person{
    void printPerson(Person *p) {
        cout << "hello person" << endl;
    }
};

void temp04() {
    Person *per = NULL;
    cout << per << endl;
    int a = 10;
    int *p = &a;
    int *q = &a;
    cout << *q << endl;


}
void printPerson(Person *p) {
    cout << "hello person" << endl;
}
void printPerson3(Person &p) {
    cout << "add person" << endl;
}
void temp05() {
    Person *p = new Person;
    printPerson(p);

    Person q;
    // *p = &q;
    printPerson(&q);

    printPerson3(q);
}



void log(const char * message) {
    cout << message << endl;
}
void temp06() {
    log("hello world");
    cin.get();
}


int main() {

//    temp01();
//    temp02();
//    temp03();
//    temp04();
//    temp05();
    temp06();
//    temp07();
//    temp08();
//    temp09();
//    temp10();


    return 0;
}