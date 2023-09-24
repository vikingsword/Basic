//#include "iostream"
//
//using namespace std;
//
//class Person {
//
//public:
//    int m_a;
//    int m_b;
//
//public:
//    int add_param() {
//        return m_a + m_b;
//    }
//
//    Person add_person_param(Person &p) {
//        Person temp;
//        temp.m_a = this->m_a + p.m_a;
//        temp.m_b = this->m_b + p.m_b;
//        return temp;
//    }
//
//    Person add_person_param2(Person p) {
//        Person temp;
//        temp.m_a = this->m_a + p.m_a;
//        temp.m_b = this->m_b + p.m_b;
//        return temp;
//    }
//
////    Person operator+(Person &p) {
////        Person temp;
////        temp.m_a = this->m_a + p.m_a;
////        temp.m_b = this->m_b + p.m_b;
////        return temp;
////    }
//
//};
//
//
//Person operator+(Person &p1, Person &p2) {
//    Person temp;
//    temp.m_a = p1.m_a + p2.m_a;
//    temp.m_b = p1.m_b + p2.m_b;
//    return temp;
//}
//
//// operator+ 重载
//Person operator+(Person &p1, int num) {
//    Person temp;
//    temp.m_a = p1.m_a + num;
//    temp.m_b = p1.m_b + num;
//    return temp;
//}
//
//Person operator-(Person &p1, Person &p2) {
//    Person temp;
//    temp.m_a = p1.m_a - p2.m_a;
//    temp.m_b = p1.m_b - p2.m_b;
//    return temp;
//}
//
//Person operator*(Person &p1, Person &p2) {
//    Person temp;
//    temp.m_a = p1.m_a * p2.m_a;
//    temp.m_b = p1.m_b * p2.m_b;
//    return temp;
//}
//
//void test01() {
//
//    Person p1;
//    p1.m_a = 10;
//    p1.m_b = 10;
//
//    Person p2;
//    p2.m_a = 10;
//    p2.m_b = 10;
//
////    p1.add_person_param(p2);
////    cout << "p1.m_a = " << p1.m_a << endl;
////    cout << "p2.m_a = " << p2.m_a << endl;
//
////    p1.add_person_param2(p2);
////    cout << "p1.m_a = " << p1.m_a << endl;
////    cout << "p2.m_a = " << p2.m_a << endl;
//
////    Person p3 = p1.operator+(p2);
////    cout << "p3.m_a = " << p3.m_a << endl;
//
//    // 通过成员函数重载 + 号
////    Person p4 = p1 + p2;
////    cout << "p4.m_a = " << p4.m_a << endl;
//
////    Person p5 = operator+(p1,p2);
////    cout << "p4.m_a = " << p5.m_a << endl;
//
////    // 成员函数、全局函数重载
////    // 原式分别为 p1.operator+(p2)   operator+(p1,p2)
////    Person p6 = p1 + p2;
////    cout << "p6.m_a = " << p6.m_a << endl;
////    cout << "p6.m_b = " << p6.m_b << endl;
//
////    // operator+ 重载
////    Person p7 = p1 + 11;
////    cout << "p7.m_a = " << p7.m_a << endl;
//
////    Person p8 = p1 - p2;
////    cout << "p8.m_a = " << p8.m_a << endl;
//
////    Person p9 = p1 * p2;
////    cout << "p9.m_a = " << p9.m_a << endl;
//
//}
//
//
///**
// * 左移运算符重载
// * @return
// */
//class Person2 {
//    friend ostream &operator<<(ostream &cout, Person2 &p);
//
//public:
//    Person2(int a, int b) {
//        m_a = a;
//        m_b = b;
//    }
//
//private:
//    int m_a;
//    int m_b;
//};
//
//// ostream 全局只能有一个，所以要通过引用的方式传递进来
//// 重载左移运算符，输出自定义数据类型
//ostream &operator<<(ostream &cout, Person2 &p) {
//    cout << "m_a = " << p.m_a << "; m_b = " << p.m_b;
//    return cout;
//}
//
//void test02() {
//
//    Person2 p(10, 10);
//
//    cout << p << " hello " << endl;
//
//}
//
//
///**
// * 递增运算符重载
// * @return
// */
//class MyInteger {
//    // 让全局函数访问类中的私有成员变量
//    friend ostream &operator<<(ostream &cout, MyInteger myInteger);
//
//public:
//    MyInteger() {
//        m_num = 0;
//    }
//
//    // 重载前置递增
//    MyInteger &operator++() {
//        m_num++;
//        return *this;
//    }
//
//    // 重载后置递增
//    // int 代表占位参数，可以用于输出前置和后置递增
//    MyInteger operator++(int) {
//        // 记录当前结果
//        MyInteger temp = *this;
//        // 递增
//        m_num++;
//        // 将记录结果做返回
//        return temp;
//    }
//
//private:
//    int m_num;
//
//};
//
//// 先重载左移运算符
//ostream &operator<<(ostream &cout, MyInteger myInteger) {
//    cout << myInteger.m_num;
//    return cout;
//}
//
//void test03() {
//    MyInteger myInteger;
//    cout << ++myInteger << endl;
//}
//
//void test04() {
//    MyInteger myInteger;
//    cout << "myInteger = " << myInteger++ << endl;
//    cout << "myInteger = " << myInteger << endl;
//}
//
//
///**
// * 赋值运算符重载
// */
//class Person5 {
//public:
//    Person5(int age) {
//        // new int 返回的为 int*
//        m_age = new int(age);
//    }
//
//    // 堆区开辟的空间需要手动释放
////    ~Person5(){
////        if (m_age != NULL){
////            delete m_age;
////            m_age = NULL;
////        }
////    }
//
//    Person5 &operator=(Person5 &p) {
//        if (m_age != NULL) {
//            delete m_age;
//            m_age = NULL;
//        }
//        m_age = new int(*p.m_age);
//        return *this;
//    }
//
//
//    int *m_age;
//};
//
//void test05() {
//    Person5 p(10);
//
//    Person5 p2(20);
//
//    p2 = p;
//
//    cout << "p.age = " << *p.m_age << endl;
//    cout << "p2.age = " << *p2.m_age << endl;
//}
//
//
//void test05_1() {
//    int a = 1;
//    int b = 2;
//    int c = 3;
//
//    c = b = a;
//
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl;
//
//
//}
//
//void test05_2() {
//    Person5 p1(1);
//    Person5 p2(2);
//    Person5 p3(3);
//
//    p3 = p2 = p1;
//
//    cout << "p1.age = " << *p1.m_age << endl;
//    cout << "p2.age = " << *p2.m_age << endl;
//    cout << "p3.age = " << *p3.m_age << endl;
//}
//
//
///**
// * 重载关系运算符
// * @return
// */
//class Person6 {
//public:
//    Person6(string name, int age) {
//        m_name = name;
//        m_age = age;
//    }
//
//    // 重载 == 号
//    bool operator==(Person6 &p) {
//        if (this->m_age == p.m_age && this->m_name == p.m_name) {
//            return true;
//        }
//        return false;
//    }
//
//    // 重载 != 号
//    bool operator!=(Person6 &p) {
//        if (this->m_name != p.m_name || this->m_age != p.m_age) {
//            return true;
//        } else {
//            return false;
//        }
//    }
//
//    string m_name;
//    int m_age;
//
//};
//
//
//void test06() {
//    Person6 p1("zs", 10);
//    Person6 p2("ls", 20);
//    Person6 p3("zs", 10);
//
//    if (p1 == p2) {
//        cout << "相等" << endl;
//    } else {
//        cout << "不相等 " << endl;
//    }
//}
//
//void test06_2() {
//    Person6 p1("zs", 10);
//    Person6 p2("ls", 20);
//    Person6 p3("zs", 10);
//
//    if (p1 == p3) {
//        cout << "不相等" << endl;
//    } else {
//        cout << "相等 " << endl;
//    }
//}
//
//
///**
// * 函数调用运算符重载 () --> 仿函数
// * 使用起来非常像函数调用，所以叫仿函数
// */
//// 打印输出类
//class MyPrint {
//public:
//    // 重载函数调用运算符
//    void operator()(string test) {
//        cout << test << endl;
//    }
//
//};
//
//void MyPrint2(string name) {
//    cout << name << endl;
//}
//
//void test07() {
//    MyPrint myPrint;
//    myPrint("hello world");
//
//    MyPrint2("hello2");
//}
//
//
//class MyAdd {
//public:
//    int operator()(int a, int b) {
//        return a + b;
//    }
//};
//
//void test07_2() {
//    MyAdd myAdd;
//    int res = myAdd(1, 2);
//    cout << "res = " << res << endl;
//
//    // 匿名函数对象
//    cout << MyAdd()(1,2) << endl;
//
//}
//
//
//
//
//int main() {
//
////    test01();
//
////    test02();
//
////    test03();
//
////    test04();
//
////    test05();
//
////    test05_1();
//
////    test05_2();
//
////    test06();
//
////    test06_2();
//
////    test07();
//
//    test07_2();
//
//
//
//}