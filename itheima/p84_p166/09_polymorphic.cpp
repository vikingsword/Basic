//#include "iostream"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/11 10:15
//* @description:  多态
//*/
//
///**
// * 动态多态满足条件：
// * 1、继承关系
// * 2、子类重写父类的虚函数
// * 动态多态的使用：
// * 父类的引用或者指针指向子类的对象：
// *      doYell(Animal &animal)  -->  Animal &animal = cat;
// *
// */
//class Animal{
//public:
//    virtual void yell(){
//        cout << "animal yell" << endl;
//    }
//};
//class Dog : public Animal{
//public:
//    // 重写 函数返回值类型 函数名 参数列表 完全相同
//    void yell(){
//        cout << "dog yell" << endl;
//    }
//};
//class Cat : public Animal{
//public:
//    void yell(){
//        cout << "cat yell" << endl;
//    }
//};
//void doYell(Animal &animal){
//    animal.yell();
//}
//void test01(){
//    Dog dog;
//    doYell(dog);
//
//    Cat cat;
//    doYell(cat);
//
//}
//
//
///**
// * 用多态的写法实现计算器(Calculator)
// * 开发中提倡开闭原则：
// * 对拓展进行开放，对修改进行关闭
// * @return
// */
//// 原始未使用多态的计算器
//class Calculator{
//public:
//    int m_num1;
//    int m_num2;
//
//    int getResult(string opera) {
//        if (opera  == "+") {
//            return m_num1 + m_num2;
//        } else if (opera == "-"){
//            return m_num1 - m_num2;
//        } else if (opera == "*") {
//            return m_num1 * m_num2;
//        } else if (opera == "/") {
//            return m_num1 / m_num2;
//        }
//    }
//
//    Calculator(int num1, int num2){
//        m_num1 = num1;
//        m_num2 = num2;
//    }
//};
//void test02(){
//    Calculator calculator(2,2);
//    int res = calculator.getResult("*");
//    cout << "res = " << res << endl;
//}
//
//// 使用多态的计算器
//// 实现计算抽象类
//class AbstractCalculator{
//public:
//    virtual int getResult(){
//
//    }
//    int m_num1;
//    int m_num2;
//};
//class AddCalculator : public AbstractCalculator{
//public:
//    int getResult(){
//        return m_num1 + m_num2;
//    }
//};
//class SubCalculator : public AbstractCalculator{
//public:
//    int getResult(){
//        return m_num1 - m_num2;
//    }
//};
//class MultiplicationCalculator : public AbstractCalculator{
//public:
//    int getResult(){
//        return m_num1 * m_num2;
//    }
//};
//class DivisionCalculator : public AbstractCalculator{
//public:
//    int getResult(){
//        return m_num1 / m_num2;
//    }
//};
//
//void test03(){
//
//    // +
//    AbstractCalculator * abc = new AddCalculator;
//    abc->m_num1 = 10;
//    abc->m_num2 = 10;
//
//    cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
//    delete abc;
//
//    // -
//    abc = new SubCalculator;
//    abc->m_num1 = 2;
//    abc->m_num2 = 1;
//    cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
//
//    // *
//    abc = new MultiplicationCalculator;
//    abc->m_num1 = 10;
//    abc->m_num2 = 10;
//    cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
//
//    // /
//    abc = new DivisionCalculator;
//    abc->m_num1 = 10;
//    abc->m_num2 = 10;
//    cout << abc->m_num1 << " / " << abc->m_num2 << " = " << abc->getResult() << endl;
//
//}
//
//
///**
// * 纯虚函数和抽象类
// * @return
// */
//class Base{
//public:
//    // 纯虚函数
//    // 只要有一个纯虚函数，这个类称为抽象类
//    // 抽象类的子类必须重写父类的纯虚函数，否则也为抽象类
//    virtual void func() = 0;
//};
//class Son : public Base{
//public:
//    virtual void func() {
//        cout << "123" << endl;
//    }
//};
//
//void test04(){
//
//    Base * base = new Son;
//    base->func();
//
//}
//
//
///**
// * 多态案例二： 制作饮品
// * @return
// */
//class AbstractMakingDrink {
//public:
//    // 煮水
//    virtual void boiling() = 0;
//    // 冲泡
//    virtual void brewing() = 0;
//    // 倒入杯子中
//    virtual void pourIntoCup() = 0;
//    // 加入辅料
//    virtual void putSomething() = 0;
//
//    void makeDrink(){
//        boiling();
//        brewing();
//        pourIntoCup();
//        putSomething();
//    }
//};
//// make coffee
//class Coffee : public AbstractMakingDrink{
//public:
//    // 煮水
//    virtual void boiling() {
//        cout << "boiling water" << endl;
//    }
//    // 冲泡
//    virtual void brewing() {
//        cout << "brewing coffee" << endl;
//    }
//    // 倒入杯子中
//    virtual void pourIntoCup() {
//        cout << "pour to java" << endl;
//    }
//    // 加入辅料
//    virtual void putSomething() {
//        cout << "add trick" << endl;
//    }
//};
//// make tea
//class Tea : public AbstractMakingDrink {
//    // 煮水
//    virtual void boiling() {
//        cout << "boiling water" << endl;
//    }
//    // 冲泡
//    virtual void brewing() {
//        cout << "brewing tea" << endl;
//    }
//    // 倒入杯子中
//    virtual void pourIntoCup() {
//        cout << "pour into tea cup " << endl;
//    }
//    // 加入辅料
//    virtual void putSomething() {
//        cout << "add lemon" << endl;
//    }
//};
//// 制作函数
//void doWork(AbstractMakingDrink * abs){
//    abs->makeDrink();
//    delete abs;
//}
//
//void test05() {
//    doWork(new Coffee);
////    doWork(new Tea);
//}
//
//
///**
// * 虚析构和纯虚析构
// * @return
// */
//class Animal2 {
//public:
//    // 纯虚函数
//    virtual void yell() = 0;
//
//    Animal2() {
//        cout << "create animal " << endl;
//    }
//    // 利用虚析构可以解决 父类指针释放子类对象不干净的问题
////    virtual ~Animal2(){
////        cout << "kill animal" << endl;
////    }
//    // 或者直接写纯虚析构
//    // 纯虚析构之后这个类也属于抽象类，无法实例化对象
//    virtual ~Animal2() = 0;
//};
//// 纯虚析构一定要有具体实现
//Animal2::~Animal2() {
//    cout << "animal2 的纯虚析构" << endl;
//}
//class Cat2 : public Animal2{
//public:
//    Cat2(string name) {
//        m_name = new string(name);
//    }
//    void yell() {
//        cout << *m_name <<" cat yell " << endl;
//    }
//    ~Cat2(){
//        if (m_name != NULL) {
//            // 父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏
//            // 父类引用指向之类对象，无法调用子类的析构函数，导致内存泄漏
//            cout << "kill cat" << endl;
//            delete m_name;
//            m_name = NULL;
//        }
//    }
//
//    string *m_name;
//};
//void test06() {
//    Animal2 * animal = new Cat2("tom");
//    animal->yell();
//    delete animal;
//}
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
//    test06();
//
//
//
//
//    return 0;
//}