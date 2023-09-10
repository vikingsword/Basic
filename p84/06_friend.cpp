//#include "iostream"
//using namespace std;
//
//
//class Room{
//public:
//    // friend 关键字 可以访问 类中的私有成员
//    friend void open_door(Room *r);
//
//
//public:
//    string m_livingRoom;
//
//private:
//    string m_bedRoom;
//
//
//public:
//    Room(){
//        m_livingRoom = "living room";
//        m_bedRoom = "bed room";
//    }
//
//};
//
//// 全局函数访问类中的私有变量
//void open_door(Room *r){
//    cout << "good man is opening " << r->m_livingRoom << endl;
//
//    cout << "friends is opening " << r->m_bedRoom << endl;
//}
//
//
//
//// 类做友元
//class Building;
//class goodGay
//{
//public:
//
//    goodGay();
//    void visit();
//
//private:
//    Building *building;
//};
//
//
//class Building
//{
//    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
//    friend class goodGay;
//
//public:
//    Building();
//
//public:
//    string m_SittingRoom; //客厅
//private:
//    string m_BedRoom;//卧室
//};
//
//Building::Building()
//{
//    this->m_SittingRoom = "客厅";
//    this->m_BedRoom = "卧室";
//}
//
//goodGay::goodGay()
//{
//    building = new Building;
//}
//
//void goodGay::visit()
//{
//    cout << "好基友正在访问" << building->m_SittingRoom << endl;
//    cout << "好基友正在访问" << building->m_BedRoom << endl;
//}
//
//void test01()
//{
//    goodGay gg;
//    gg.visit();
//
//}
//
//
//
////cout << "好基友正在访问" << building->m_BedRoom << endl;
////class Building;
////class goodGay
////{
////public:
////
////    goodGay();
////    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
////    void visit2();
////
////private:
////    Building *building;
////};
////
////
////class Building
////{
////    //告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
////    friend void goodGay::visit();
////
////public:
////    Building();
////
////public:
////    string m_SittingRoom; //客厅
////private:
////    string m_BedRoom;//卧室
////};
////
////Building::Building()
////{
////    this->m_SittingRoom = "客厅";
////    this->m_BedRoom = "卧室";
////}
////
////goodGay::goodGay()
////{
////    building = new Building;
////}
////
////void goodGay::visit()
////{
////    cout << "好基友正在访问" << building->m_SittingRoom << endl;
////    cout << "好基友正在访问" << building->m_BedRoom << endl;
////}
////
////void goodGay::visit2()
////{
////    cout << "好基友正在访问" << building->m_SittingRoom << endl;
////    //cout << "好基友正在访问" << building->m_BedRoom << endl;
////}
////
////void test01()
////{
////    goodGay  gg;
////    gg.visit();
////
////}
//
//
//
//int main(){
//
////    Room r;
////    open_door(&r);
//
//}