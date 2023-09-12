#include "iostream"
#include <fstream>
using namespace std;

/**
* @author: vikingar
* @time: 2023/9/12 8:01
* @description: c++中的文件操作
*/

// 写文件
void test01() {

    ofstream ofs;
//    ofs.open("E:\\Dev\\C++\\Project\\Practice\\Basic\\p84\\file\\demo.txt", ios::out);
//    ofs.open("..//file//demo.txt", ios::out);
    ofs.open("./p84/file/demo.txt", ios::out);
    ofs << "hello vikingar! " << endl;
    ofs.close();

}

// 读文件
void test02(){
    ifstream ifs;
    ifs.open("./p84/demo.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "文件未打开成功" << endl;
        return;
    }

//    // 读数据
//    // 方式一
//    char buf[1024] = {0};
//    while (ifs >> buf) {
//        cout << buf << endl;
//    }

//    // 方式二
//    char buf[1024] = {0};
//    while (ifs.getline(buf, sizeof(buf))) {
//        cout << buf << endl;
//    }

//    // 第三种
//    string buf;
//    while (getline(ifs, buf)) {
//        cout << buf << endl;
//    }

//    // 第四种，不推荐
//    char c;
//    while ((c = ifs.get()) != EOF) {
//        cout << c;
//    }


    ifs.close();

}



/**
 * 二进制写文件
 */
class Person{
public:
    // 最好不要用string
    char m_Name[64];
    int m_Age;
};
void test03() {
    // 将两步合成一步
//    ofstream ofstream1("demo1.txt", ios::out | ios::binary);
    ofstream ofs;
    ofs.open("./p84/demo.txt", ios::out | ios::binary);
    Person p = {"zs", 21};
    ofs.write((const char *) &p, sizeof(Person));

    ofs.close();

}


/**
 * 二进制读文件
 * @return
 */

void test04(){

    ifstream ifs;
    ifs.open("./p84/demo.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
    }

    // 读文件
    Person p;
    ifs.read((char *) &p, sizeof(Person));
    cout << "name = " << p.m_Name << "; age = " << p.m_Age << endl;

    ifs.close();


}













int main() {

//    test01();

//    test02();

//    test03();

    test04();

    return 0;
}