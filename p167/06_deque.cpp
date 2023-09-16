//#include "iostream"
//#include "deque"
//#include "algorithm"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/16 12:11
//* @description:  deque 及基本函数
//*/
///**
// * 双端数组，可以对头端进行插入删除操作
// * deque与vector区别：
// * vector对于头部的插入删除效率低，数据量越大，效率越低
// * deque相对而言，对头部的插入删除速度回比vector快
// * vector访问元素时的速度会比deque快,这和两者内部实现有关
// *
// * deque内部工作原理:
// * deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
// * 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
// */
//
//
//void printDeque1(const deque<int> &d) {
//    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
//}
//
//void printDeque2(deque<int> &d) {
//    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
//        cout << (*it) << " ";
//    }
//    cout << endl;
//}
//
///**
// * deque 容器构造
// * * deque<T> deqT;                   //默认构造形式
// * deque(beg, end);                   //构造函数将[beg, end)区间中的元素拷贝给本身。
// * deque(n, elem);                    //构造函数将n个elem拷贝给本身。
// * deque(const deque &deq);           //拷贝构造函数
// */
//void test01() {
//    deque<int> d1;
//    for (int i = 0; i < 10; ++i) {
//        d1.push_back(i);
//    }
//    printDeque1(d1);
//
//    deque<int> d2;
//    d2 = d1;
//    printDeque1(d2);
//
//    deque<int> d3;
//    d3.assign(d1.begin(), d1.end());
//    printDeque1(d3);
//
//    deque<int> d4;
//    d4.assign(10, 100);
//    printDeque1(d4);
//
//    deque<int> d5 = d3;
//    printDeque1(d5);
//
//}
//
//
///**
// * 给deque容器进行赋值
// * deque& operator=(const deque &deq);                          //重载等号操作符
// * assign(beg, end);                                           //将[beg, end)区间中的数据拷贝赋值给本身。
// * assign(n, elem);                                            //将n个elem拷贝赋值给本身。
// */
//void test02() {
//    deque<int> d;
//    for (int i = 0; i < 10; ++i) {
//        d.push_front(i);
//    }
//    printDeque1(d);
//
//    deque<int> d2;
//    d2 = d;
//    printDeque1(d2);
//
//    deque<int> d3;
//    d3.assign(d.begin(), d.end());
//    printDeque1(d3);
//
//    deque<int> d4;
//    d4.assign(5, 100);
//    printDeque1(d4);
//
//}
//
//
///**
// * 对deque容器的大小进行操作
// * deque.empty();                    //判断容器是否为空
// * deque.size();                     //返回容器中元素的个数
// * deque.resize(num);                //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//                                    //如果容器变短，则末尾超出容器长度的元素被删除。
// * deque.resize(num, elem);      //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//                                //如果容器变短，则末尾超出容器长度的元素被删除。
// */
//void test03() {
//    deque<int> d;
//    for (int i = 0; i < 10; ++i) {
//        d.push_back(i);
//    }
//    printDeque1(d);
//
//    if (d.empty()) {
//        cout << "d 为空" << endl;
//    } else {
//        cout << "d 不为空" << endl;
//        cout << "d 的大小为：" << d.size() << endl;
//    }
//
//    // resize
//    d.resize(5);
//    printDeque1(d);
//
//    d.resize(10, 10);
//    printDeque1(d);
//
//}
//
//
///**
// * 向deque容器中插入和删除数据
// * 两端插入操作：
// * push_back(elem);              //在容器尾部添加一个数据
// * push_front(elem);             //在容器头部插入一个数据
// * pop_back();                   //删除容器最后一个数据
// * pop_front();                  //删除容器第一个数据
// *
//指定位置操作：
//* insert(pos,elem);             //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
//* insert(pos,n,elem);           //在pos位置插入n个elem数据，无返回值。
//* insert(pos,beg,end);          //在pos位置插入[beg,end)区间的数据，无返回值。
//* clear();                      //清空容器的所有数据
//* erase(beg,end);               //删除[beg,end)区间的数据，返回下一个数据的位置。
//* erase(pos);                   //删除pos位置的数据，返回下一个数据的位置。
// */
//void test04() {
//    deque<int> d;
//    // 尾插
//    d.push_back(10);
//    d.push_back(20);
//    d.push_back(30);
//    // 头插
//    d.push_front(40);
//    d.push_front(50);
//
//    printDeque1(d);
//
//    // 尾删
//    d.pop_back();
//    d.pop_front();
//    printDeque1(d);
//
//}
//
//void test04_2() {
//    // 插入
//    deque<int> d;
//    cout << "-------------" << endl;
//    d.push_back(10);
//    d.push_back(20);
//    d.push_back(30);
//    printDeque1(d);
//
//    d.insert(d.begin(), 40);
//    printDeque1(d);
//
//    d.insert(d.begin(), 2, 100);
//    printDeque1(d);
//
//}
//void test04_3() {
//    deque<int> d;
//    d.push_back(10);
//    d.push_back(20);
//    d.push_back(30);
//    d.push_back(40);
//    printDeque1(d);
//
//    d.erase(d.end());
//    printDeque1(d);
//
//    d.erase(d.begin());
//    printDeque1(d);
//
//    d.erase(d.begin(), d.end());
//    d.clear();
//    cout << "---------" << endl;
//    printDeque1(d);
//}
//
//
///**
// * * 对deque 中的数据的存取操作
// * at(int idx);      //返回索引idx所指的数据
// * operator[];       //返回索引idx所指的数据
// * front();             //返回容器中第一个数据元素
// * back();              //返回容器中最后一个数据元素
// */
//void test05() {
//    deque<int> d;
//    for (int i = 0; i < 10; ++i) {
//        d.push_back(i);
//    }
//    for (int i = 0; i < 10; ++i) {
//        cout << d.at(i) << " " ;
//    }
//    cout << endl;
//
//    cout << d.front() << endl;
//    cout << d.back() << endl;
//
//}
//
///**
// * 利用算法实现对deque容器进行排序
// * sort(iterator beg, iterator end)  //对beg和end区间内元素进行排序
// */
//void test06() {
//    deque<int> d;
//    d.push_back(10);
//    d.push_back(2);
//    d.push_back(50);
//    d.push_back(40);
//
//    printDeque1(d);
//
//    sort(d.begin(), d.end());
//    printDeque1(d);
//
//}
//
//
//
//
//void test() {}
//
//int main() {
//
////    test01();
////    test02();
////    test03();
////    test04();
////    test04_2();
////    test04_3();
////    test05();
//    test06();
////    test07();
////    test08();
//
//    return 0;
//}