//#include "iostream"
//using namespace std;
//
//void swap(int a, int b){
//    int temp = a;
//    a = b;
//    b = temp;
//
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//}
//
//void swap2(int * p1, int * p2){
//    int temp = *p1;
//    *p1 = *p2;
//    *p2 = temp;
//
//    cout << "*p1 = " << *p1 << endl;
//    cout << "*p2 = " << *p2 << endl;
//}
//
////冒泡排序函数
//void bubbleSort(int * arr, int len)  //int * arr 也可以写为int arr[]
//{
//    for (int i = 0; i < len - 1; i++)
//    {
//        for (int j = 0; j < len - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
////打印数组函数
//void printArray(int arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << arr[i] << endl;
//    }
//}
//
//int main(){
//
////    // 1. 定义指针
////    int a = 10;
////    // 指针定义的语法： 数据类型 * 指针变量名，指针的类型为： int*（int *）
////    int * p;
////    // 让指针记录变量 a 的地址
////    p = &a;
////    cout << "a 的地址为： " << &a << endl;
////    cout << "指针 p 为： " << p << endl;
////
////    int b = 10;
////    int * q = &b;
////    cout << "b 的地址为： " << &b << endl;
////    cout << "指针 q 为：" << q << endl;
////
////    // 2. 指针的使用
////    // 可以通过解引用的方式来找到指针指向的内存
////    // 指针前加 * 代表解引用， 找到指针指向的内存中的数据
////    cout << *p << endl;
////    *p = 100;
////    cout << "a = " << a << endl;
////    cout << "*p = " << *p << endl;
//
//
////    int b = 10;
////    int * p = &b;
////    cout << "int 指针所占的内存大小： " << sizeof(int *) << endl;
////    cout << "float 指针所占的内存大小： " << sizeof(float *) << endl;
////    cout << "double 指针所占的内存大小： " << sizeof(double *) << endl;
//
//
////    // 空指针： 指向内存编号为 0 的指针
////    //用途：初始化指针变量
////    //注意：空指针指向的内存是不可以访问的
////    int * p = NULL;
////    // 空指针无法进行访问
////    // 0-255 之间的编号是系统占用的，因此无法访问
////    *p = 100;
////    cout << *p << endl;
//
//
////    // 野指针: 指针变量指向非法的内存空间
////    // 在程序中要避免野指针
////    int * p = (int *)0x1100;
////    cout << *p << endl;
//
//
////    // const
////    // 技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量
////    // const 后跟 int * 表示值（int *）是常量 ，说明值不能改
////    // const 后跟 p 表示指针的地址（p）是常量，说明指针的位置不能改
////    // 1. const 修饰指针： 常量指针
////    int a = 10;
////    int b = 10;
////    const int * p = &a;
////    // 指针指向的值不可以修改，指针指向的位置可以改
//////    *p = 20; //错误
//////    p = &b;  //正确
////
////    // 2. const 修饰常量： 指针常量
////    int * const q = &a;
////    // 指针的指向不可以改，指针指向的值可以改
//////    *q = 20;//正确
//////    q = &b;//错误
////
////    // 3. const 修饰指针和常量：
////    const int * const m = &a;
//////    *m = 20;// 错误
//////    m = &b;// 错误
//
//
////    // 指针和数组： 利用指针访问数组中元素
////    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
////    int * p = arr;
////    cout << "第一个元素： " << arr[0] << endl;
////    cout << "指针访问第一个元素： " << *p << endl;
////    // 让指向向后偏移四个字节
////    p++;
////    cout << "指针指向第二个元素： " << *p << endl;
////
////    int * p2 = arr;
////    cout << "遍历 arr 的结果为： ";
////    for (int i=0; i < 10; i++){
//////        cout << *p2 << "\t";
//////        *p2++;
////        cout << *p2++ << "\t";
////    }
//
//
////    // 指针和函数
////    // 1. 值传递
////    int a = 10;
////    int b = 20;
////    swap(a,b);
////
////    // 2. 地址传递
////    // 地址传递可以修改变量值
////    int a1 = 10;
////    int a2 = 20;
////    swap2(&a1, &a2);
////    cout << "a1 = " << a1 << endl;
////    cout << "a2 = " << a2 << endl;
//
//
////    // 冒泡排序
////    int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
////    int len = sizeof(arr) / sizeof(int);
////    bubbleSort(arr,len);
////    printArray(arr, len);
//
//
//
//
//
//    return 0;
//
//
//}