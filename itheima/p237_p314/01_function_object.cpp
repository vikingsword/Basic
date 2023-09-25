#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"
#include "headers/function.hpp"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/17 21:46
* @description:  function object
*/

/**
 * 函数对象：
 * 函数对象使用重载的()时，行为类似函数调用，也叫 仿函数
 * 函数对象(仿函数)是一个 类 ，不是一个函数
 *
 * 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
 * 函数对象超出普通函数的概念，函数对象可以有自己的状态
 * 函数对象可以作为参数传递
 */
class MyAdd {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

class MyPrint {
public:
    MyPrint() {
        m_count = 0;
    }

    void operator()(string message) {
        cout << message << endl;
        m_count++;
    }

    int m_count;
};

// 作为参数传递
void printMessage(MyPrint &myPrint, string message) {
    myPrint(message);
}

void test01() {
    // 这里的MyAdd就是函数对象
    MyAdd myAdd;
    int res = myAdd(1, 2);
    cout << res << endl;

    MyPrint myPrint;
    myPrint("hello");
    myPrint("hello");
    myPrint("hello");
    cout << myPrint.m_count << endl;

    // 作为参数传递
    MyPrint myPrint1;
    printMessage(myPrint1, "vikingar");

}

/**
 * 返回bool类型的仿函数称为 谓词
 * * 如果operator()接受一个参数，那么叫做一元谓词
 * 如果operator()接受两个参数，那么叫做二元谓词
 */
class GreaterFive {
public:
    bool operator()(int value) {
        return value > 5;
    }
};

void test02() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        cout << "没找到" << endl;
    } else {
        while (it != v.end()) {
            cout << "找到： " << *it << " " << endl;
            it++;
        }
    }
}

// 二元谓词
class MyCompare {
public:
    bool operator()(int num1, int num2) {
        // 从小到大排序
        return num1 < num2;
    }
};

void test03() {
    vector<int> v = {6, 5, 4, 3, 2, 1, 9};
    sort(v.begin(), v.end(), MyCompare());
    for (int elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}


/**
 * STL内建了一些函数对象
 * * 算术仿函数
 * 关系仿函数
 * 逻辑仿函数
 * * 这些仿函数所产生的对象，用法和一般函数完全相同
 * 使用内建函数对象，需要引入头文件 #include<functional>
 */

/**
 * 算术仿函数
 * 实现四则运算
 * 其中negate是一元运算，其他都是二元运算
 * 仿函数原型：
 * template<class T> T plus<T>                //加法仿函数
 * template<class T> T minus<T>              //减法仿函数
 * template<class T> T multiplies<T>        //乘法仿函数
 * template<class T> T divides<T>         //除法仿函数
 * template<class T> T modulus<T>         //取模仿函数
 * template<class T> T negate<T>           //取反仿函数
 */
void test04() {
    negate<int> n;
    cout << n(20) << endl;

    plus<int> p;
    cout << p(10, 20) << endl;
}


/**
 * 关系仿函数
 * 功能描述：
 * 实现关系对比
 * 仿函数原型：
 * template<class T> bool equal_to<T>                    //等于
 * template<class T> bool not_equal_to<T>            //不等于
 * template<class T> bool greater<T>                      //大于
 * template<class T> bool greater_equal<T>          //大于等于
 * template<class T> bool less<T>                           //小于
 * template<class T> bool less_equal<T>               //小于等于
 */
void test05() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);

    printVector(v);

    sort(v.begin(), v.end(), greater<int>());

    printVector(v);

}


/**
 * 逻辑仿函数
 * 功能描述：
 * 实现逻辑运算
 * 函数原型：
 * template<class T> bool logical_and<T>              //逻辑与
 * template<class T> bool logical_or<T>                //逻辑或
 * template<class T> bool logical_not<T>              //逻辑非
 */
void test06() {
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    printVector(v);

    //逻辑非  将v容器搬运到v2中，并执行逻辑非运算
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());

    printVector(v2);
}


void test() {}

int main() {

//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
    test06();
//    test07();
//    test08();
//    test09();
//    test10();
//    test11();
//    test12();
//    test13();
//    test14();


    return 0;
}