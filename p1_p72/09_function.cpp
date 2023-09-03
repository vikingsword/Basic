//#include "iostream"
//#include "10_function_with_file.h"
//using namespace std;
//
//// num1  num2 为形参
//int add(int num1, int num2){
//    return num1 + num2;
//}
//
//// 值传递
//// 两个数字进行交换
//void swap(int a, int b){
//    int temp = a;
//    a = b;
//    b = temp;
//    cout << "交换后" << endl;
//    cout << "a = " << a << "\nb = " << b << endl;
//}
//
////函数常见样式
////1、 无参无返
//void test1(){
//    cout << "this is test1" << endl;
//}
//
////2、 有参无返
//void test2(string name){
//    cout << "my name is " << name << endl;
//}
//
////3、无参有返
//int test3(){
//    return 1;
//}
//
//// 4、有参有返
//int test4(int a){
//    return a;
//}
//
//
//// 函数的定义
//// 返回两个函数中的最大值
//int getMax(int a, int b){
//    return a > b ? a : b;
//}
//
////声明可以多次，定义只能一次
////声明：告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。
//int getMax2(int a,int b);
//int getMax2(int a,int b);
//int getMax2(int a,int b);
//
//
//int main(){
////    int sum = add(1,2);
////    cout << "sum = " << sum;
////
////    int a = 1;
////    int b = 2;
////    // a b 为实参
////    int sum2 = add(a,b);
////    cout << "sum2 = " << sum2 << endl;
//
//
////    int a = 1;
////    int b = 2;
////    cout << "交换前" << endl;
////    cout << "a = " << a << "\nb = " << b << endl;
////    swap(a,b);
//
//
////    test1();
////    test2("vikingar");
////    int temp = test3();
////    cout << "temp = " << temp << endl;
////    int  temp2 = test4(1);
////    cout << "temp2 = " << temp2 << endl;
//
//
////    int temp = getMax(1,2);
////    cout << "the max between a and b is " << temp << endl;
////
////    int temp2 = getMax2(1,2);
////    cout << "the max between a and b is " << temp2 << endl;
//
//
////    // 函数的分文件编写, 调用需要包含 10_function_with_file.h
////    swap2(1,2);
//
//
//
//
//
//}
//
//
//
//int getMax2(int a, int b){
//    return a > b ? a : b;
//}
