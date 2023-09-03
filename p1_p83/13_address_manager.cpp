/**
* 通讯录管理系统：
* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
* 显示联系人：显示通讯录中所有联系人信息
* 删除联系人：按照姓名进行删除指定联系人
* 查找联系人：按照姓名查看指定联系人信息
* 修改联系人：按照姓名重新修改指定联系人
* 清空联系人：清空通讯录中所有信息
* 退出通讯录：退出当前使用的通讯录
*/
# include "iostream"
using namespace std;
#define MAX 1000


// 展示菜单
void showMenu(){
    cout << "1. 添加联系人" << endl;
    cout << "2. 显示联系人" << endl;
    cout << "3. 删除联系人" << endl;
    cout << "4. 查找联系人" << endl;
    cout << "5. 修改联系人" << endl;
    cout << "6. 清空联系人" << endl;
    cout << "0. 退出通讯录" << endl;

}

struct Person{
    string m_Name; //姓名
    int m_Sex; //性别：1男 2女
    int m_Age; //年龄
    string m_Phone; //电话
    string m_Addr; //住址
};

//通讯录结构体
struct Addressbooks{
    struct Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_Size; //通讯录中人员个数
};


void addPerson(Addressbooks * abs){
    if (abs->m_Size == MAX) {
        cout << "通讯录满了，无法添加" << endl;
        return;
    } else {
        // 添加 联系人
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;

        //性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //联系电话
        cout << "请输入联系电话：" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //更新通讯录人数
        abs->m_Size++;

        cout << "添加成功" << endl;
        system("pause");
        system("cls");
    }
}

void showPerson(Addressbooks * abs){
    if (abs->m_Size == 0) {
        cout << "当前记录为空 " << endl;
    } else{
        for (int i=0; i < abs->m_Size; i++){
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

//判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

//3、删除指定联系人信息
void deletePerson(Addressbooks * abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}


//4、查找指定联系人信息
void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");

}

//5、修改指定联系人信息
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;

        //性别
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //联系电话
        cout << "请输入联系电话：" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");

}

// 清空联系人
void clearPerson(Addressbooks * abs){
    abs->m_Size = 0;
    cout << "通讯录已经清空" << endl;
    system("pause");
    system("cls");
}


int main(){

    Addressbooks abs;

    abs.m_Size = 0;

    // 用户输入的变量
    int select = 0;

    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
            case 1:  //添加联系人
                addPerson(&abs);
                break;
            case 2:  //显示联系人
                showPerson(&abs);
                break;
            case 3:  //删除联系人
                deletePerson(&abs);
                break;
            case 4:  //查找联系人
                findPerson(&abs);
                break;
            case 5:  //修改联系人
                modifyPerson(&abs);
                break;
            case 6:  //清空联系人
                clearPerson(&abs);
                break;
            case 0:  //退出通讯录
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }


}