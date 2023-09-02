#include "iostream"
using namespace std;


/**
 * 1. 数据类型  数组名[ 数组长度 ];
 * 2. 数据类型  数组名[ 数组长度 ] = { 值1，值2 ...};
 * 3. 数据类型  数组名[ ] = { 值1，值2 ...};
 */
int main(){

//     int arr[5];
//     arr[0] = 10;
//     arr[1] = 20;
//     arr[2] = 30;
//     arr[3] = 40;
//     arr[4] = 50;
//
//     for (int i=0; i < 5; i++){
//         cout << arr[i] << endl;
//     }

//    int arr[5] = {1,2,3,4,5};
//    for (int i=0; i < 5; i++){
//        cout << arr[i] << endl;
//    }
//    int arr2[5]  = {1,2,3};
//    for (int j=0; j < 5; j++){
//        cout << arr2[j] << endl;
//    }

//    int arr[] = {1,2,3,4,5,6};
//    for (int i=0; i < 6; i++){
//        cout << arr[i] << endl;
//    }


//    //数组名用途
//    //1、可以获取整个数组占用内存空间大小
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
//
//    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
//    cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
//    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
//
//    //2、可以通过数组名获取到数组首地址
//    cout << "数组首地址为： " << arr << endl;
//    cout << "数组首地址为： " << (long long)arr << endl;
//    cout << "数组中第一个元素地址为： " << &arr[0] << endl;
//    cout << "数组中第一个元素地址为： " << (long long)&arr[0] << endl;
//    cout << "数组中第二个元素地址为： " << &arr[1] << endl;
//    cout << "数组中第二个元素地址为： " << (long long)&arr[1] << endl;


//    // 找出数组中的最大值
//    int arr[5] = {300,350,200,400,250};
//    int max = arr[0];
//    for (int i=0; i < sizeof(arr)/ sizeof(arr[0]); i++){
//        if (max < arr[i]) {
//            max = arr[i];
//        }
//    }
//    cout << "max =  " << max <<  endl;


//    // 数组元素逆置
//    int arr[] = {1,3,2,5,4};
//    int n = (sizeof(arr)/ sizeof(arr[0]));
//    for (int i=0; i < n/2; i++){
//        int temp = 0;
//        int last = n - 1 -i;
//        temp = arr[i];
//        arr[i] = arr[last];
//        arr[last] = temp;
//    }
//    for(int j=0; j < n; j++){
//        cout << "arr[j] = " << arr[j] << endl;
//    }


    // 冒泡排序: 小 -> 大
    int arr[9] = { 4,2,8,0,5,7,1,3,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // i 为排序次数
    for(int i=0; i < n - 1; i++){
        // j 为每次比较元素位置
        for (int j=0; j < n - i - 1; j++){
            int temp = 0;
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }
    for (int i=0; i < n; i++){
        cout << arr[i] << endl;
    }




    return 0;


}