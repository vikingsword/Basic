#include "iostream"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/24 15:36
* @description: temp4
*/

class Animal {
public:
    virtual void yell() = 0;
};
class Cat : public Animal {
    void yell() override {
        cout << "cat yell" << endl;
    }
};
class Dog : public Animal {
    void yell() override {
        cout << "dog yell" << endl;
    }
};
void doYell(Animal & animal) {
    animal.yell();
}
void doYell2(Animal * animal) {
    animal->yell();
}
void temp01() {
    Cat cat;
    doYell(cat);

    Dog dog;
    doYell(dog);
}
void temp02() {
    Cat cat;
    doYell2(&cat);

    Dog dog;
    doYell2(&dog);

    doYell2(new Cat);

    Animal * a = &cat;
    doYell2(a);
//    Cat *cat2 = new Cat;
//    doYell2(cat2);
}


class Animal2 {
public:
    virtual void yell() = 0;
};
class Cat2 : public Animal2 {
    void yell() override {
        cout << "cat yell" << endl;
    }
};
class Dog2 : public Animal2 {
    void yell() override {
        cout << "dog yell" << endl;
    }
};

void doYell(Animal * animal) {
    animal->yell();
}

void temp03() {
    Cat cat;

    doYell(&cat);
    doYell(new Cat);
}

class Demo1{
public:
    int m_a;
};
void temp04() {
    int a = 10;
    int * p = &a;
    int arr[] = {1,2,3};
    // arr在这里已经被隐式转换为指向数组首元素的指针
    int * p1 = arr;

    cout << "-----------" << endl;
    Demo1 demo1;
    Demo1 * p2 = &demo1;

    int (*p3)[3] = &arr;
    for (int i = 0; i < 3; ++i) {
        cout << (*p3)[i] << " ";
    }

    Demo1 *p4 = new Demo1;
    cout << "p2 = " << p2 << endl;
    cout << "p4 = " << p4 << endl;



}








int main() {

//    temp01();
//    temp02();
//    temp03();
    temp04();
//    temp05();
//    temp06();
//    temp07();
//    temp08();
//    temp09();
//    temp10();

    return 0;
}