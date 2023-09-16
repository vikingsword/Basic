//#include "iostream"
//
//using namespace std;
//
///**
//* @author: vikingar
//* @time: 2023/9/15 21:30
//* @description:  string 相关函数
//*/
//
///**
// * string 构造函数
// * string();         			    //创建一个空的字符串 例如: string str;
// * string(const char* s);	        //使用字符串s初始化
// * string(const string& str);       //使用一个string对象初始化另一个string对象
// * string(int n, char c);           //使用n个字符c初始化
// */
//void test01() {
//    string s1;
//    cout << "str1 = " << s1 << endl;
//
//    const char *str = "hello world";
//    string s2(str);
//    cout << "str2 = " << s2 << endl;
//
//    string s3(s2);
//    cout << "str3 = " << s3 << endl;
//
//    string s4(10, 'a');
//    cout << "str4 = " << s4 << endl;
//}
//
//
///**
// * string 赋值操作
// * string& operator=(const char* s);             //char*类型字符串 赋值给当前的字符串
// * string& operator=(const string &s);         //把字符串s赋给当前的字符串
// * string& operator=(char c);                          //字符赋值给当前的字符串
// * string& assign(const char *s);                  //把字符串s赋给当前的字符串
// * string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
// * string& assign(const string &s);              //把字符串s赋给当前字符串
// * string& assign(int n, char c);                  //用n个字符c赋给当前字符串
// */
//void test02() {
//    string str1 = "abc";
//    cout << "str1 = " << str1 << endl;
//
//    string str2;
//    str2 = str1;
//    cout << "str2 = " << str2 << endl;
//
//    string str3;
//    str3 = 'a';
//    cout << "str3 = " << str3 << endl;
//
//    string str4;
//    str4.assign(str1);
//    cout << "str4 = " << str4 << endl;
//    str4.assign("hello vikingar");
//    cout << "str4 = " << str4 << endl;
//
//    string str5;
//    str5.assign("vikingar", 3);
//    cout << "str5 = " << str5 << endl;
//
//    string str6;
//    str6.assign(10, 'a');
//    cout << "str6 = " << str6 << endl;
//
//}
//
//
///**
// * string 字符串拼接
// * string& operator+=(const char* str);                  //重载+=操作符
// * string& operator+=(const char c);                     //重载+=操作符
// * string& operator+=(const string& str);                //重载+=操作符
// * string& append(const char *s);                        //把字符串s连接到当前字符串结尾
// * string& append(const char *s, int n);                 //把字符串s的前n个字符连接到当前字符串结尾
// * string& append(const string &s);                      //同operator+=(const string& str)
// * string& append(const string &s, int pos, int n);      //字符串s中从pos开始的n个字符连接到字符串结尾
// */
//void test03() {
//    string s1 = "I ";
//    s1 += "like sleeping";
//    cout << "s1 = " << s1 << endl;
//
//    s1 += ':';
//    cout << "s1 = " << s1 << endl;
//
//    string s2 = "anywhere";
//    s1 += s2;
//    cout << "s1 = " << s1 << endl;
//
//    string s3 = "I";
//    s3.append(" like eating ");
//    s3.append("apple girl", 6);
//    s3.append(s2, 4, 4);
//    cout << "s3 = " << s3 << endl;
//
//}
//
//
///**
// * string 查找和替换
// * int find(const string& str, int pos = 0) const;              //查找str第一次出现位置,从pos开始查找
// * int find(const char* s, int pos = 0) const;                  //查找s第一次出现位置,从pos开始查找
// * int find(const char* s, int pos, int n) const;               //从pos位置查找s的前n个字符第一次位置
// * int find(const char c, int pos = 0) const;                   //查找字符c第一次出现位置
// * int rfind(const string& str, int pos = npos) const;          //查找str最后一次位置,从pos开始查找
// * int rfind(const char* s, int pos = npos) const;              //查找s最后一次出现位置,从pos开始查找
// * int rfind(const char* s, int pos, int n) const;              //从pos查找s的前n个字符最后一次位置
// * int rfind(const char c, int pos = 0) const;                  //查找字符c最后一次出现位置
// * string& replace(int pos, int n, const string& str);          //替换从pos开始n个字符为字符串str
// * string& replace(int pos, int n,const char* s);               //替换从pos开始的n个字符为字符串s
// */
//void test04() {
//    string str1 = "abcdefgde";
//    int pos = str1.find("de");
//    if (pos == -1) {
//        cout << "not found " << endl;
//    } else {
//        cout << "pos = " << pos << endl;
//    }
//
//    int pos2 = str1.find('e');
//    cout << "pos2 = " << pos2 << endl;
//
//    int pos3 = str1.find('e', 2);
//    cout << "pos3 = " << pos3 << endl;
//
//    str1.replace(1, 3, "1111");
//    cout << "str1 = " << str1 << endl;
//
//}
//
//
///**
// * string 字符串比较
// * int compare(const string &s) const;    //与字符串s比较
// * int compare(const char *s) const;      //与字符串s比较
// */
//void test05() {
//    string s1 = "hello";
//    string s2 = "aello";
//    string s3 = "hello";
//
//    int ret = s1.compare(s2);
//    if (ret == 0) {
//        cout << "s1 == s2" << endl;
//    } else if (ret > 0) {
//        cout << "s1 > s2" << endl;
//    } else {
//        cout << "s1 < s2" << endl;
//    }
//}
//
//
///**
// * string 字符串存取
// * char& operator[](int n);                 //通过[]方式取字符
// * char& at(int n);                         //通过at方法获取字符
// */
//void test06() {
//    string str = "hello world";
//    for (int i = 0; i < str.size(); ++i) {
//        cout << str[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < str.size(); ++i) {
//        cout << str.at(i) << " ";
//    }
//    cout << endl;
//
//    // 字符串修改
//    str[0] = 'x';
//    str.at(1) = 'j';
//    cout << "str after modify : " << str << endl;
//
//}
//
//
///**
// * string 字符串插入和删除
// * string& insert(int pos, const char* s);             //插入字符串
// * string& insert(int pos, const string& str);         //插入字符串
// * string& insert(int pos, int n, char c);             //在指定位置插入n个字符c
// * string& erase(int pos, int n = npos);               //删除从Pos开始的n个字符
// */
//void test07() {
//    string str = "hello";
//    string str2 = "111";
//    str.insert(1, str2);
//    cout << str << endl;
//
//    string str3 = "hello2";
//    str3.insert(1, 3, 'a');
//    cout << str3 << endl;
//
//    str3.erase(1, 3);
//    cout << str3 << endl;
//}
//
//
///**
// * string 子串
// * string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串
// */
//void test08() {
//    string str = "hello world";
//    string substr = str.substr(0, 5);
//    cout << "substr = " << substr << endl;
//
//    string str2 = "vikingar";
//    str2.append(" ").append("sword");
//    cout << "str2 = " << str2 << endl;
//
//    string email = "vikingar@gmail.com";
//    int pos = email.find("@");
//    string name = email.substr(0, pos);
//    cout << "name = " << name << endl;
//
//    string email2 = "vikingar@gmail.com";
//    int pos2 = email2.find(".");
//    cout << pos2 << endl;
//    string email_name = email2.substr(pos + 1, pos2 - pos - 1);
//    cout << email_name;
//}
//
//
//int main() {
//
////    test01();
//
////    test02();
//
////    test03();
//
////    test04();
//
////    test05();
//
////    test06();
//
////    test07();
//
//    test08();
//
//
//    return 0;
//}