//#include "iostream"
//#include "ctime"
//using namespace std;
//
//int main(){
//
//    // 顺序结构
//
//
////    // 选择结构
////    // if
////    int score = 0;
////    cout << "please input your score: ";
////    cin >> score;
////    if (score > 60) {
////        cout << "已经及格! " << endl;
////    } else if (score == 60){
////        cout << "刚好及格! " << endl;
////    } else {
////        cout << "未及格! " << endl;
////    }
//
////    // 输入 a b c 求最大值
////    int a =0, b = 0, c = 0;
////    cout << "请输入 a 的值: ";
////    cin >> a;
////    cout << "请输入 b 的值： ";
////    cin >> b;
////    cout << "请输入 c 的值： ";
////    cin >> c;
////    if (a >= b){
////        if (a >= c){
////            cout << "最大值为 a ";
////        } else {
////            cout << "最大值为 c ";
////        }
////    } else {
////        if (b >= c){
////            cout << "最大值为 b";
////        } else {
////            cout << "最大值为 c";
////        }
////    }
//
////    // 三目运算符
////    int a = 1, b = 2;
////    int max  = (a > b) ? a : b;
////    cout << "a, b 中的最大值为： " << max << endl;
//
////    // switch
////    int score = 0;
////    cout << "请给电影打分(1-10): ";
////    cin >> score;
////    switch (score) {
////        case 10:
////        case 9:
////        case 8:
////            cout << "高分" << endl;
////            break;
////        case 7:
////        case 6:
////        case 5:
////            cout << "中等" << endl;
////            break;
////        case 4:
////        case 3:
////        case 2:
////            cout << "低等" << endl;
////            break;
////        default:
////            cout << "awful" << endl;
////            break;
////    }
//
//
////    // 循环结构
////    // while
////    int i = 0;
////    while (i < 10){
////        cout << "i = " <<  i << endl;
////        i++;
////    }
//
////    // 猜数字
////    // srand 要求包含头文件 #include <ctime>
////    srand((unsigned int)time(NULL));
////    int res = rand() % 100 + 1;
////    int guess = -1;
////    cout << "请输入数字: ";
////    while (guess != res){
////        cin >> guess;
////        if (res > guess){
////            cout << "猜小了，请重新输入： ";
////        } else if (res < guess) {
////            cout << "猜大了，请重新输入： ";
////        } else {
////            cout << "猜对了, 恭喜你! ";
////            break;
////        }
////    }
//
////    // do-while
////    int i = 0;
////    do {
////        cout << "i = " << i << endl;
////        i++;
////    } while (i < 10);
//
////    // 水仙花数
////    int i = 100;
////    while (i < 1000) {
////        int num1 = i / 100;
////        int num2 = (i % 100) / 10;
////        int num3 = i % 10;
////        if (num1*num1*num1 + num2*num2*num2 + num3*num3*num3 == i){
////            cout << "i = " << i << endl;
////        }
////        i++;
////    }
////    int j = 100;
////    do{
////        int num1 = j / 100;
////        int num2 = (j % 100) / 10;
////        int num3 = j % 10;
////        if (num1*num1*num1 + num2*num2*num2 + num3*num3*num3 == j){
////            cout << "j = " << j << endl;
////        }
////        j++;
////    }while(j < 1000);
//
////    // for loop
////    for (int i=0; i < 10; i++){
////        cout << "i = " << i << endl;
////    }
//
////    // 案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。
////    for (int i=1; i <= 100; i++){
////        if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0) {
////            cout << "敲桌子" << endl;
////        } else {
////            cout << "i = " << i << endl;
////        }
////    }
//
////    for (int i=0; i < 10; i++){
////        for (int j=0; j < 10; j++){
////            cout << "* ";
////        }
////        cout << "" << endl;
////    }
//
////    for (int i=1; i < 10; i++){
////        for (int j=1; j < 10 && i >= j; j++){
////            cout << i << " * " << j << " = " << i * j << "  ";
////        }
////        cout << "" << endl;
////    }
//
//
////    // 跳转语句
////    // break 使用时机
////    // 1. 出现在switch中
////    cout << "请选择难度 ： " << endl;
////    int select  = 0;
////    cin >> select;
////    switch(select) {
////        case 1:
////            cout << "困难" << endl;
////            break;
////        case 2:
////            cout << "中等" << endl;
////            break;
////        case 3:
////            cout << "轻度" << endl;
////            break;
////        default:
////            cout << "请输入 1 - 3 " << endl;
////            break;
////    }
//
////    // 2. 出现在循环中
////    for (int i=0; i < 10; i++){
////        if (i == 5){
////            break;
////        }
////        cout << "i = " << i << endl;
////    }
//
////    // 3. 出现在嵌套循环中
////    for (int j=0; j < 10; j++) {
////        for (int k=0; k < 10; k++){
////            if (k == 2) break;
////            cout << "j = " << j << ", k = " << k << endl;
////        }
////    }
//
////    // continue
////    for (int i=0; i < 10; i++){
////        if (i == 3){
////            continue;
////        }
////        cout << "i = " << i << endl;
////    }
//
//
//
//
//
//
//    return 0;
//}