#include "iostream"

using namespace std;

/**
* @author: vikingar
* @time: 2023/11/12 21:52
* @description:  
*/
int main() {
    // 从键盘输入 10 个整数
    int numbers[10];
    for (int i = 0; i < 10; ++i) {
        printf("请输入第%d个整数：", i + 1);
        scanf("%d", &numbers[i]);
    }

    // 输入一个整数赋值给变量 X
    int x;
    printf("请输入变量 X 的值：");
    scanf("%d", &x);

    // 划分顺序表
    int left_part[10], right_part[10];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < 10; ++i) {
        if (numbers[i] < x) {
            left_part[left_count++] = numbers[i];
        } else {
            right_part[right_count++] = numbers[i];
        }
    }

    // 输出划分后的结果
    printf("左半部分: ");
    for (int i = 0; i < left_count; ++i) {
        printf("%d ", left_part[i]);
    }

    printf("\n右半部分: ");
    for (int i = 0; i < right_count; ++i) {
        printf("%d ", right_part[i]);
    }

    return 0;
}
