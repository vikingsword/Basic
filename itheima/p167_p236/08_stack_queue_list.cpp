//#include "iostream"
//#include "stack"
//#include "queue"
//#include "list"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/16 21:42
//* @description:  栈、队列和链表
//*/
//
///**
// * stack
// *构造函数：
// * stack<T> stk;                        //stack采用模板类实现， stack对象的默认构造形式
// * stack(const stack &stk);            //拷贝构造函数
// *
// * 赋值操作：
// * stack& operator=(const stack &stk);           //重载等号操作符
// *
// * 数据存取：
// * push(elem);            //向栈顶添加元素
// * pop();                 //从栈顶移除第一个元素
// * top();                 //返回栈顶元素
// *
// * 大小操作：
// * empty();              //判断堆栈是否为空
// * size();               //返回栈的大小
// */
//void test01() {
//    stack<int> s;
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    cout << "栈的大小为：" << s.size() << endl;
//
//    while (!s.empty()) {
//        // 输出栈顶元素
//        cout << "栈顶元素为： " << s.top() << endl;
//        // 弹出栈顶元素
//        s.pop();
//    }
//    cout << "栈的大小为： " << s.size() << endl;
//}
//
//
///**
// * queue
// * 构造函数：
// * queue<T> que;                       //queue采用模板类实现，queue对象的默认构造形式
// * queue(const queue &que);            //拷贝构造函数
// *
// * 赋值操作：
// * queue& operator=(const queue &que);           //重载等号操作符
// *
// * 数据存取：
// * push(elem);                                 //往队尾添加元素
// * pop();                                      //从队头移除第一个元素
// * back();                                     //返回最后一个元素
// * front();                                    //返回第一个元素
// *
// * 大小操作：
// * empty();            //判断堆栈是否为空
// * size();               //返回栈的大小
// */
//class Person {
//public:
//    string m_name;
//    int m_age;
//
//    Person(string name, int age) {
//        this->m_name = name;
//        this->m_age = age;
//    }
//};
//
//void test02() {
//    queue<Person> q;
//    Person p1("唐僧", 30);
//    Person p2("孙悟空", 1000);
//    Person p3("猪八戒", 900);
//    Person p4("沙僧", 800);
//
//    q.push(p1);
//    q.push(p2);
//    q.push(p3);
//    q.push(p4);
//
//    while (!q.empty()) {
//        cout << "队头元素-- 姓名： " << q.front().m_name
//             << "; 年龄：" << q.front().m_age << endl;
//        cout << "队尾元素-- 姓名: " << q.back().m_name
//             << "; 年龄：" << q.back().m_age << endl;
//        cout << endl;
//        q.pop();
//    }
//}
//
//
///**
// * list 构造函数
// * list<T> lst;                               //list采用采用模板类实现,对象的默认构造形式：
// * list(beg,end);                              //构造函数将[beg, end)区间中的元素拷贝给本身。
// * list(n,elem);                               //构造函数将n个elem拷贝给本身。
// * list(const list &lst);                      //拷贝构造函数。
// */
//void printList(const list<int> &l) {
//    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
//}
//
//void test03() {
//
//    list<int> l1;
//    l1.push_back(10);
//    l1.push_back(20);
//    l1.push_back(30);
//    l1.push_back(40);
//
//    printList(l1);
//
//    list<int> l2(l1);
//    printList(l2);
//
//    list<int> l3(l1.begin(), l1.end());
//    printList(l3);
//
//    list<int> l4(10, 100);
//    printList(l4);
//
//}
//
//
///**
// * list 交换和赋值
// * assign(beg, end);                        //将[beg, end)区间中的数据拷贝赋值给本身。
// * assign(n, elem);                         //将n个elem拷贝赋值给本身。
// * list& operator=(const list &lst);        //重载等号操作符
// * swap(lst);                               //将lst与本身的元素互换。
// */
//void test04() {
//    list<int> l1;
//    l1.push_back(10);
//    l1.push_back(20);
//    l1.push_back(30);
//    l1.push_back(40);
//
//    // 赋值
//    list<int> l2(l1);
//    cout << "l2 = ";
//    printList(l2);
//
//    list<int> l3;
//    l3.assign(l1.begin(), l1.end());
//    cout << "l3 = ";
//    printList(l3);
//
//    list<int> l4 = l1;
//    cout << "l4 = ";
//    printList(l4);
//
//    list<int> l5;
//    l5.assign(10, 100);
//    cout << "l5 = ";
//    printList(l5);
//
//}
//
//void test04_2() {
//    list<int> l1;
//    l1.push_back(10);
//    l1.push_back(20);
//    l1.push_back(30);
//
//    list<int> l2;
//    l2.assign(10, 100);
//
//    cout << "交换前： " << endl;
//    printList(l1);
//    printList(l2);
//
//    cout << endl;
//
//    cout << "交换后： " << endl;
//    l1.swap(l2);
//    printList(l1);
//    printList(l2);
//}
//
//
///**
// * list 大小操作
// * size();                              //返回容器中元素的个数
// * empty();                            //判断容器是否为空
// * resize(num);                      //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
// *                                   //如果容器变短，则末尾超出容器长度的元素被删除。
// * resize(num, elem);               //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
// *                                  //如果容器变短，则末尾超出容器长度的元素被删除。
// */
//void test05() {
//    list<int> l1;
//    l1.push_back(10);
//    l1.push_back(20);
//    l1.push_back(30);
//
//    if (l1.empty()) {
//        cout << "l1 为空" << endl;
//    } else {
//        cout << "l1 不为空" << endl;
//        cout << "l1 的大小为： " << l1.size() << endl;
//    }
//
//    l1.resize(10);
//    printList(l1);
//
//    l1.resize(11, 100);
//    printList(l1);
//}
//
//
///**
// * list 的插入和删除
// * push_back(elem);         //在容器尾部加入一个元素
// * pop_back();              //删除容器中最后一个元素
// * push_front(elem);        //在容器开头插入一个元素
// * pop_front();             //从容器开头移除第一个元素
// * insert(pos,elem);        //在pos位置插elem元素的拷贝，返回新数据的位置。
// * insert(pos,n,elem);      //在pos位置插入n个elem数据，无返回值。
// * insert(pos,beg,end);     //在pos位置插入[beg,end)区间的数据，无返回值。
// * clear();                 //移除容器的所有数据
// * erase(beg,end);          //删除[beg,end)区间的数据，返回下一个数据的位置。
// * erase(pos);              //删除pos位置的数据，返回下一个数据的位置。
// * remove(elem);            //删除容器中所有与elem值匹配的元素。
// */
//void test06() {
//    list<int> l1;
//    // 尾插
//    l1.push_back(1);
//    l1.push_back(2);
//    l1.push_back(3);
//    // 头插
//    l1.push_front(100);
//    l1.push_front(200);
//    l1.push_front(300);
//
//    printList(l1);
//
//    // 尾删、头删
//    l1.pop_back();
//    l1.pop_front();
//
//    printList(l1);
//
//    // 插入
//    list<int>::iterator it = l1.begin();
//    l1.insert(++it, 99);
//    printList(l1);
//
//    // 删除
//    l1.erase(--it);
//    printList(l1);
//
//    // 移除
//    l1.push_back(1000);
//    l1.push_back(1000);
//    l1.push_back(1000);
//    printList(l1);
//    l1.remove(1000);
//    printList(l1);
//
//    // 清空
//    l1.clear();
//    printList(l1);
//}
//
//
///**
// * list 数据存取
// * front();         // 返回第一个元素
// * back();          // 返回最后一个元素
// */
//void test07() {
//    list<int> l1;
//    l1.push_back(10);
//    l1.push_back(20);
//    l1.push_back(30);
//    l1.push_back(40);
//
//    cout << "第一个元素： " << l1.front() << endl;
//    cout << "最后一个元素： " << l1.back() << endl;
//
//    // list 容器的迭代器是双向迭代器， 不支持随机访问
//    list<int>::iterator it = l1.begin();
//    l1.insert(it++, 12);
//    printList(l1);
//}
//
//
///**
// * list 的反转和排序
// * reverse();       //反转链表
// * sort();         //链表排序
// */
//bool myCompare(int val1, int val2) {
//    // 降序就让第一个数大于第二个数
//    return val1 > val2;
//}
//
//void test08() {
//    list<int> l1;
//    l1.push_back(90);
//    l1.push_back(30);
//    l1.push_back(20);
//    l1.push_back(70);
//    printList(l1);
//
//    //反转容器的元素
//    l1.reverse();
//    printList(l1);
//
//    // 排序， 所有不支持随机访问迭代器的容器，不可以用标准算法，而是用内部提供的算法
//    l1.sort();
//    printList(l1);
//
//    // 指定规则，从大到小
//    l1.sort(myCompare);
//    printList(l1);
//
//}
//
//
///**
// * 排序案例：
// * 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// * 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
// */
//class Student {
//public:
//    string m_name;
//    int m_age;
//    int m_height;
//
//    Student(string name, int age, int height) {
//        m_name = name;
//        m_age = age;
//        m_height = height;
//    }
//};
//
//bool compareStudent(Student &s1, Student &s2) {
//    if (s1.m_age == s2.m_age) {
//        return s1.m_height > s2.m_height;
//    } else {
//        return s1.m_age < s2.m_age;
//    }
//}
//
//void test09() {
//    list<Student> l;
//
//    Student s1("刘备", 35, 175);
//    Student s2("曹操", 45, 180);
//    Student s3("孙权", 40, 170);
//    Student s4("赵云", 25, 190);
//    Student s5("张飞", 35, 160);
//    Student s6("关羽", 35, 200);
//
//    l.push_back(s1);
//    l.push_back(s2);
//    l.push_back(s3);
//    l.push_back(s4);
//    l.push_back(s5);
//    l.push_back(s6);
//
//    for (list<Student>::iterator it = l.begin(); it != l.end(); it++) {
//        cout << "姓名： " << it->m_name << "; 年龄: " << it->m_age
//            << "; 身高： " << it->m_height << endl;
//    }
//
//    cout << "----------------------" << endl;
//    l.sort(compareStudent);
//    for (list<Student>::iterator it = l.begin(); it != l.end(); it++) {
//        cout << "姓名： " << it->m_name << "; 年龄: " << it->m_age
//             << "; 身高： " << it->m_height << endl;
//    }
//
//}
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
////    test05();
////    test06();
////    test07();
////    test08();
//    test09();
//
//    return 0;
//}