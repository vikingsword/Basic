//#include "iostream"
//using namespace std;
//
//// 1.如果 b 有默认参数，c 必须也要有默认参数
//int fun1(int a, int b = 2, int c = 3){
//    return a + b + c;
//}
//
//// 2. 如果函数声明有默认参数，函数实现就不能有默认参数
//// 声明和实现只能有一个有默认参数
//int fun2(int a = 10, int b = 20);
//// 函数实现不能有默认参数
////int fun2(int a = 10, int b = 10){
////    return a + b;
////}
//int fun2(int a, int b){
//    return a + b;
//}
//
//
//// 占位参数 --> int (目前还用不到)
//void fun3(int a, int){
//    cout << "this is function " << endl;
//}
//// 占位参数也可以有默认参数
//void fun4(int a, int=10){
//    cout << "this is another function" << endl;
//}
//
//
//void fun5(){
//    cout << "this is fun5.1 " << endl;
//}
//void fun5(int a){
//    cout << "this is fun5.2 " << endl;
//}
//void fun5(string a){
//    cout <<  "this is fun5.3" << endl;
//}
//void fun5(int a, float b){
//    cout << "this is fun5.4" << endl;
//}
//void fun5(float a, int b){
//    cout << "this is fun5.5" << endl;
//}
//// 函数的返回值不能作为重载的条件
////int fun5(){
////
////}
//
//
///**
//* 引用作为重载条件
//*/
//void fun6(int &a){
//    // int &a = 10 不合法
//    cout << "function (int &a) 调用" << endl;
//}
//void fun6(const int &a){
//    // const int &a = 10  合法
//    cout << "function (const int &a) 调用" << endl;
//}
//
///**
// * 函数重载碰到默认函数
// */
//void fun7(int a, int b=10){
// cout << "fun7 (int a,int b) 默认调用 " << endl;
//}
//void fun7(int a){
//    cout << "fun7 (int a) 默认调用 " << endl;
//}
//
//int main(){
//
////    int res = fun1(1, 3);
////    cout << "res = " << res << endl;
////
////    int res2 = fun2(1,2);
////    cout << "res2 = " << res2 << endl;
////
////    int res3 = fun2();
////    cout << "res3 = " << res3 << endl;
//
//
////    fun3(1,2);
////    fun4(1);
//
//
////    // 函数重载： 函数名可以相同，提高复用性
////    /**
////     * 函数重载满足条件：
////     * 同一个作用域下 (都在 main 的作用域下)
////     * 函数名称相同 (都叫 fun5)
////     * 函数参数 类型不同(int string...) 或者 个数不同((int a)/(int a, int b)) 或者 顺序不同((int a,int b)/(int b,int a))
////     */
////    fun5();
////    fun5(1);
////    fun5("hello");
////    fun5(1,2.1);
////    fun5(1.1,2);
//
//
////    // 函数重载注意事项：
////    // 引用作为重载条件
////    int  a = 10;
////    fun6(a);
////    fun6(10);
//
//    // 函数重载碰到函数默认参数，出现二义性，报错，尽量避免这种情况
////    fun7(10);
//    fun7(10,10);
//
//
//
//
//
//
//
//
//
//
//}