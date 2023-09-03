//#include "iostream"
//using namespace std;
//
//
///**
// * 1. 数据类型  数组名[ 数组长度 ];
// * 2. 数据类型  数组名[ 数组长度 ] = { 值1，值2 ...};
// * 3. 数据类型  数组名[ ] = { 值1，值2 ...};
// */
//int main(){
//
////     int arr[5];
////     arr[0] = 10;
////     arr[1] = 20;
////     arr[2] = 30;
////     arr[3] = 40;
////     arr[4] = 50;
////
////     for (int i=0; i < 5; i++){
////         cout << arr[i] << endl;
////     }
//
////    int arr[5] = {1,2,3,4,5};
////    for (int i=0; i < 5; i++){
////        cout << arr[i] << endl;
////    }
////    int arr2[5]  = {1,2,3};
////    for (int j=0; j < 5; j++){
////        cout << arr2[j] << endl;
////    }
//
////    int arr[] = {1,2,3,4,5,6};
////    for (int i=0; i < 6; i++){
////        cout << arr[i] << endl;
////    }
//
//
////    //数组名用途
////    //1、可以获取整个数组占用内存空间大小
////    int arr[10] = { 1,2,3,4,5,6,7,8,9,10};
////
////    cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;
////    cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;
////    cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
////
////    //2、可以通过数组名获取到数组首地址
////    cout << "数组首地址为： " << arr << endl;
////    cout << "数组首地址为： " << (long long)arr << endl;
////    cout << "数组中第一个元素地址为： " << &arr[0] << endl;
////    cout << "数组中第一个元素地址为： " << (long long)&arr[0] << endl;
////    cout << "数组中第二个元素地址为： " << &arr[1] << endl;
////    cout << "数组中第二个元素地址为： " << (long long)&arr[1] << endl;
//
//
////    // 找出数组中的最大值
////    int arr[5] = {300,350,200,400,250};
////    int max = arr[0];
////    for (int i=0; i < sizeof(arr)/ sizeof(arr[0]); i++){
////        if (max < arr[i]) {
////            max = arr[i];
////        }
////    }
////    cout << "max =  " << max <<  endl;
//
//
////    // 数组元素逆置
////    int arr[] = {1,3,2,5,4};
////    int n = (sizeof(arr)/ sizeof(arr[0]));
////    for (int i=0; i < n/2; i++){
////        int temp = 0;
////        int last = n - 1 -i;
////        temp = arr[i];
////        arr[i] = arr[last];
////        arr[last] = temp;
////    }
////    for(int j=0; j < n; j++){
////        cout << "arr[j] = " << arr[j] << endl;
////    }
//
//
////    // 冒泡排序: 小 -> 大
////    int arr[9] = { 4,2,8,0,5,7,1,3,9};
////    int n = sizeof(arr) / sizeof(arr[0]);
////    // i 为排序次数
////    for(int i=0; i < n - 1; i++){
////        // j 为每次比较元素位置
////        for (int j=0; j < n - i - 1; j++){
////            if (arr[j] > arr[j + 1]){
////                int temp = arr[j];
////                arr[j] = arr[j+1];
////                arr[j+1]  = temp;
////            }
////        }
////    }
////    for (int i=0; i < n; i++){
////        cout << arr[i] << endl;
////    }
//
//
////    // 二维数组
////    //方式1
////    //数组类型 数组名 [行数][列数]
////    int arr[2][3];
////    arr[0][0] = 1;
////    arr[0][1] = 2;
////    arr[0][2] = 3;
////    arr[1][0] = 4;
////    arr[1][1] = 5;
////    arr[1][2] = 6;
////    for (int i=0;i < 2; i++){
////        for (int j=0; j < 3; j++){
////            cout << arr[i][j] << endl;
////        }
////    }
//
////    //方式2
////    //数据类型 数组名[行数][列数] = { {数据1，数据2 } ，{数据3，数据4 } };
////    int arr[2][3] = {
////            {1,2,3},
////            {4,5,6}
////    };
////    for (int i=0;i < 2; i++){
////        for (int j=0; j < 3; j++){
////            cout << arr[i][j] << " ";
////        }
////        cout << endl;
////    }
//
////    //方式3
////    //数据类型 数组名[行数][列数] = { 数据1，数据2 ,数据3，数据4  };
////    int arr[2][3] = {1,2,3,4,5,6};
////    for (int i=0;i < 2; i++){
////        for (int j=0; j < 3; j++){
////            cout << arr[i][j] << " ";
////        }
////        cout << endl;
////    }
//
////    // 方式4
////    // 数据类型 数组名[][列数] = { 数据1，数据2 ,数据3，数据4  };
////    // 只写行数无法准确寻址，所有的数据可以都在同一行
////    int arr[][3] = {1,2,3,4,5,6};
////    for (int i=0;i < 2; i++){
////        for (int j=0; j < 3; j++){
////            cout << arr[i][j] << " ";
////        }
////        cout << endl;
////    }
//
////    //二维数组数组名
////    //* 查看二维数组所占内存空间
////    int arr[2][3] = {
////            {1,2,3},
////            {4,5,6}
////    };
////    cout << sizeof(arr) << endl;
////    cout << sizeof(arr[0]) << endl;
////    cout << sizeof(arr[0][0]) << endl;
////    int raw = sizeof(arr) / sizeof(arr[0]);
////    int column = sizeof(arr[0]) / sizeof(arr[0][0]);
////    cout << "行数： " << raw << endl;
////    cout << "列数： " << column << endl;
////
////    //* 获取二维数组首地址
////    cout << &arr[0][0] << endl;
////    cout << &arr << endl;
////    cout << (long long)&arr << endl;
////    cout << &arr[0][0] << endl;
////    cout << (long long)&arr[0][0] << endl;
////    cout << (long long)&arr[1] << endl;
//
//
////    string name[] = {"张三", "李四", "王五"};
////    int scores[3][3] = {
////            {100, 100, 100},
////            {90, 50, 100},
////            {60, 70, 80},
////    };
////    for (int i=0; i < 3; i++){
////        int sum = 0;
////        for (int j=0; j < 3; j++){
////            sum += scores[i][j];
////        }
////        cout << name[i] << " 的总成绩为 " << sum << endl;
////    }
//
//
//
//    return 0;
//
//
//}