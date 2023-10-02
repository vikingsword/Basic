//#include "iostream"
//#include "deque"
//#include "algorithm"
//#include "ctime"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/10/2 21:04
//* @description:
//*/
//
//void printDq() {
//
//    srand((unsigned int)time(NULL));
//
//    deque<double> d;
//    for (int i = 0; i < 10; ++i) {
//        double elem = (rand() % 401 + 600) / 10.f;
//        d.push_back(elem);
//    }
//
//    sort(d.begin(), d.end());
//    cout << "elem : \t\t";
//    for_each(d.begin(), d.end(), [](double value){cout << value << "  ";});
//
//    cout << endl;
//    cout << "after pop: \t";
//    d.pop_back();
//    d.pop_front();
//    double sum;
//    for_each(d.begin(), d.end(), [&sum](double v){
//        cout << v << "  ";
//        sum += v;
//    });
//    double avg = sum / d.size();
//    cout << endl << "avg = " << avg << endl;
//
//}
//int main() {
//
//    printDq();
//
//    return 0;
//}