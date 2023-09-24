///**
// * 案例： 员工分组
// * * 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
// * 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
// * 随机给10名员工分配部门和工资
// * 通过multimap进行信息的插入  key(部门编号) value(员工)
// * 分部门显示员工信息
// *
// * 步骤：
// * 1. 创建10名员工，放到vector中
// * 2. 遍历vector容器，取出每个员工，进行随机分组
// * 3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
// * 4. 分部门显示员工信息
// */
//#include "iostream"
//#include "vector"
//#include "map"
//#include "ctime"
//
//using namespace std;
//
//
//#define CEHUA  0
//#define MEISHU 1
//#define YANFA  2
//
//class Worker {
//public:
//    string m_name;
//    int m_salary;
//};
//
//void createWorker(vector<Worker> &v) {
//    string nameSeed = "ABCDEFGHIJ";
//    for (int i = 0; i < 10; ++i) {
//        Worker worker;
//        worker.m_name = "员工";
//        worker.m_name += nameSeed[i];
//
//        // salary between 10000 - 19999
//        worker.m_salary = rand() % 10000 + 10000;
//        v.push_back(worker);
//
//    }
//}
//
//void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
//    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
//        int deptId = rand() % 3;
//        //将员工插入到分组中
//        //key部门编号，value具体员工
////        m.insert(pair<int, Worker>(deptId, *it));
//        m.insert(make_pair(deptId,(*it)));
//    }
//}
//
//void showWorkerByGroup(multimap<int, Worker> &m) {
//    cout << "策划部门： " << endl;
//
//    multimap<int, Worker>::iterator pos = m.find(CEHUA);
//    int count = m.count(CEHUA);
//    int index = 0;
//    for (; pos != m.end() && index < count; pos++, index++) {
//        cout << "name: " << pos->second.m_name
//             << "; salary: " << pos->second.m_salary << endl;
//    }
//
//    cout << "------------------------" << endl;
//    cout << "美术部门" << endl;
//    pos = m.find(MEISHU);
//    count = m.count(MEISHU);
//    index = 0;
//    for (; pos != m.end() && index < count; pos++, index++) {
//        cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
//    }
//
//    cout << "----------------------" << endl;
//    cout << "研发部门： " << endl;
//    pos = m.find(YANFA);
//    count = m.count(YANFA); // 统计具体人数
//    index = 0;
//    for (; pos != m.end() && index < count; pos++, index++) {
//        cout << "姓名： " << pos->second.m_name << " 工资： " << pos->second.m_salary << endl;
//    }
//
//}
//
//
//int main() {
//
//
//    srand((unsigned int) time(NULL));
//
//    // 1. 创建员工
//    vector<Worker> v;
//    createWorker(v);
//
//    // 2. 员工分组
//    multimap<int, Worker> m;
//    setGroup(v, m);
//
//    // 3. 分组显示员工
//    showWorkerByGroup(m);
//
//    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
//        cout << "姓名： " << it->m_name << " 工资： " << it->m_salary << endl;
//    }
//
//    return 0;
//}