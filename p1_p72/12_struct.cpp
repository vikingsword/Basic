//#include "iostream"
//using namespace std;
//
//// 1. 创建学生数据类型： 学生包括（姓名、年龄、分数）
//// 自定义数据类型，一些类型的集合组成一个类型
//struct Student{
//    string name;
//    int age;
//    int score;
//};
//struct Student2{
//    string name;
//    int age;
//    int score;
//}s3;
//
//// 结构体数组
//// 1. 定义结构体
//struct Student3{
//    // 姓名
//    string name;
//    // 年龄
//    int age;
//    // 分数
//    int score;
//};
//
//// 结构体嵌套结构体
//struct student{
//    string name;
//    int age;
//    int score;
//};
//struct teacher{
//    int id;
//    string name;
//    int age;
//    struct student stu;
//};
//
//
//// 打印学生信息函数
//// 1. 值传递
//void printStudent1(struct student stu){
//    cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
//}
//// 2. 地址传递
//void printStudent2(struct student *p){
////    p -> name = "vik";  地址传递修改元素的值
//    cout << "子函数中 姓名：" << p->name << " 年龄： " << p->age  << " 分数：" << p->score << endl;
//}
//
//
//struct student2{
//    //成员列表
//    string name;  //姓名
//    int age;      //年龄
//    int score;    //分数
//};
////const使用场景，使用指针减少内存空间占用，而且不会复制新的副本
//void printStudent(const student2 *stu) //加const防止函数体中的误操作
//{
////    stu->age = 100; //操作失败，因为加了const修饰
//    cout << "姓名：" << stu->name << " 年龄：" << stu->age << " 分数：" << stu->score << endl;
//
//}
//
//
//struct hero{
//    string name;
//    int age;
//    string sex;
//};
////冒泡排序
//void bubbleSort(hero arr[] , int len) {
//    for (int i = 0; i < len - 1; i++) {
//        for (int j = 0; j < len - 1 - i; j++) {
//            if (arr[j].age > arr[j + 1].age) {
//                hero temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
////打印数组
//void printHeroes(hero arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
//    }
//}
//
//
//// 结构体
//int main(){
//
////    // 2. 通过学生类型创建具体学生
////    // 第 1  2  种使用较多
////    // 2.1 struct Student s1
////    struct Student s1;
////    s1.name = "zs";
////    s1.age = 18;
////    s1.score = 100;
////    cout << "姓名：" << s1.name << " 年龄：" << s1.age  << " 分数：" << s1.score << endl;
////
////    // 2.2 struct Student s2 = {}
////    struct Student s2 = {"ls", 29, 80};
////    cout << "姓名：" << s2.name << " 年龄：" << s2.age  << " 分数：" << s2.score << endl;
////
////    // 2.3 在定义结构体时顺便创建结构体变量
////    s3.name = "wu";
////    s3.age = 18;
////    s3.score = 90;
////    cout << "姓名：" << s3.name << " 年龄：" << s3.age  << " 分数：" << s3.score << endl;
////
////    // 在结构体创建时省略 struct 关键字，定义时不可以省略
////    Student s4;
//
//
////    // 结构体数组
////    // 2. 创建结构体数组
////    struct Student3 stuArray[3] = {
////            {"zs", 18,100},
////            {"ls", 20, 90},
////            {"wu",21,80}
////    };
////    // 3. 给结构体中的元素赋值
////    stuArray[2].name = "liu";
////    stuArray[2].age = 19;
////    stuArray[2].score = 70;
////    // 4. 遍历结构体数组
////    for (int i=0; i < 3; i++){
////        cout << "name = " << stuArray[i].name
////        << "; age = " << stuArray[i].age
////        << "; score = " << stuArray[i].score << endl;
////    }
//
//
////    // 1. 创建学生结构体变量
////    struct Student s = {"zs", 18, 100};
////    // 2. 通过指针指向结构
////    struct Student * p = &s;
////    // 3. 通过指针访问结构体变量中的数据
////    // 结构体指针访问结构体变量 使用 ->
////    cout << "name= " << p->name << "; age = " << p->age << "; score = " << p->score;
//
//
////    // 结构体嵌套结构体
////    // 创建老师
////    teacher t1;
////    t1.id = 1000;
////    t1.name = "zs";
////    t1.age = 40;
////    t1.stu.name = "wang";
////    t1.stu.age = 19;
////    t1.stu.score = 100;
////
////    cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
////    cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;
//
//
////    // 结构体作函数参数
////    struct student stu;
////    stu.name = "zs";
////    stu.age = 19;
////    stu.score = 100;
////    cout << "姓名：" << stu.name << " 年龄： " << stu.age  << " 分数：" << stu.score << endl;
////
////    printStudent1(stu);
////    printStudent2(&stu);
//
//
//    // 设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
//    // 通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
//    struct hero heroArray[5] = {
//            {"刘备",23,"男"},
//            {"关羽",22,"男"},
//            {"张飞",20,"男"},
//            {"赵云",21,"男"},
//            {"貂蝉",19,"女"},
//    };
//    int len = sizeof(heroArray) / sizeof(hero); //获取数组元素个数
//
//    bubbleSort(heroArray, len); //排序
//
//    printHeroes(heroArray, len); //打印
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//    return 0;
//}