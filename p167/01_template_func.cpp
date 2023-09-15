//#include "iostream"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/15 9:10
//* @description:  c++中的模板： 函数模板
//*/
//
//
//// 两个整型交换的函数
//void swapInt(int &a, int &b) {
//    int temp = a;
//    a = b;
//    b = temp;
//
//    cout << "a = " << a << "; b = " << b << endl;
//}
//
//void swapDouble(double &a, double &b) {
//    double temp = a;
//    a = b;
//    b = temp;
//
//    cout << "a = " << a << "; b = " << b << endl;
//
//}
//
//void test01() {
//    int a = 10;
//    int b = 20;
//    swapInt(a, b);
//
//    double c = 1.1;
//    double d = 2.2;
//    swapDouble(c, d);
//
//}
//
///**
// * 函数模板的使用
// * 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用数据类型
// */
//template<typename T>
//void mySwap(T &a, T &b) {
//    T temp = a;
//    a = b;
//    b = temp;
//
//    cout << "a = " << a << "; b = " << b << endl;
//}
//
//void test01_2() {
//    short a = 1;
//    short b = 2;
//
//    // 1. 自动类型推导
//    mySwap(a, b);
//
//    // 2. 显式指定类型
//    int c = 10;
//    int d = 20;
//    mySwap<int>(c, d);
//}
//
//
///**
// * 函数模板使用注意事项
// * 1. 自动类型推导，必须推导出一致的数据类型T,才可以使用
// * 2. 模板必须要确定出T的数据类型，才可以使用
// */
//// 当T为包含子类的类时,用class编译器会误认为对象声明,建议统一写 typename
////template<class T>
//template<typename T>
//void mySwap2(T &a, T &b) {
//    T temp = a;
//    a = b;
//    b = temp;
//
//    cout << "a = " << a << "; b = " << b << endl;
//}
//
//void test02() {
//    int a = 10;
//    int b = 20;
//    double c = 1.1;
//
//    mySwap2(a, b);
//    // 数据类型不一致
////    mySwap2(a, c);
//
//    cout << "a = " << a << "; b = " << b << endl;
//}
//
//template<typename T>
//void func() {
//    cout << "this is func" << endl;
//}
//
//void test02_2() {
//    // 使用时没有确定出T的数据类型，无法直接使用
////    func();
//
//    // 需要指定 T 的类型
//    func<int>();
//}
//
//
///**
// * 使用模板进行数组排序
// * 从小到大
// */
//template<typename R>
//void mySwap3(R &a, R &b) {
//    R temp = a;
//    a = b;
//    b = temp;
//}
//
//template<typename T>
//void mySort(T arr[], int len) {
//    for (int i = 0; i < len; i++) {
//        int min = i;
//        for (int j = i + 1; j < len; j++) {
//            if (arr[min] > arr[j]) {
//                min = j;
//            }
//        }
//        // 交换
//        if (min != i) {
//            mySwap3(arr[min], arr[i]);
//        }
//    }
//}
//
//// 打印数组模板
//template<typename T>
//void printArr(T arr[], int len) {
//    for (int i = 0; i < len; i++) {
//        cout << "arr[" << i << "] = " << arr[i] << endl;
//    }
//}
//
//void test03() {
//
//    char arr[] = "dbeac";
//    // arr 最后是以 '/0' 结尾，所以len为6，而不是5
//    int len = sizeof(arr) / sizeof(char) - 1;
//    mySort(arr, len);
//    printArr(arr, len);
//
//}
//
//void test03_2() {
//    int arr[] = {5, 4, 3, 2, 1};
//    int len = sizeof(arr) / sizeof(int);
//    mySort(arr, len);
//    printArr(arr, len);
//}
//
//
///**
// * 普通函数与函数模板的区别
// * 普通函数调用时可以发生自动类型转换（隐式类型转换）
// * 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// * 如果利用显示指定类型的方式，可以发生隐式类型转换
// */
//// 普通函数
//int myAdd1(int a, int b) {
//    return a + b;
//}
//
//void test04_1() {
//    int a = 1;
//    int b = 2;
//    char c = '2';
////    int res = myAdd1(a, b);
//    int res = myAdd1(a, c);
//    cout << "res = " << res << endl;
//}
//
//// 函数模板 - 自动推导
//template<typename T>
//int myAdd2(T a, T b) {
//    return a + b;
//}
//
//void test04_2() {
//    int a = 1;
//    int b = 2;
//    char c = '2';
//    // 自动推导 无法推导出一致的数据类型
////    myAdd2(a,c);
//}
//
//// 函数模板 - 显示指定类型
//template<typename T>
//int myAdd3(T a, T b) {
//    return a + b;
//}
//
//void test04_3() {
//    int a = 1;
//    int b = 2;
//    char c = '2';
//    int res = myAdd3<int>(a, c);
//    cout << "res = " << res << endl;
//}
//
//
///**
// * 普通函数和函数模板的调用规则
// * 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
// * 2. 可以通过空模板参数列表来强制调用函数模板
// * 3. 函数模板也可以发生重载
// * 4. 如果函数模板可以产生更好的匹配,优先调用函数模板
// *
// * 注意： 既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
// */
////void myPrint1(int a, int b);
//void myPrint1(int a, int b) {
//    cout << "普通函数调用 " << endl;
//}
//
//template<class T>
//void myPrint1(T a, T b) {
//    cout << "模板函数调用" << endl;
//}
//
//template<class T>
//void myPrint1(T a, T b, T c) {
//    cout << "重载模板函数调用" << endl;
//}
//
//void test05() {
//    int a = 1;
//    int b = 2;
//    int c = 3;
////    myPrint1(a,b);
//
////    myPrint1<>(a,b);
//
////    myPrint1<>(a, b,c);
//
//    // 如果函数模板可以产生更好的匹配,优先调用函数模板
//    char char1 = 'a';
//    char char2 = 'b';
//    myPrint1(char1, char2);
//
//}
//
//
///**
// * 模板的局限性
// * 有些特性的数据类型，需要用具体化方式做特殊实现
// */
//class Person {
//public:
//    string m_name;
//    int m_age;
//
//    Person(string name, int age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//};
//
//// 对比两个数据是否相等
//template<typename T>
//bool myCompare(T &a, T &b) {
//    if (a == b) {
//        return true;
//    } else {
//        return false;
//    }
//}
//// 利用具体化Person的版本实现代码，具体化优先调用
//template<> bool myCompare(Person &p1, Person &p2) {
//    if (p1.m_age == p2.m_age && p1.m_name == p2.m_name) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
//void test06() {
//    int a = 1;
//    int b = 2;
//    bool flag = myCompare(a, b);
//    cout << "flag = " << flag;
//}
//
//void test06_2() {
//    Person p1("zs", 19);
//    Person p2("ls", 20);
//    Person p3("zs", 19);
//    bool flag = myCompare(p1, p3);
//    cout << "flag = " << flag << endl;
//}
//
//
//
//
//int main() {
//
////    test01();
//
////    test01_2();
//
////    test02();
//
////    test02_2();
//
////    test03();
//
////    test03_2();
//
////    test04_1();
//
////    test04_3();
//
////    test05();
//
////    test06();
//
////    test06_2();
//
//
//
//    return 0;
//}