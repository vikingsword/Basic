#include "iostream"
#include "cmath"

using namespace std;

/**
* @author: vikingar
* @time: 2023/10/1 11:17
* @description:  f(x) = e^x - 5x
*/

double getRes(double x) {
    double e = exp(1.0);
    double res = pow(e, x) - 5 * x;
    cout << "res = " << res << endl;
    return res;
}

int main() {

    while (true) {
        cout << "input x: ";
        double x = 1.0;
        cin >> x;
        getRes(x);
        if (x == 0.0) {
            break;
        }
    }
}