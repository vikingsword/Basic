#include "iostream"

using namespace std;

class Person {
    // 编译器提供的构造函数和析构函数是空实现。
public:
    /**
     * 1. 构造函数，没有返回值也不写void
     * 2. 函数名称与类名相同
     * 3. 构造函数可以有参数，因此可以发生重载
     * 4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
     */
    Person() {
        cout << "person 构造函数的调用" << endl;
    }

    /**
     * 1. 析构函数，没有返回值也不写void
     * 2. 函数名称与类名相同,在名称前加上符号  ~
     * 3. 析构函数不可以有参数，因此不可以发生重载
     * 4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
     */
    ~Person() {
        cout << "person 析构函数的调用" << endl;
    }
};

void test01() {
    Person p;
}


class Person2 {
public:
    string m_name;
    int m_age;

public:
    // 无参构造
    Person2() {
        cout << "Person2 构造函数的调用 " << endl;
    }

    // 有参构造
    Person2(string name) {
        cout << "Person2 的有参构造 name " << endl;
        m_name = name;
    }

    Person2(int age) {
        cout << "Person2 的有参构造 age " << endl;
        m_age = age;
    }

    Person2(string name, int age) {
        cout << "Person2 的有参构造 name age" << endl;
        m_name = name;
        m_age = age;
    }

    // 拷贝构造函数
    Person2(const Person2 &p) {
        // 将传入的人身上的所有属性，拷贝到我身上
        cout << "Person2 的拷贝构造函数 " << endl;
        m_age = p.m_age;
        m_name = p.m_name;
    }


    ~Person2() {
        cout << "Person2 析构函数的调用" << endl;
    }
};

void test02() {
    // 构造函数的调用
    // 括号法
//    Person2 p2;
//    Person2(10);
//    Person2("zs");

//    Person2 p3(15);
//    Person2 p4(p3);
//    cout << "p3的年龄为： " << p3.m_age << endl;
//    cout << "p4的年龄为： " << p4.m_age << endl;

    // 注意
    // 调用默认构造函数的时候，不要加()，否则会被认为是函数声明
//    Person2 p2();     // void func();


//    // 显示法
////    Person2 p1;
//    Person2 p2 = Person2(10);
//    Person2 p3 = Person2(p2);

//    // 下面为匿名对象，当前行执行结束后会立即回收掉这个对象
//    Person2(10);

//    // 不要利用拷贝构造初始化匿名对象
//    Person2 p4;
//    // 编译器为认为 Person2(p4)  -->  Person2 p4
////    Person2(p4);


//    // 隐式转换法
//    Person2 p5 = 10;    // 等价于 Person2 p5 = Person2(10);
//    Person2 p6 = p5;


}


/**
 * C++中拷贝构造函数调用时机通常有三种情况
 * 使用一个已经创建完毕的对象来初始化一个新对象
 * 值传递的方式给函数参数传值
 * 以值方式返回局部对象
 */


/**
 * 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
 * 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
 */
class Person3 {
public:
    int m_age;

public:
    Person3() {
        cout << "person3 的无参构造函数 " << endl;
    }

    Person3(int age) {
        m_age = age;
        cout << "person3 的有参构造函数 age" << endl;
    }

    Person3(const Person3 &p) {
        cout << "拷贝构造函数" << endl;
    }

    ~Person3() {
        cout << "person3 的析构函数" << endl;
    }
};

void test03() {
    Person3 p1;
    p1.m_age = 19;
    Person3 p2(p1);
    cout << "p2'a age = " << p2.m_age << endl;

}

/**
 * 深拷贝与浅拷贝
 */
class Person4 {
public:
    int m_age;
    // 用指针(将身高数据创建到堆区)
    int *m_height;

public:
    Person4() {
        cout << "person3 的无参构造函数 " << endl;
    }

    Person4(int age, int height) {
        m_age = age;
        m_height = new int(height);
        cout << "person3 的有参构造函数 age height" << endl;
    }

    Person4(const Person4 &p) {
        // 自己实现拷贝构造函数，解决浅拷贝带来的问题
        cout << "拷贝构造函数" << endl;
        m_age = p.m_age;
        // 编译器默认下面这行代码
//        m_height = p.m_height;
        // 自己写深拷贝操作
        cout << "*p.m_height = " << *p.m_height << endl;
        m_height = new int(*p.m_height);
    }

    ~Person4() {
        // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        // p2 将堆内存释放，导致 p1 无法再次将堆内存释放，程序报错
        // 将堆区开辟的数据释放
        if (m_height != NULL) {
            delete m_height;
            m_height = NULL;
        }
        cout << "person3 的析构函数" << endl;
    }
};

void test04() {

    Person4 p1(18, 190);
    cout << "p1的年龄为： " << p1.m_age << "; p1的身高为： " << *p1.m_height << endl;
    Person4 p2(p1);
    cout << "p2的年龄为： " << p2.m_age << "; p2的身高为： " << *p2.m_height << endl;

}


class Person5 {

public:
    Person5(int a, int b, int c) : m_a(a), m_b(b), m_c(c) {}

    void printPerson() {
        cout << "m_a = " << m_a << endl;
        cout << "m_b = " << m_b << endl;
        cout << "m_c = " << m_c << endl;
    }

private:
    int m_a;
    int m_b;
    int m_c;
};

class Phone {
public:
    Phone(string pName) {
        m_pname = pName;
    }

    string m_pname;
};

class Person6 {
public:
    string m_name;
    Phone m_phone;
public:
    Person6(string name, string phone) : m_name(name), m_phone(phone) {}


};

void test06() {

    Person6 p("zs", "apple");

    cout << p.m_name << "拿着" << p.m_phone.m_pname << endl;

}

class Person7 {
public:
    /**
     * 静态成员变量
     *  所有对象共享同一份数据
     *  在编译阶段分配内存
     *  类内声明，类外初始化
     */
    static int m_age;

    // 静态成员变量也是有访问权限的
private:
    static int m_height;
};

int Person7::m_age = 10;
// 类内声明一定要类外初始化一下
int Person7::m_height = 190;

void test07() {

    Person7 p;
    cout << p.m_age << endl;

    Person7 p2;
    p2.m_age = 100;
    // 变为 100 说明 m_age 为共享的数据
    cout << p.m_age << endl;

}

void test07_2() {
    // 静态成员变量 不属于某个对象上，所有对象都共享同一份数据
    // 因此静态成员变量有两种访问方式
    // 1. 通过对象进行访问
    Person7 p1;
    cout << p1.m_age << endl;

    // 2. 通过类名进行访问
    cout << Person7::m_age << endl;
    // 私有权限类外无法访问
//    cout << Person7::m_height << endl;
}


/**
 *  静态成员函数
 *  所有对象共享同一个函数
 *  静态成员函数只能访问静态成员变量
 */

class Person8 {
public:
    static void func() {
        cout << "this is static function" << endl;
        // 静态成员函数可以访问静态成员变量
        m_a = 100;
        // 因为无法区分是哪个成员变量的属性 m_b
//        m_b = 100;
    }

    static int m_a;
    int m_b;
private:
    static void func2() {
        cout << "static void func2 调用" << endl;
    }
};

// 记得静态成员变量一定要在类内声明、类外初始化
int Person8::m_a = 10;

void test08() {
    // 1. 通过对象进行访问
    Person8 p;
    p.func();
    // 2. 通过类名进行访问
    Person8::func();

    // 类外无法访问私有的静态成员函数
//    Person8::func2()
}


// 成员变量和成员函数分开存储
class Person9 {

    // 非对象成员变量属于类的对象上的
    int a;

    // 静态成员变量，不属于类的对象上
    static int b;

    // 非静态成员函数，不属于类对象上
    void func(){}

    // 静态成员函数，不属于类的对象上
    static void func2(){}

};

int Person9::b = 10;

void test09() {
    Person9 p;
    // c++ 会给每个空对象分配一个内存空间，是为了空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "person9 的大小为： " << sizeof(p) << endl;
}

void test10() {
    Person9 p;
    cout << "sizeof p is " << sizeof(p) << endl;
}

int main() {


//    test01();

//    test02();

//    test03();

//    test04();

//    test06();

//    test07();

//    test07_2();

//    test08();

    test09();

    test10();





//    system("pause");

    return 0;
}
