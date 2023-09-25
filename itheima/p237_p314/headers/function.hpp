#pragma once
#include "iostream"
#include "vector"

using namespace std;

template<typename T>
void printVector(vector<T> &v) {
    for (T elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}