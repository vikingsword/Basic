#include "iostream"
#include "headers/worker.h"
#include "headers/employee.h"
#include "headers/manager.h"
#include "headers/boss.h"

using namespace std;

/**
* @author: vikingar
* @time: 2023/9/12 21:52
* @description:  
*/

void test() {
    Worker *worker = NULL;
    worker = new Employee(1,"zs",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2, "ls", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "wu", 3);
    worker->showInfo();
    delete worker;


}


int main() {

    test();

    return 0;
}


