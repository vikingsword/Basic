// 在编译器预处理阶段，它会检查头文件是否已经被包含，如果已经包含过了，就不会再次包含
#pragma once
#include "iostream"
#include "point.h"
using namespace std;

class Circle2 {

private:
    int m_R;
    Point m_center;

public:

    void set_r(int r);

    int get_r();

    void set_center(Point center);

    Point get_center();

};