//#include "iostream"
//#include "cmath"
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
//    return exp(x) - 5 * x;
//}
//
//auto roundToThreeDecimal = [](double value) {
//    return round(value * 1000.0) / 1000.0;
//};
//
//
//int main() {
//
//    // precision
//    cout << "input ε : ";
//    double k;
//    cin >> k;
//
//    cout << "input a: ";
//    double a;
//    cin >> a;
//    cout << "input b: ";
//    double b;
//    cin >> b;
//
//    int count  = 1;
//
//    while (true) {
//
//        cout << "第 " << count << " 轮" << endl;
//
//        double left = a + 0.382 * (b - a);
//        left = roundToThreeDecimal(left);
//        double right = a + 0.618 * (b - a);
//        right = roundToThreeDecimal(right);
//
//        double res1 = roundToThreeDecimal(getRes(left));
//        double res2 = roundToThreeDecimal(getRes(right));
//
//        cout << "a = " << a << endl;
//        cout << "b = " << b << endl;
//
//        cout << "λ = " << left << endl;
//        cout << "μ = " << right << endl;
//
//        cout << "ψ(λ) = " << res1 << endl;
//        cout << "ψ(μ) = " << res2 << endl;
//
//        cout << "b - a = " << b - a << endl;
//
//        double abs_diff = abs(b -a);
//
//        if (abs_diff < k) {
//            double result = (a + b) / 2;
//            cout << "result = " << result << endl;
//            break;
//        }
//
//        if (res1 < res2) {
//            b = right;
//        } else {
//            a = left;
//        }
//
//        count++;
//
//    }
//}