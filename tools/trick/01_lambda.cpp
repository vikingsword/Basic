//#include "iostream"
//#include "vector"
//#include "algorithm"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/10/3 9:48
//* @description:  lambda statement
//*/
//
//
///**
// * lambda 表达式的格式
// * [OuterVar] (int x, int y) -> int {
// *      return OuterVar + x + y;
// * }
// * [OuterVar]: 捕获变量
// * (int x, int y): 参数列表
// * int: 返回类型
// * OuterVar + x + y: 函数主体
// */
//
//void test01() {
//    vector<int> vec{0, 11, 319, 22, 7, 1, 5};
//    auto f = [](int a, int b) {
//        return a < b;
//    };
//    sort(vec.begin(), vec.end(), f);
//}
//
//void test02() {
//    auto f = [](int a, int b) {
//        return a + b;
//    };
//    cout << f(1, 2) << endl;
//}
//
///**
// * 使用 [] 进行变量捕获
// * 只写 [&] 捕获所有封闭范围内的变量，按引用捕获
// * 只写 [=] 所有的变量都按值捕获
// */
//void test03() {
//    int N = 100, M = 10;
//    auto f = [N, &M](int i) {
//        M = 20;
//        return N * i;
//    };
//    cout << f(10) << endl;
//    cout << M << endl;
//}
//void test04() {
//    int N = 100, M = 10;
//    auto f = [&N](int i){
//        cout << N << endl;
//        return N;
//    };
//    f(10);
//}
//
///**
// * 本地函数: Lambda允许你在需要的地方定义匿名函数，而不必为它们命名或在其他地方定义它们。这对于一次性或特定上下文的操作非常有用。
// */
//void test05() {
//    auto add = [](int a, int b) { return a + b; };
//    cout << "input two number: " << endl;
//    cout << "num1: ";
//    int num1;
//    cin >> num1;
//    cout << "num2: ";
//    int num2;
//    cin >> num2;
//    auto sum = add(num1,num2);
//    cout << "sum = " << sum << endl;
//}
//
///**
// * 代码块封装: Lambda表达式可以封装一组操作，使得代码更具可读性和结构化，特别是在算法和STL容器中的应用。
// */
//void test06() {
//    vector<int> v {1,2,3,4,5};
//    int total = 0;
//    for_each(v.begin(), v.end(), [&total](int num){total += num;});
//    cout << "total = " << total << endl;
//}
//
///**
// * 回调函数: 用于回调函数，例如，当你需要将函数作为参数传递给其他函数时，Lambda表达式可以方便地定义回调函数。
// */
//void test07() {
//    // 打印 vector 中的所有偶数
//    vector<int> v {1,2,3,4,5};
//    for_each(v.begin(), v.end(), [](int num){
//        if (num % 2 == 0) cout << "num " << num << " is even." << endl;
//    });
//}
//
///**
// *  自定义排序: 在排序算法中，Lambda表达式可用于自定义排序的规则。
// */
//void test08() {
//    vector<int> v {5,3,2,7,9,1,4};
//    sort(v.begin(), v.end(), [](int &num1, int &num2){
//        return num1 < num2;
//    });
//    for_each(v.begin(), v.end(),[](int num){cout << num << " ";});
//}
//void test09() {
//    vector<string> v = {"apple", "banana", "cherry", "date"};
//    sort(v.begin(), v.end(), [](string &str1, string &str2){return str1.length() > str2.length();});
//    for_each(v.begin(), v.end(), [](string s){cout << s << " ";});
//}
//
///**
// * 闭包: Lambda表达式允许捕获外部作用域的变量，使其在Lambda函数内可见。这是一种方便的方式来传递外部变量给Lambda函数，而不必通过参数传递。
// */
//void test10() {
//    int x = 10;
//    auto f = [&x]() {cout << "x = " << x << endl;};
//    f();
//}
//
//
//
//
//int main() {
//
////    test01();
////    test02();
////    test03();
////    test04();
////    test05();
////    test06();
////    test07();
////    test08();
////    test09();
//    test10();
//
//
//    return 0;
//}