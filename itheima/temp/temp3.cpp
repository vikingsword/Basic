//#include "iostream"
//#include "vector"
//#include "map"
//#include "list"
//#include "algorithm"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/23 22:01
//* @description:  c++ 提高编程
//*/
//
//template<typename T>
//void swapNum(T &num1, T &num2) {
//    T temp = num1;
//    num1 = num2;
//    num2 = temp;
//}
//
//void temp01() {
//    int a = 1;
//    int b = 2;
//    swapNum(a, b);
//    cout << "a = " << a << "; b = " << b << endl;
//
//    float c = 1.1;
//    float d = 2.2;
//    swapNum(c, d);
//    cout << "c = " << c << "; d = " << d << endl;
//}
//
//template<typename T>
//void func() {
//    cout << "func" << endl;
//}
//
//void temp02() {
//    func<int>();
//}
//
//
///**
// * arr sort
// */
//template<typename T>
//void printArr(T arr[], int len) {
//    cout << "arr = ";
//    for (int i = 0; i < len; ++i) {
//        cout << arr[i] << " ";
//    }
//}
//
//template<typename T>
//void mySwap(T &num1, T &num2) {
//    T temp = num1;
//    num1 = num2;
//    num2 = temp;
//}
//
//template<typename T>
//void sortArr(T arr[], int len) {
//    // 选择排序
//    for (int i = 0; i < len - 1; ++i) {
//        int min = i;
//        for (int j = i + 1; j < len; ++j) {
//            if (arr[min] > arr[j]) {
//                min = j;
//            }
//        }
//        if (i != min) {
//            mySwap(arr[i], arr[min]);
//        }
//    }
//}
//
//void temp03() {
//    int arr[] = {6, 2, 9, 5, 3, 4, 8, 1, 7};
//    int len = sizeof(arr) / sizeof(arr[0]);
//    sortArr(arr, len);
//    printArr(arr, len);
//}
//
//
///**
// * 普通函数和模板函数
// * 默认调用普通函数
// */
//void myPrint(int a, int b) {
//    cout << "normal function" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b) {
//    cout << "template function" << endl;
//}
//
//template<typename T>
//void myPrint(T a, T b, T c) {
//    cout << "overload template function" << endl;
//}
//
//void temp04() {
//    int a = 1;
//    int b = 2;
//    char c = '3';
//    int d = 4;
//    myPrint(a, c);
//    myPrint(a, b);
//    myPrint<>(a, b);
//    myPrint(a, b, d);
//}
//
//
///**
// * 具体化模板和常规模板
// */
//template<typename T>
//bool myCompare(T &a, T &b) {
//    if (a == b) {
//        return true;
//    } else {
//        return false;
//    }
//};
//
//class Person {
//public:
//    string m_name;
//    int m_age;
//};
//
//template<>
//bool myCompare(Person &p1, Person &p2) {
//    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
//void temp05() {
//    Person p1 = {"zs", 19};
//    Person p2 = {"ls", 20};
//    Person p3 = {"ls", 20};
//    bool flag1 = myCompare(p1, p2);
//    bool flag2 = myCompare(p2, p3);
//    cout << "flag1 = " << flag1 << endl;
//    cout << "flag2 = " << flag2 << endl;
//}
//
//
///**
// * class template
// */
//template<typename NameType, typename AgeType>
//class Person2 {
//public:
//    NameType m_name;
//    AgeType m_age;
//
//    Person2(NameType name, AgeType age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//    void showPerson2() {
//        cout << "name = " << this->m_name << "; age = " << this->m_age << endl;
//    }
//};
//
//void temp06() {
//    Person2 p = {"zs", 29};
//    p.showPerson2();
//
//    Person2<string, int> p2("ls", 28);
//    p2.showPerson2();
//}
//
//
///**
// * 类模板对象做函数参数
// */
//template<typename NameType, typename AgeType>
//class Person3 {
//public:
//    NameType m_name;
//    AgeType m_age;
//
//    Person3(NameType name, AgeType age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//
//    void showPerson3() {
//        cout << "name = " << this->m_name << "; age = " << this->m_age << endl;
//    }
//};
//
//void printPerson1(Person3<string, int> &p) {
//    p.showPerson3();
//}
//
//// 参数模板化
//template<typename T, typename R>
//void printPerson2(Person3<T, R> &p) {
//    p.showPerson3();
//    cout << "T的类型为： " << typeid(T).name() << endl;
//    cout << "R的类型为：" << typeid(R).name() << endl;
//}
//
//// 类模板化
//template<typename T>
//void printPerson3(T &p) {
//    cout << "T的类型为： " << typeid(T).name() << endl;
//    p.showPerson3();
//}
//
//void temp07() {
//    Person3<string, int> p("zs", 28);
//    printPerson1(p);
//    cout << "---------" << endl;
//
//    printPerson2(p);
//    cout << "-------------" << endl;
//
//    printPerson3(p);
//}
//
//
///**
// * 虚析构和纯虚析构
// * 可以解决父类指针释放子类对象
// * 都需要有具体的函数实现
// * 如果是纯虚析构，该类属于抽象类，无法实例化对象
// */
//class Animal {
//public:
//    Animal() {
//        cout << "Animal 构造函数调用" << endl;
//    }
//
//    // 纯虚函数
//    virtual void yell() = 0;
//
//    // 纯虚析构
//    virtual ~Animal() = 0;
//
//};
//
//Animal::~Animal() {
//    cout << "Animal 纯虚析构函数调用！" << endl;
//}
//
////和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
//class Cat : public Animal {
//public:
//    Cat(string name) {
//        cout << "Cat 构造函数调用" << endl;
//        this->m_name = new string(name);
//    }
//
//    virtual void yell() {
//        cout << *m_name << "cat yell" << endl;
//    }
//
//    ~Cat() {
//        cout << "cat 析构函数调用" << endl;
//        if (this->m_name != NULL) {
//            delete m_name;
//            m_name = NULL;
//        }
//    }
//
//    string *m_name;
//};
//
//class Dog : public Animal {
//public:
//    Dog(string name) : m_name(name) {}
//
//    string m_name;
//};
//
//void temp08() {
//    Animal *animal = new Cat("Tom");
//    animal->yell();
//
//    delete animal;
//}
//
//
///**
// * 多态案例三-电脑组装
// */
//class CPU {
//public:
//    virtual void calculate() = 0;
//};
//
//class VideoCard {
//public:
//    virtual void display() = 0;
//};
//
//class Memory {
//public:
//    virtual void storage() = 0;
//};
//
//class Computer {
//private:
//    CPU *m_cpu;
//    VideoCard *m_videoCard;
//    Memory *m_memory;
//public:
//    Computer(CPU *cpu, VideoCard *videoCard, Memory *memory) {
//        m_cpu = cpu;
//        m_videoCard = videoCard;
//        m_memory = memory;
//    }
//
//    void doWork() {
//        m_cpu->calculate();
//        m_memory->storage();
//        m_videoCard->display();
//    }
//
//    ~Computer() {
//        if (m_cpu != NULL) {
//            delete m_cpu;
//            m_cpu = NULL;
//        }
//        if (m_videoCard != NULL) {
//            delete m_videoCard;
//            m_videoCard = NULL;
//        }
//        if (m_memory != NULL) {
//            delete m_memory;
//            m_memory = NULL;
//        }
//    }
//};
//
//class IntelCPU : public CPU {
//public:
//    virtual void calculate() {
//        cout << "Intel的CPU开始计算了！" << endl;
//    }
//};
//
//class IntelVideoCard : public VideoCard {
//public:
//    virtual void display() {
//        cout << "Intel的显卡开始显示了！" << endl;
//    }
//};
//
//class IntelMemory : public Memory {
//public:
//    virtual void storage() {
//        cout << "Intel的内存条开始存储了！" << endl;
//    }
//};
//
////Lenovo厂商
//class LenovoCPU : public CPU {
//public:
//    virtual void calculate() {
//        cout << "Lenovo的CPU开始计算了！" << endl;
//    }
//};
//
//class LenovoVideoCard : public VideoCard {
//public:
//    virtual void display() {
//        cout << "Lenovo的显卡开始显示了！" << endl;
//    }
//};
//
//class LenovoMemory : public Memory {
//public:
//    virtual void storage() {
//        cout << "Lenovo的内存条开始存储了！" << endl;
//    }
//};
//
//void temp09() {
//    CPU * intelCpu = new IntelCPU;
//    VideoCard * intelCard = new IntelVideoCard;
//    Memory * intelMem = new IntelMemory;
//
//    cout << "第一台电脑开始工作：" << endl;
//    //创建第一台电脑
//    Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
//    computer1->doWork();
//    delete computer1;
//
//    cout << "-----------------------" << endl;
//    cout << "第二台电脑开始工作：" << endl;
//    //第二台电脑组装
//    Computer * computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);;
//    computer2->doWork();
//    delete computer2;
//
//    cout << "-----------------------" << endl;
//    cout << "第三台电脑开始工作：" << endl;
//    //第三台电脑组装
//    Computer * computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);;
//    computer3->doWork();
//    delete computer3;
//}
//
//class Father{
//public:
//    virtual void yell() = 0;
//};
//class Son1 :public Father{
//    void yell() override {
//        cout << "son1" << endl;
//    }
//};
//class Son2 : public Father {
//    void yell() override {
//        cout << "son2" << endl;
//    }
//};
//void temp10() {
//    Father *f = new Son1();
//    f->yell();
//    f = new Son2();
//    f->yell();
//}
//
//
//
//void temp() {}
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
//    temp10();
//
//
//    return 0;
//}