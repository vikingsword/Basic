#include "iostream"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/24 20:18
* @description: how cpp work
*/
void log(const char * message) {
    cout << message << endl;
}
void temp01() {
    log("hello vikingar");
    cin.get();
}
int main() {

    temp01();

    return 0;
}