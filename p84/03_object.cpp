#include "iostream"
using namespace std;

const double PI = 3.14;

class Circle {
public:
    // 属性
    // 半径
    int m_r;

    // 行为
    // 获取圆的周长
    double calculatePerimeter() {
        return 2 * PI * m_r;
    }
};

class Student{
private:
    string name;
    int id;

public:
    void setName(string set_name){
        name = set_name;
    }
    void setId(int sid){
        id = sid;
    }

    void showName(){
        cout << "name = " << name << endl;
    }
    void showId(){
        cout << "id = " << id << endl;
    }

};

class Person{
public:
    string m_Name;
protected:
    string m_Car;
private:
    int m_Password;

private:
    void fun(){
        m_Name = "张三";
        m_Car = "tax";
        m_Password = 123;
    }
};


class C1{
    // 默认权限是私有
    int m_A;
};
struct C2{
    // 默认权限是公共
    int m_A;
};


// 私有化成员变量
class Person2{

private:
    string m_Name;
    int m_Age;
    string m_Lover;

public:
    void setName(string name){
        m_Name = name;
    }
    string getName(){
        return m_Name;
    }

    int getAge(){
        m_Age = 10;
        return m_Age;
    }

    void setLover(string lover){
        m_Lover = lover;
    }


};

int main(){

//    // 通过圆类，创建具体的圆
//    Circle cl;
//
//    // 给圆对象的属性进行赋值
//    cl.m_r = 1;
//    double perimeter = cl.calculatePerimeter();
//    cout << "周长为： " << perimeter << endl;


//    Student s;
//    s.setId(1);
//    s.setName("zs");
//    s.showId();
//    s.showName();


//    // 访问权限： 公共、保护、私有
//    //公共权限  public     类内可以访问  类外可以访问
//    //保护权限  protected  类内可以访问  类外不可以访问  儿子可以访问父亲中的保护内容
//    //私有权限  private    类内可以访问  类外不可以访问  儿子不可以访问父亲的私有内容
//    Person p;
//    p.m_Name = "li";
//    // protected 和 private 的内容在类外访问不到
////    p.m_Car = "car";
////    p.m_Password = 1234;
////    p.fun();


//    // * struct 默认权限为公共
//    // * class   默认权限为私有
//    C1 c1;
////    c1.m_A = 100;
//    C2 c2;
//    c2.m_A = 100;


    /**
     * 成员属性设置为私有:
     * 优点1：将所有成员属性设置为私有，可以自己控制读写权限
     * 优点2：对于写权限，我们可以检测数据的有效性
     */
    Person2 p2;
    p2.setName("wu");
    string name = p2.getName();
    cout << "name = " << name << endl;
    int age = p2.getAge();
    cout << "age = " << age << endl;
    p2.setLover("ls");


}