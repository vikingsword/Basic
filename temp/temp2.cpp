//#include "iostream"
//#include "vector"
//#include "algorithm"
//#include "fstream"
//
//using namespace std;
//
//
//void temp01() {
//
//    int arr[] = {1, 2, 3, 4, 5, 6};
//    int *p = arr;
//    int len = sizeof(arr) / sizeof(arr[0]);
//    for (int i = 0; i < len; i++) {
//        cout << *p++ << endl;
//    }
//    cout << len << endl;
//
//
//    int arr2[2][3] = {
//            {1, 2, 3},
//            {4, 5, 6},
//    };
//
//}
//
//
//void showValue(const int &v) {
//    cout << v << endl;
//}
//
//void temp02() {
//
//    const int &ref = 1;
//    showValue(ref);
//
//    cout << ref << endl;
//}
//
//
//int &test03(int &v) {
//    v++;
//    cout << v << endl;
//    return v;
//}
//
//void temp03() {
//    int a = 1;
//    int &ref = a;
//    int &temp = test03(ref);
//    cout << temp << endl;
//}
//
//
////函数重载注意事项
////1、引用作为重载条件
//void func(int &a) {
//    cout << "func (int &a) 调用 " << endl;
//}
//void func(const int &a) {
//    cout << "func (const int &a) 调用 " << endl;
//}
////2、函数重载碰到函数默认参数
//void func2(int a, int b = 10) {
//    cout << "func2(int a, int b = 10) 调用" << endl;
//}
//void func2(int a) {
//    cout << "func2(int a) 调用" << endl;
//}
//void temp04() {
//    int a = 10;
//    const int b = 20;
//    int c = 30;
////    func(a);
////    func(b);
//    func2(a, c);
////    func2(static_cast<int>(3));
//    //func2(10); //碰到默认参数产生歧义，需要避免
//}
//
//class Animal{
//public:
//    string m_name;
//    int m_age;
//    virtual void yell() {}
//};
//class Dog : public Animal{
//public:
//    void yell(){
//        cout << "dog yell" << endl;
//    }
//};
//class Cat : public Animal{
//public:
//    void yell() {
//        cout << "cat yell" << endl;
//    }
//};
//void temp05() {
//    Dog dog;
//    dog.yell();
//    Cat cat;
//    cat.yell();
//}
//
//const double PI = 3.14;
//class Circle{
//public:
//    int m_r;
//    double getPerimeter() {
//        return 2 * PI * this->m_r;
//    }
//};
//void temp06() {
//    Circle c1;
//    c1.m_r = 10;
//    double len = c1.getPerimeter();
//    cout << "len = " << len << endl;
//}
//
//class Student {
//private:
//    string m_name;
//    string m_id;
//
//public:
//    void set_name(string name) {
//        this->m_name = name;
//    }
//    void set_id(string id) {
//        this->m_id = id;
//    }
//    void show_name() {
//        cout << this->m_name << endl;
//    }
//    void show_id() {
//        cout << this->m_id << endl;
//    }
//};
//void temp07() {
//    Student s;
//    s.set_name("zs");
//    s.set_id("a1");
//    s.show_name();
//    s.show_id();
//}
//
//class Person{
//public:
//    static int m_a;
//private:
//    static int m_b;
//};
//int Person::m_a = 10;
//int Person::m_b = 20;
//void temp08() {
//    Person p;
//    p.m_a = 100;
//    cout << "p.m_a = " << p.m_a << endl;
//
//    Person p2;
//    p2.m_a = 200;
//    cout << "p2.m_a = " << p2.m_a << endl;
//
//    cout << "Person::m_a = " << Person::m_a << endl;
//}
//
//
//class BasePage{
//public:
//    void headers() {
//        cout << "header" << endl;
//    }
//    void footer() {
//        cout << "footer" << endl;
//    }
//};
//class CPP : public BasePage{
//public:
//    void content() {
//        cout << "cpp content" << endl;
//    }
//};
//class Java : public BasePage{
//public:
//    void content() {
//        cout << "java content" << endl;
//    }
//};
//void temp09() {
//    CPP p;
//    p.headers();
//    p.content();
//    p.footer();
//
//    cout << "------------" << endl;
//
//    Java j;
//    j.headers();
//    j.content();
//    j.footer();
//}
//
//
//class Father {
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;
//};
//class Son1 : public Father{
//public:
//    void fun() {
//        this->m_a = 1;
//        cout << m_a << endl;
//    }
//    void fun2() {
//        this->m_b = 2;
//        cout << m_b << endl;
//    }
//};
//void temp10() {
//    Son1 s;
//    s.fun();
//    s.fun2();
//}
//
//
//class Father2 {
//public:
//    int m_a;
//    static int m_b;
//    Father2() {
//        this->m_a = 10;
//    }
//};
//int Father2::m_b = 10;
//class Son2 : public Father2{
//public:
//    int m_a;
//    static int m_b;
//    Son2() {
//        this->m_a = 100;
//    }
//};
//int Son2::m_b = 100;
//void temp11() {
//    Son2 s;
//    cout << s.m_a << endl;
//    cout << s.Father2::m_a << endl;
//
//    cout << "----------" << endl;
//
//    Son2 s2;
//    cout << s2.m_b << endl;
//    cout << s2.Father2::m_b << endl;
//}
//
//// 菱形继承
//class Animal2{
//public:
//    int m_age;
//};
//class Sheep : virtual public Animal2{};
//class Camel : virtual public Animal2{};
//class SC : public Sheep, public Camel {};
//
//void temp12() {
//    SC sc;
//    sc.Sheep::m_age = 10;
//    sc.Camel::m_age = 20;
//
//    // 当你执行 sc.Sheep::m_age = 10; 时，实际上是修改了这个共享的 Animal2 子对象的 m_age 成员，这个修改会影响到所有虚继承自 Animal2 的类，
//    // 包括 Camel。因此，sc.Sheep::m_age 和 sc.Camel::m_age 都是 20，因为它们共享同一个 Animal2 子对象。
//    // 同样地，sc.m_age 直接访问共享的 Animal2 子对象，这个对象的 m_age 成员已经被修改为 20，所以 sc.m_age 也是 20。
//    cout << "sc.Sheep::m_age: " << sc.Sheep::m_age << endl;
//    cout << "sc.Camel::m_age: " << sc.Camel::m_age << endl;
//    cout << "sc.m_age: " << sc.m_age << endl;
//}
//
//class Animal3{
//public:
//    virtual void yell() {
//        cout << "animal yell" << endl;
//    }
//};
//class Dog3 : public Animal3{
//public:
//    void yell() {
//        cout << "dog yell" << endl;
//    }
//};
//class Cat3 : public Animal3{
//public:
//    void yell() {
//        cout << "cat yell" << endl;
//    }
//};
//void doYell(Animal3 &animal) {
//    animal.yell();
//}
//void temp13() {
//    Dog3 dog;
//    doYell(dog);
//
//    Cat3 cat;
//    doYell(cat);
//}
//
//// 多态实现计算器
//class AbstractCalculator {
//public:
//    virtual int getResult() = 0;
//    int m_a;
//    int m_b;
//};
//class AddCalculator : public AbstractCalculator{
//public:
//    int getResult() {
//        return m_a + m_b;
//    }
//};
//class SubCalculator : public AbstractCalculator{
//public:
//    int getResult() {
//        return m_a - m_b;
//    }
//};
//void temp14() {
//    AbstractCalculator *abs = new AddCalculator;
//    abs->m_a = 10;
//    abs->m_b = 20;
//    int res = abs->getResult();
//    cout << "res = " << res << endl;
//
//    abs = new SubCalculator;
//    abs->m_a = 30;
//    abs->m_b = 10;
//    res = abs->getResult();
//    cout << "res = " << res << endl;
//
//    delete abs;
//}
//
//
//// 多态案例 ： 制作饮品
//class AbstractDrinking {
//public:
//    virtual void boiling() = 0;
//    virtual void brewing() = 0;
//    virtual void putCup() = 0;
//    virtual void putSomething() = 0;
//    void makeDrink() {
//        boiling();
//        brewing();
//        putCup();
//        putSomething();
//    }
//};
//class Coffee : public AbstractDrinking {
//public:
//    void boiling(){
//       cout << "boiling coffee" << endl;
//    }
//    void brewing() {
//        cout << "brewing coffee" << endl;
//    }
//    void putCup() {
//        cout << "put in java" << endl;
//    }
//    void putSomething() {
//        cout << "put sugar" << endl;
//    }
//};
//class Tea : public AbstractDrinking {
//public:
//    void boiling(){
//        cout << "boiling tea" << endl;
//    }
//    void brewing() {
//        cout << "brewing tea" << endl;
//    }
//    void putCup() {
//        cout << "put in cup" << endl;
//    }
//    void putSomething() {
//        cout << "put berry" << endl;
//    }
//};
//// 业务函数
//void doDrink(AbstractDrinking *ad) {
//    ad->makeDrink();
//    delete ad;
//}
//void temp15() {
//
//    AbstractDrinking *ad = new Coffee;
//    doDrink(ad);
//
//    cout << "-----------" << endl;
//    doDrink(new Tea);
//
//}
//
//
///**
// * 文件操作
// */
//void temp16() {
//    ofstream ofs("./temp/temp.txt", ios::binary|ios::app);
//    cout << "input your content: ";
//    string content;
//    getline(cin, content);
//    ofs << content << "\n";
//
//}
//void temp17() {
//    ofstream ofs("./temp/temp.txt", ios::out|ios::app);
//    if (!ofs.is_open()) {
//        cerr << "cannot open this file " << endl;
//    }
//    while (true) {
//        cout << "please input your content : " ;
//        string input;
//        cin >> input;
//        getline(cin, input);
//        if (input == "exit") {
//            break;
//        }
//        ofs << input << endl;
//    }
//    ofs.close();
//}
//
//void temp18() {
//    ifstream ifs;
//    ifs.open("./temp/temp.txt", ios::in);
//    if (!ifs.is_open()) {
//        cout << "can't open file" << endl;
//        return;
//    }
//    char c;
//    while ((c = ifs.get()) != EOF) {
//        cout << c;
//    }
//    ifs.close();
//
//}
//
//class Person2{
//public:
//    char m_name[64];
//    int m_age;
////    Person2(string name, int age) {
////        this->m_age = age;
////        this->m_name = name;
////    }
//};
//void temp19() {
//    ofstream ofs("./temp/temp.txt", ios::out|ios::binary);
//    Person2 p = {"zs", 19};
//    ofs.write((const char *) &p, sizeof (p));
//    ofs.close();
//}
//void temp20() {
//    ifstream ifs("./temp/temp.txt", ios::in|ios::binary);
//    Person2 p;
//    ifs.read((char *)&p, sizeof (p));
//    cout << "name: " << p.m_name << "; age = " << p.m_age << endl;
//
//    ifs.close();
//}
//
//int main() {
//
////    temp01();
////    temp02();
////    temp03();
////    temp04();
////    temp05();
////    temp06();
////    temp07();
////    temp08();
////    temp09();
////    temp10();
////    temp11();
////    temp12();
////    temp13();
////    temp14();
////    temp15();
////    temp16();
////    temp17();
////    temp18();
////    temp19();
//    temp20();
//
//
//    return 0;
//
//}