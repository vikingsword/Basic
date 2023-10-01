//#include "iostream"
//#include "cmath"
//#include "iomanip"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/10/1 11:17
//* @description:  f(x) = e^x - 5x
//*/
//
//double getRes(double x) {
//    double e = exp(1.0);
//    double res = pow(e, x) - 5 * x;
//    return res;
//}
//
//int main() {
//
//    while (true) {
//        cout << "input a: ";
//        double a = 1.0;
//        cin >> a;
//        cout << "input b: ";
//        double b = 1.0;
//        cin >> b;
//
//        double left = a + 0.382 * (b - a);
//        left = round(left * 1000.0) / 1000.0;
//        double right = a + 0.618 * (b - a);
//        right = round(right * 1000.0) / 1000.0;
//
//        double res1 = getRes(left);
//        res1 = round(res1 * 1000.0) / 1000.0;
//        double res2 = getRes(right);
//        res2 = round(res2 * 1000.0) / 1000.0;
//
//        cout << "λ = " << left << endl;
//        cout << "μ = " << right << endl;
//
//        cout << "ψ(λ) = " << res1 << endl;
//        cout << "ψ(μ) = " << res2 << endl;
//
//        cout << "b - a = " << b - a << endl;
//
//        if (a == 0.0) {
//            break;
//        }
//    }
//}