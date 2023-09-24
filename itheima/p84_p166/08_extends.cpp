//#include "iostream"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/10 19:01
//* @description: 继承
//*/
//
//// java 页面
//class Java {
//public:
//    void headers() {
//        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//    }
//
//    void footer() {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    }
//
//    void left() {
//        cout << "Java,Python,C++...(公共分类列表)" << endl;
//    }
//
//    void content() {
//        cout << "JAVA学科视频" << endl;
//    }
//};
//
////Python页面
//class Python {
//public:
//    void headers() {
//        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//    }
//
//    void footer() {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    }
//
//    void left() {
//        cout << "Java,Python,C++...(公共分类列表)" << endl;
//    }
//
//    void content() {
//        cout << "Python学科视频" << endl;
//    }
//};
//
////C++页面
//class CPP {
//public:
//    void headers() {
//        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//    }
//
//    void footer() {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    }
//
//    void left() {
//        cout << "Java,Python,C++...(公共分类列表)" << endl;
//    }
//
//    void content() {
//        cout << "C++学科视频" << endl;
//    }
//};
//
//void test01() {
//
//    //Java页面
//    cout << "Java下载视频页面如下： " << endl;
//    Java ja;
//    ja.headers();
//    ja.footer();
//    ja.left();
//    ja.content();
//    cout << "--------------------" << endl;
//
//    //Python页面
//    cout << "Python下载视频页面如下： " << endl;
//    Python py;
//    py.headers();
//    py.footer();
//    py.left();
//    py.content();
//    cout << "--------------------" << endl;
//
//    //C++页面
//    cout << "C++下载视频页面如下： " << endl;
//    CPP cp;
//    cp.headers();
//    cp.footer();
//    cp.left();
//    cp.content();
//    cout << "--------------------" << endl;
//
//
//}
//
///**
// * 继承的好处：==可以减少重复的代码==
// * class A : public B;
// * A 类称为子类 或 派生类
// * B 类称为父类 或 基类
// */
//// 继承实现页面
//// 公共页面类
//class BasePage {
//public:
//    void headers() {
//        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//    }
//
//    void footer() {
//        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//    }
//
//    void left() {
//        cout << "Java,Python,C++...(公共分类列表)" << endl;
//    }
//};
//
//class Java2 : public BasePage{
//public:
//    void content() {
//        cout << "JAVA学科视频" << endl;
//    }
//
//};
////Python页面
//class Python2 : public BasePage
//{
//public:
//    void content()
//    {
//        cout << "Python学科视频" << endl;
//    }
//};
////C++页面
//class CPP2 : public BasePage
//{
//public:
//    void content()
//    {
//        cout << "C++学科视频" << endl;
//    }
//};
//
//void test02(){
//
//    //Java页面
//    cout << "Java下载视频页面如下： " << endl;
//    Java2 ja;
//    ja.headers();
//    ja.footer();
//    ja.left();
//    ja.content();
//    cout << "--------------------" << endl;
//
//    //Python页面
//    cout << "Python下载视频页面如下： " << endl;
//    Python2 py;
//    py.headers();
//    py.footer();
//    py.left();
//    py.content();
//    cout << "--------------------" << endl;
//
//    //C++页面
//    cout << "C++下载视频页面如下： " << endl;
//    CPP2 cp;
//    cp.headers();
//    cp.footer();
//    cp.left();
//    cp.content();
//
//}
//
//
///**
// * 继承方式
// * public / protected / private
// * @return
// */
//// 公共继承
//class Father1{
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;
//};
//
//class Son1 : public Father1{
//public:
//    void func(){
//        m_a = 10;
//        m_b = 10;
////        m_c = 10;
//    }
//};
//
//void test03_1() {
//    Son1 s1;
//    cout << s1.m_a << endl;
//    // son1 中 m_b 是受保护的权限，类外不能访问
////    s1.m_b;
//}
//
//// 保护继承
//class Father2 {
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;
//};
//
//class Son2 : protected Father2{
//public:
//    void func(){
//        // 父类中公共成员，到子类中为保护的成员
//        m_a = 100;
//        m_b = 100;
//        // 父类中的私有成员，子类访问不到
////        m_c = 100;
//    }
//};
//
//void test03_2() {
//    Son2 s2;
//    // 在 son2 中 m_a 和 m_b 变为保护权限，无法再类外访问
////    s2.m_a = 1;
////    s2.m_b = 1;
//}
//
//// 私有继承
//class Father3{
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;
//};
//
//class Son3 : private Father3{
//public:
//    void fun(){
//        // 父类中公共和保护的成员变量，到子类中变为私有的成员变量
//        m_a = 100;
//        m_b = 100;
////        m_c = 100;
//    }
//};
//
//class GrandSon3 : public Son3{
//public:
//    void func(){
////        m_a = 100;
////        m_b = 100;
//    }
//};
//
//void test03_3(){
//    Son3 s3;
//    // 私有成员更无法在类外访问
////    s3.m_a;
////    s3.m_b;
//}
//
//
///**
// * 继承中的对象模型
// * @return
// */
//class Base{
//public:
//    int m_a;
//protected:
//    int m_b;
//private:
//    int m_c;
//};
//
//class SubBase : public Base{
//public:
//    int m_d;
//};
//
//void test04_4() {
//    // 父类中所有非静态的成员属性都会被子类继承下去p
//    cout << "sizeof(subBase) = " << sizeof(SubBase) << endl;
//}
//
//
///**
// * 继承中的构造和析构的顺序
// * @return
// */
//class Base2{
//public:
//    Base2(){
//        cout << "base2的构造函数" << endl;
//    }
//    ~Base2(){
//        cout << "base2的析构函数" << endl;
//    }
//};
//
//class SubBase2 : public Base2{
//public:
//    SubBase2(){
//        cout << "SubBase2的构造函数" << endl;
//    }
//    ~SubBase2(){
//        cout << "SubBase2的析构函数" << endl;
//    }
//};
//
//void test05(){
//    SubBase2 s;
//};
//
//
///**
// * 继承同名成员处理方式
// * @return
// */
//class Base3{
//public:
//    Base3(){
//        m_a = 100;
//    }
//
//    void func1(){
//        cout << "this is father " << endl;
//    }
//
//    int m_a;
//};
//
//class SubBase3 : public Base3{
//public:
//    SubBase3(){
//        m_a = 200;
//    }
//    int m_a;
//
//    void func1(){
//        cout << "this is son " << endl;
//    }
//};
//
//void test06(){
//
////    SubBase3 s;
////    cout << "Son s.m_a = " << s.m_a << endl;
////
////    // 子类访问父类中的同名成员需要加作用域
////    cout << "Base m_a = " << s.Base3::m_a << endl;
//
//    SubBase3 s;
////    s.func1();
//    s.Base3::func1();
//
//}
//
//
///**
// * 继承同名静态成员处理方式
// * @return
// */
//class Base4{
//public:
//    static int m_a;
//
//    static void func1(){
//        cout << "father func1 " << endl;
//    }
//};
//int Base4::m_a = 100;
//
//class SubBase4 : public Base4{
//public:
//    static int m_a;
//
//    static void func1(){
//        cout << "son func1" << endl;
//    }
//};
//int SubBase4::m_a = 200;
//
//void test07() {
//
//////     同名静态成员属性
//////     通过对象方式访问
////    SubBase4 s;
////    cout << "s.m_a = " << s.m_a << endl;
////    cout << "s.Base4::m_a = " << s.Base4::m_a << endl;
//
////    // 通过类名方式访问
////    cout << "SubBase4::m_a = " << SubBase4::m_a << endl;
////    // 第一个 :: 表示通过类名的方式访问，第二个 :: 表示访问父类作用域下
////    cout << "Base4::m_a = " << SubBase4::Base4::m_a << endl;
//
////    // 同名静态成员函数
////    // 通过对象的方式访问
////    SubBase4 s;
//////    s.func1();
////    s.Base4::func1();
//
////    // 通过类名的方式访问
//////    SubBase4::func1();
////    SubBase4::Base4::func1();
//
//}
//
//
///**
// * 多继承
// * @return
// */
//class FatherBase1{
//public:
//    int m_a;
//    FatherBase1(){
//        m_a = 100;
//    }
//};
//class FatherBase2{
//public:
//    int m_a;
//    FatherBase2(){
//        m_a = 200;
//    }
//};
//class Son4 : public FatherBase1, public FatherBase2{
//public:
//    int m_a;
//    int m_d;
//    Son4(){
//        m_a = 300;
//        m_d = 400;
//    }
//};
//void test08(){
//    Son4 s;
//    cout << "sizeof(Son4) = " << sizeof(Son4) << endl;
//
//    cout << "Son4 m_a = " << s.m_a << endl;
//
//    cout << "Father1 m_a = " << s.FatherBase1::m_a << endl;
//    cout << "Father2 m_a = " << s.FatherBase2::m_a << endl;
//
//}
//
//
///**
// * 菱形继承
// * 虚继承会导致产生两个相同成员，造成资源浪费
// * 利用虚继承可以解决菱形继承的问题 virtual
// * Animal 称为虚基类
// * @return
// */
//class Animal{
//public:
//    int m_age;
//};
//class Sheep : virtual public Animal{
//
//};
//class Camel : virtual public Animal{
//
//};
//class Alpaca : public Sheep, public Camel{
//
//};
//
//void test09(){
//    Alpaca alpaca;
//    alpaca.Sheep::m_age = 10;
//    alpaca.Camel::m_age = 20;
//
//    cout <<  "alpaca age from sheep is " << alpaca.Sheep::m_age << endl;
//    cout <<  "alpaca age from camel is " << alpaca.Camel::m_age << endl;
//
//    cout << "alpaca age is " << alpaca.m_age << endl;
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
////    test04_4();
//
////    test05();
//
////    test06();
//
////    test07();
//
////    test08();
//
//    test09();
//
//
//
//
//    return 0;
//}