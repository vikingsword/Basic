//#include "iostream"
//#include "header/point.h"
//#include "header/circle.h"
//
//using namespace std;
//
//const double PI = 3.14;
//
//class Circle {
//public:
//    // 属性
//    // 半径
//    int m_r;
//
//    // 行为
//    // 获取圆的周长
//    double calculatePerimeter() {
//        return 2 * PI * m_r;
//    }
//};
//
//class Student {
//private:
//    string name;
//    int id;
//
//public:
//    void setName(string set_name) {
//        name = set_name;
//    }
//
//    void setId(int sid) {
//        id = sid;
//    }
//
//    void showName() {
//        cout << "name = " << name << endl;
//    }
//
//    void showId() {
//        cout << "id = " << id << endl;
//    }
//
//};
//
//class Person {
//public:
//    string m_Name;
//protected:
//    string m_Car;
//private:
//    int m_Password;
//
//private:
//    void fun() {
//        m_Name = "张三";
//        m_Car = "tax";
//        m_Password = 123;
//    }
//};
//
//
//class C1 {
//    // 默认权限是私有
//    int m_A;
//};
//
//struct C2 {
//    // 默认权限是公共
//    int m_A;
//};
//
//
//// 私有化成员变量
//class Person2 {
//
//private:
//    string m_Name;
//    int m_Age;
//    string m_Lover;
//
//public:
//    void setName(string name) {
//        m_Name = name;
//    }
//
//    string getName() {
//        return m_Name;
//    }
//
//    void setAge(int age) {
//        if (age > 100 || age < 0) {
//            cout << "输入的年龄有误" << endl;
//            return;
//        }
//    }
//
//    int getAge() {
//        return m_Age;
//    }
//
//    void setLover(string lover) {
//        m_Lover = lover;
//    }
//};
//
//
//// 案例： 设计立方体类
////求出立方体的面积和体积
////分别用全局函数和成员函数判断两个立方体是否相等
//class Cube {
//private:
//    double m_H;
//    double m_L;
//    double m_W;
//
//public:
//    void set_H(double H) {
//        m_H = H;
//    }
//
//    void set_L(double L) {
//        m_L = L;
//    }
//
//    void set_W(double W) {
//        m_W = W;
//    }
//
//    double get_w() {
//        return m_W;
//    }
//
//    double get_l() {
//        return m_L;
//    }
//
//    double get_h() {
//        return m_H;
//    }
//
//    void init_cube(double h, double w, double l) {
//        m_H = h;
//        m_L = l;
//        m_W = w;
//    }
//
//
//    double get_area() {
//        return 2 * ((m_H * m_L) + (m_H * m_W) + (m_L * m_W));
//    }
//
//    double get_volume() {
//        return m_H * m_L * m_W;
//    }
//
//    // 利用成员函数判断两个立方体是否相等
//    bool is_same_by_class(Cube &c) {
//        if (m_L == c.get_l() && m_W == c.get_w() && m_H == c.get_h()) {
//            return true;
//        }
//        return false;
//    }
//
//
//};
//
//
//void if_equal(Cube c1, Cube c2) {
//    if (c1.get_h() == c2.get_h() && c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w()) {
//        cout << "两个立方体相等 " << endl;
//    } else {
//        cout << "不相等" << endl;
//    }
//}
//
//
//void Point::set_x(int x){
//    m_x = x;
//}
//void Point::set_y(int y){
//    m_y = y;
//}
//
//int Point::get_x(){
//    return m_x;
//}
//
//int Point::get_y(){
//    return m_y;
//}
//
//
//void Circle2::set_r(int r){
//    m_R = r;
//}
//
//int Circle2::get_r(){
//    return m_R;
//}
//
//void Circle2::set_center(Point center){
//    m_center = center;
//}
//
//Point Circle2::get_center(){
//    return m_center;
//}
//
//
//
//void isInCircle(Circle2 &c, Point &p) {
//    double distance = (c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
//            (c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
//    if (distance ==  c.get_r() * c.get_r()) {
//        cout << "点在圆上" << endl;
//    } else if (distance < c.get_r() * c.get_r()) {
//        cout << "点在圆内" << endl;
//    } else {
//        cout << "点在圆外" << endl;
//    }
//}
//
//
//int main() {
//
////    // 通过圆类，创建具体的圆
////    Circle cl;
////
////    // 给圆对象的属性进行赋值
////    cl.m_r = 1;
////    double perimeter = cl.calculatePerimeter();
////    cout << "周长为： " << perimeter << endl;
//
//
////    Student s;
////    s.setId(1);
////    s.setName("zs");
////    s.showId();
////    s.showName();
//
//
////    // 访问权限： 公共、保护、私有
////    //公共权限  public     类内可以访问  类外可以访问
////    //保护权限  protected  类内可以访问  类外不可以访问  儿子可以访问父亲中的保护内容
////    //私有权限  private    类内可以访问  类外不可以访问  儿子不可以访问父亲的私有内容
////    Person p;
////    p.m_Name = "li";
////    // protected 和 private 的内容在类外访问不到
//////    p.m_Car = "car";
//////    p.m_Password = 1234;
//////    p.fun();
//
//
////    // * struct 默认权限为公共
////    // * class   默认权限为私有
////    C1 c1;
//////    c1.m_A = 100;
////    C2 c2;
////    c2.m_A = 100;
//
//
////    /**
////     * 成员属性设置为私有:
////     * 优点1：将所有成员属性设置为私有，可以自己控制读写权限
////     * 优点2：对于写权限，我们可以检测数据的有效性
////     */
////    Person2 p2;
////    p2.setName("wu");
////    string name = p2.getName();
////    cout << "name = " << name << endl;
//////    int age = p2.getAge();
//////    cout << "age = " << age << endl;
////    p2.setLover("ls");
////    p2.setAge(103);
//
//
////    Cube c;
////    c.set_H(1);
////    c.set_L(2);
////    c.set_W(3);
////    cout << c.get_area() << endl;
////    cout << c.get_volume() << endl;
////
////    Cube c1, c2, c3;
////    c1.init_cube(1, 2, 3);
////    c2.init_cube(1, 2, 3);
////    c3.init_cube(1, 2, 1);
////    if_equal(c1, c2);
////    if_equal(c1, c3);
////    bool flag = c1.is_same_by_class(c2);
////    if (flag) {
////        cout << "相等" << endl;
////    }
//
//
//    Circle2 c;
//    Point c_center;
//    c_center.set_x(0);
//    c_center.set_y(0);
//    c.set_center(c_center);
//    c.set_r(2);
//
//    Point p;
//    p.set_x(0);
//    p.set_y(5);
//
//    isInCircle(c, p);
//
//
//
//
//
//}