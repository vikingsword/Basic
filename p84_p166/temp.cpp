//#include "iostream"
//
//using namespace std;
//
//#include "string"
//
//#define MAX 1000
////设计联系人结构体
//struct Person {
//    string m_Name;
//    int m_Sex;
//    int m_Age;
//    string m_Phone;
//    string m_Addr;
//};
//struct Addressbooks {
////    通讯录中保存的联系人数组
//    struct Person personArray[MAX];
//// 通讯录中当前记录联系人个数
//    int m_Size;
//};
//
////1.添加联系人
//void addPerson(Addressbooks *abs) {
//    //判断通讯录是否已满，如果满了就不在添加
//    if (abs->m_Size == MAX) {
//        cout << "通讯录已满，无法添加，宝宝" << endl;
//    } else {
//        //添加具体联系人
//        string name;
//        cout << "请输入姓名" << endl;
//        cin >> name;
//        abs->personArray[abs->m_Size].m_Name = name;
//
//        //性别
//
//        cout << "请输入性别：" << endl;
//        cout << "1____男" << endl;
//        cout << "2____女" << endl;
//        int sex = 0;
//
//        while (true) {
//            cin >> sex;
//            if (sex == 1 || sex == 2) {
//                abs->personArray[abs->m_Size].m_Sex = sex;
//                break;
//            }
//            cout << "输入有误，傻逼，请重新输入别再错了奥" << endl;
//        }
//        //年龄
//        cout << "请输入年龄；" << endl;
//        int age = 0;
//        cin >> age;
//        abs->personArray[abs->m_Size].m_Age = age;
//
//        //住址
//        cout << "请输入住址" << endl;
//        string address;
//        cin >> address;
//        abs->personArray[abs->m_Size].m_Addr = address;
//
//        //更新通讯录人数
//        abs->m_Size++;
//        cout << "添加成功" << endl;
//
//        system("pause");//请按任意键结束
//        system("cls");//清屏操作
//    }
//}
//
////2.显示所有联系人
//void showPerson(Addressbooks *abs) {
////判断通讯录中人数是否为0，如果为0提示记录为空
////如果不为0，显示记录的联系人信息
//    if (abs->m_Size == 0) {
//        cout << "当前记录为空" << endl;
//    } else {
//        for (int i = 0; i < abs->m_Size; ++i) {
//            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
//            cout << "性别：" << abs->personArray[i].m_Sex << "\t";
//            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
//            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
//            cout << "住址：" << abs->personArray[i].m_Addr << endl;
//        }
//    }
//}
//
////检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
////参数1  通讯录  参数2  对比姓名
//int isExist(Addressbooks *abs, string name) {
//    for (int i = 0; i < abs->m_Size; ++i) {
//        //找到用户输入的姓名了
//        if (abs->personArray[i].m_Name == name) {
//            return i;
//        }
//    }
//    return -1;
//}
//
////3.删除指定联系人
//void deletePerson(Addressbooks *abs) {
//    cout << "请输入宁要删除的联系人" << endl;
//    string name;
//    cin >> name;
//    int ret = isExist(abs, name);
//}
//
////菜单页面
//void showMenu() {
//    cout << "*********************" << endl;
//    cout << "*****1、添加联系人*****" << endl;
//    cout << "*****2、显示联系人*****" << endl;
//    cout << "*****3、删除联系人*****" << endl;
//    cout << "*****4、查找联系人*****" << endl;
//    cout << "*****5、修改联系人*****" << endl;
//    cout << "*****6、清空联系人*****" << endl;
//    cout << "*****0、退出联系人*****" << endl;
//    cout << "*********************" << endl;
//}
//
//int main() {
//
//    //创建通讯录结构体变量
//    Addressbooks abs;
//    //初始化通讯录中当前人员个数
//    abs.m_Size = 0;
//    int select = 0;
//    showMenu();
//
//    while (true) {
//        cin >> select;
//        switch (select) {
//            case 1://添加联系人
//                addPerson(&abs);
//                break;
//            case 2://显示联系人
//                showPerson(&abs);
//                break;
//            case 3://删除联系人
//            {
//                cout << "请输入删除联系人姓名" << endl;
//                string name;
//                cin >> name;
//                break;
//            }
//
////            case 4:
////                break;
////            case 5:
////                break;
////            case 6:
////                break;
////            case 0:
////                cout << "欢迎下次光临，尊敬的宝宝，手牌请拿好" << endl;
////                system("pause");
//            default:
//                break;
//
//        }
//    }
//
//
//    system("pause");
//    return 0;
//}