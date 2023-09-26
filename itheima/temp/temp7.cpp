//#include "iostream"
//
//using namespace std;
//
//
//
////int& test01() {
////    int a = 10; //局部变量
////    return a;
////}
//
//
////返回静态变量引用
//int& test02() {
//    int a = 20;
//    return a;
//}
//
//
//int main() {
//
//    int& ref2 = test02();
//    cout << "ref2 = " << ref2 << endl;
//
//
//    ref2++;
//    cout << "ref2 = " << ref2 << endl;
//
//    int& ref3 = test02();
//    cout << "ref3 = " << ref3 << endl;
//
//    system("pause");
//
//    return 0;
//}