#include "stdio.h"

/**
* @author: vikingar
* @time: 2023/11/12 22:12
* @description:  从键盘输入 10个整数存储在一个顺序表中，再输入一个整数赋值给变量 X，
 * 然后将这个顺序表划分成两部分，其中左半部分的每个整数均小于 x，右半部分的每个整数均大于等于 X。
*/
int main() {

    printf("hello vikingar");

    int arr[10];
    for (int i = 0; i < 10; ++i) {
        printf("please input ten number: ");
        scanf("%d", &arr[i]);
    }

    printf("please input a number x: ");
    int x;
    scanf("%d", x);
    printf("%d", x);

    return 0;
}