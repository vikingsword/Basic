#include "iostream"
using namespace std;

// 1. 创建学生数据类型： 学生包括（姓名、年龄、分数）
// 自定义数据类型，一些类型的集合组成一个类型
struct Student{
    string name;
    int age;
    int score;
};
struct Student2{
    string name;
    int age;
    int score;
}s3;


// 结构体
int main(){

    // 2. 通过学生类型创建具体学生
    // 第 1  2  种使用较多
    // 2.1 struct Student s1
    struct Student s1;
    s1.name = "zs";
    s1.age = 18;
    s1.score = 100;
    cout << "姓名：" << s1.name << " 年龄：" << s1.age  << " 分数：" << s1.score << endl;

    // 2.2 struct Student s2 = {}
    struct Student s2 = {"ls", 29, 80};
    cout << "姓名：" << s2.name << " 年龄：" << s2.age  << " 分数：" << s2.score << endl;

    // 2.3 在定义结构体时顺便创建结构体变量
    s3.name = "wu";
    s3.age = 18;
    s3.score = 90;
    cout << "姓名：" << s3.name << " 年龄：" << s3.age  << " 分数：" << s3.score << endl;

    // 在结构体创建时省略 struct 关键字，定义时不可以省略
    Student s4;



    return 0;
}