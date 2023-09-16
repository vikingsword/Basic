//#include "iostream"
//#include "vector"
//#include "algorithm"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/16 8:50
//* @description:  vector 相关函数
//*/
//void printVector(vector<int> &v) {
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//        cout << (*it) << " ";
//    }
//    cout << endl;
//}
//
///**
// * 创建 vector 容器
// * vector<T> v;                		    //采用模板实现类实现，默认构造函数
// * vector(v.begin(), v.end());          //将v[begin(), end())区间中的元素拷贝给本身。
// * vector(n, elem);                     //构造函数将n个elem拷贝给本身。
// * vector(const vector &vec);           //拷贝构造函数。
// */
//void test01() {
//    vector<int> v1;
//    for (int i = 0; i < 10; ++i) {
//        v1.push_back(i);
//    }
//    printVector(v1);
//
//    vector<int> v2(v1.begin(), v1.end());
//    printVector(v2);
//
//    vector<int> v3(10, 100);
//    printVector(v3);
//
//    vector<int> v4(v3);
//    printVector(v4);
//
//}
//
//
///**
// * 给 vector 容器进行赋值
// * vector& operator=(const vector &vec);    //重载等号操作符
// * assign(beg, end);                        //将[beg, end)区间中的数据拷贝赋值给本身。
// * assign(n, elem);                         //将n个elem拷贝赋值给本身。
// */
//void test02() {
//    vector<int> v1;
//    for (int i = 0; i < 10; ++i) {
//        v1.push_back(i);
//    }
//
//    vector<int> v2;
//    v2 = v1;
//    printVector(v2);
//
//    vector<int> v3;
//    v3.assign(v1.begin(), v1.end());
//    printVector(v3);
//
//    vector<int> v4;
//    v4.assign(10, 10);
//    printVector(v4);
//
//}
//
//
///**
// * 对 vector 容器的容量和大小操作
// * empty();                     //判断容器是否为空
// * capacity();                  //容器的容量
// * size();                      //返回容器中元素的个数
// * resize(int num);             //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
// *                              // 如果容器变短，则末尾超出容器长度的元素被删除。
// * resize(int num, elem);       //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
// *                              //如果容器变短，则末尾超出容器长度的元素被删除
// */
//void test03() {
//    vector<int> v1;
//    for (int i = 0; i < 10; ++i) {
//        v1.push_back(i);
//    }
//    printVector(v1);
//
//    if (v1.empty()) {
//        cout << "v1 为空" << endl;
//    } else {
//        cout << "v1 不为空" << endl;
//        cout << "v1 的容量大小为： " << v1.capacity() << endl;
//        cout << "v1 中的元素个数为： " << v1.size() << endl;
//    }
//
//    // resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
//    v1.resize(15, 10);
//    printVector(v1);
//
//    //resize 重新指定大小 ，若指定的更小，超出部分元素被删除
//    v1.resize(5);
//    printVector(v1);
//}
//
//
///**
// * 对 vector 容器进行插入、删除操作
// * push_back(ele);                                                  //尾部插入元素ele
// * pop_back();                                                      //删除最后一个元素
// * insert(const_iterator pos, ele);                                 //迭代器指向位置pos插入元素ele
// * insert(const_iterator pos, int count,ele);                       //迭代器指向位置pos插入count个元素ele
// * erase(const_iterator pos);                                       //删除迭代器指向的元素
// * erase(const_iterator start, const_iterator end);                 //删除迭代器从start到end之间的元素
// * clear();                                                        //删除容器中所有元素
// */
//void test04() {
//    vector<int> v1;
//    // 尾插
//    v1.push_back(1);
//    v1.push_back(2);
//    v1.push_back(3);
//    printVector(v1);
//
//    // 尾删
//    v1.pop_back();
//    printVector(v1);
//
//    // 插入
//    v1.insert(v1.begin(), 0);
//    v1.insert(v1.end(), 3);
//    printVector(v1);
//
//    v1.insert(v1.begin(), 1, 0);
//    printVector(v1);
//
//    // 删除
//    v1.erase(v1.begin());
//    printVector(v1);
//
//    // 清空
//    v1.erase(v1.begin(), v1.end());
//    v1.clear();
//    cout << "print empty" << endl;
//    printVector(v1);
//
//
//}
//
//
///**
// * 对 vector 中的数据进行存取
// * at(int idx);      //返回索引idx所指的数据
// * operator[];        //返回索引idx所指的数据
// * front();             //返回容器中第一个数据元素
// * back();              //返回容器中最后一个数据元素
// */
//void test05() {
//    vector<int> v;
//    for (int i = 0; i < 10; ++i) {
//        v.push_back(i);
//    }
//
//    // 取 vector 中的元素 1
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//
//    // 取
//    for (int i = 0; i < v.size(); ++i) {
//        cout << v.at(i) << " ";
//    }
//    cout << endl;
//
//    cout << "v的第一个元素为： " << v.front() << endl;
//    cout << "v的最后一个元素为：" << v.back() << endl;
//
//
//}
//
//
///**
// * swap(vec);           // 将vec与本身的元素互换
// */
//void test06() {
//    vector<int> v1;
//    for (int i = 0; i < 10; ++i) {
//        v1.push_back(i);
//    }
//    printVector(v1);
//
//    vector<int> v2;
//    for (int i = 9; i >= 0; i--) {
//        v2.push_back(i);
//    }
//    printVector(v2);
//
//    swap(v1, v2);
//    cout << "交换 v1 v2 之后： " << endl;
//    cout << "v1 = ";
//    printVector(v1);
//    cout << "v2 = ";
//    printVector(v2);
//
//}
//
//// 收缩内存
//void test06_2() {
//    vector<int> v;
//    for (int i = 0; i < 10000; ++i) {
//        v.push_back(i);
//    }
//    cout << "v的容量大小为： " << v.capacity() << endl;
//    cout << "v的大小为：" << v.size() << endl;
//
//    v.resize(3);
//    cout << "v的容量大小为： " << v.capacity() << endl;
//    cout << "v的大小为：" << v.size() << endl;
//
//    // 收缩内存
//    // vector<int>(v): 匿名对象，按照当前v的大小进行初始化，假设当前对象为 x
//    // .swap(v) x 和 v 进行容器之间的交换，而且匿名对象执行完了马上被回收
//    vector<int>(v).swap(v);
//    cout << "v的容量大小为： " << v.capacity() << endl;
//    cout << "v的大小为：" << v.size() << endl;
//
//}
//
//
///**
// * 减少vector在动态扩展容量时的扩展次数
// * reserve(int len);    //容器预留len个元素长度，预留位置不初始化，元素不可访问。
// */
//void test07() {
//    vector<int> v;
//    v.reserve(100000);
//
//    // 统计 vector 开辟内存的次数
//    int num = 0;
//    int *p = NULL;
//    for (int i = 0; i < 100000; ++i) {
//        v.push_back(i);
//        if (p != &v[0]) {
//            p = &v[0];
//            num++;
//        }
//    }
//
//    cout << "num : " << num << endl;
//}
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
////    test06_2();
//    test07();
//
//
//    return 0;
//
//}