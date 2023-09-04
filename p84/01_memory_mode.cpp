//#include "iostream"
//using namespace std;
//
//int g_a = 10;
//int g_b = 10;
//
//// const 修饰的全局变量 -> 全局常量
//const int c_g_a = 10;
//const int c_g_b = 10;
//
//// 不要返回局部变量的地址
//int * func(){
//    int a = 10;
//    return &a;
//}
//
//int * func2(){
//    int * p = new int(10);
//    return p;
//}
//
//void * func3(){
//    int * arr = new int[10];
//    for (int i=0; i < 10; i++){
//        arr[i] = i + 100;
//    }
//    for (int i=0; i < 10; i++){
//        cout << arr[i] << "\t";
//    }
//    cout << endl;
//    // 释放数组的时候要加 []
//    delete [] arr;
//}
//
//
////1. 值传递
//void mySwap01(int a, int b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
////2. 地址传递
//void mySwap02(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
////3. 引用传递
//void mySwap03(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//int& func4(){
//    int a = 10;
//    return a;
//}
//// 函数调用作为左值
//int & func5(){
//    // 放在全局区，结束后由系统释放
//    static int a = 10;
//    return a;
//}
//
////引用使用的场景，通常用来修饰形参
//void showValue(const int& v) {
//    //v += 10;
//    cout << v << endl;
//}
//
//int main(){
//
////    /**
////     *  C++中在程序运行前分为全局区和代码区
////     * 代码区特点是共享和只读
////     * 全局区中存放全局变量、静态变量、常量
////     * 常量区中存放 const修饰的全局常量  和 字符串常量
////     */
////    // 全局区
////    // 全局变量、静态变量、常量
////    // 创建普通局部变量
////    int a = 10;
////    int b = 10;
////
////    cout << "局部变量 a 的地址为： " << (long long)&a << endl;
////    cout << "局部变量 b 的地址为： " << (long long)&b << endl;
////
////    cout << "全局变量 g_a 的地址为： " << (long long)&g_a << endl;
////    cout << "全局变量 g_b 的地址为： " << (long long)&g_b << endl;
////
////    // 静态变量
////    static int s_a = 10;
////    static int s_b = 10;
////    cout << "静态变量 s_a 的地址为： " << (long long)&s_a << endl;
////    cout << "静态变量 s_b 的地址为： " << (long long)&s_b << endl;
////
////    // 字符串常量
////    cout << "字符串常量地址： " << (long long)&"hello" << endl;
////    cout << "字符串常量地址： " << (long long)&"world" << endl;
////
////    // const 修饰的全局变量 -> 全局常量
////    cout << "const 修饰的全局常量地址： " << (long long)&c_g_a << endl;
////    cout << "const 修饰的全局常量地址： " << (long long)&c_g_b << endl;
////
////    // const 修饰的局部变量
////    const int c_l_a = 10;
////    const int c_l_b = 10;
////    cout << "const 修饰的局部常量地址： " << (long long)&c_l_a << endl;
////    cout << "const 修饰的局部常量地址： " << (long long)&c_l_b << endl;
//
//
////    // 不要返回局部变量地址
////    int * p = func();
////    cout << *p << endl;
////    cout << *p << endl;
//
//
////    /**
////     * 由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
////     * 在C++中主要利用new在堆区开辟内存
////     */
////    int *p = func2();
////    cout << *p << endl;
////    delete p;
//////    cout << *p << endl;
////
////    func3();
//
//
////    /**
////     * 引用必须初始化
////     * 引用在初始化后，不可以改变
////     */
////    int a = 10;
////    int c = 10;
////    // 创建 a 的引用 b
////    int &b = a;
////    cout << "a = " << a << endl;
////    cout << "b = " << b << endl;
////
////    b = 100;
////    cout << "a = " << a << endl;
////    cout << "b = " << b << endl;
////
////    // 引用不可更改
//////    int &b = c;
//
//
////    /**
////     * 通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单
////     */
////    int a = 10;
////    int b = 20;
//////    mySwap01(a,b);
//////    mySwap02(&a,&b);
////    mySwap03(a, b);
////    cout << "a = " << a << "; b = " << b << endl;
//
//
////    /**
////     * 引用做函数返回值
////     * 注意：**不要返回局部变量引用**
////     * 用法：函数调用作为左值
////     */
//////    int & ref = func4();
//////    cout << "ref = " << ref << endl;
////    int & ref2 = func5();
////    cout << "ref2 = " << ref2 << endl;
////    cout << "ref2 = " << ref2 << endl;
////    // 相当于修改了 a 的引用的值，原名改成了 100，别名访问也是100
////    // 如果函数的返回值是引用，这个函数调用可以作为左值
////    func5() = 100;
////    cout << "ref2 = " << ref2 << endl;
////    cout << "ref2 = " << ref2 << endl;
//
//
//    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
//    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
//    const int& ref = 10;
//
//    //ref = 100;  //加入const后不可以修改变量
//    cout << ref << endl;
//
//    //函数中利用常量引用防止误操作修改实参
//    int a = 10;
//    showValue(a);
//
//
//
//}