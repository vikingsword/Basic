#include "iostream"
#include "./headers/log.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/24 20:18
* @description: p5 how cpp work、 link
*/

void log(const char * message);
// 如果没有调用temp01(), main() 中没有 temp01() 那么在 build 的时候也会报错
// 编译器可能会认为它是在别的地方被调用， 如果想告诉编译器只在这个文件调用，就加上 static 关键字
static void temp01() {
    log("hello vikingar");
    cin.get();
}


int main() {

    temp01();

    return 0;
}