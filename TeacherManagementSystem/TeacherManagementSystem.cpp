#include "TeacherManagementSystem.h"
#include <iostream>
#include <fstream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
	login();
	loadData();
}

TeacherManagementSystem::~TeacherManagementSystem()
{
	saveData();
}

void TeacherManagementSystem::start()
{

	while (true) {
		bool back = false;
		__showMainMenu();
		switch (__waitForRequest(2)) {
		case 1: {//进入教师管理菜单
			while (true) {
				bool back = false;
				__showTeacherMenu();
				switch (__waitForRequest(5)) {
				case 1:{//录入新教师
					addTeacher();
					break;
				}
				case 2: {//查询与管理教师
					if (m_teacherList.size() == 0) {
						cout << "请先添加教师！" << endl;
						system("pause");
						break;
					}
					system("cls");
					__printLine();
					__offset("选择教师", 21);
					__printLine();
					__listTeacher();
					cout << "请输入教师ID（返回请输入0）：" ;
					string id;
					cin >> id;

					Teacher *p;

					while (!(p=__getTeacherById(id)) && id != "0") {
						system("cls");
						__printLine();
						__offset("选择教师", 21);
						__printLine();
						cout << "ID为" << id << "的教师不存在！" << endl;
						__listTeacher();
						cout << "请重新输入（返回请输入0）：";
						cin >> id;
					}
					if (id == "0") break;


					while (true) {
						bool back = false;
						__showTeacherManagementMenu(*p);
						switch (__waitForRequest(4)) {
						case 1: {//教学任务管理
							while (true) {
								bool back = false;
								__showTeachingMissionMenu();
								switch (__waitForRequest(4)) {
								case 1: {//查看该教师已有教学任务
									p->displayTask();
									break;
								}
								case 2: {//添加教学任务
									p->assignTask();
									break;
								}
								case 3: {//修改教学任务
									p->reviseTask();
									break;
								}
								case 4: {//删除教学任务
									p->deleteMission();
									break;
								}
								case 0: {
									back = true;
									break;
								}
								}//switch
								if (back) break;
							}
							break;
						}
						case 2: {//查看该教师详细信息
							p->showDetailInfo();
							break;
						}
						case 3: {//修改该教师信息
							reviseTeacher(p);
							break;
						}
						case 4: {//删除该教师
							cout << "确认要删除" << p->getName()
								<< p->getPost() << "？输入(Y/y)确认删除：";
							string ascertain;
							cin >> ascertain;
							if (ascertain != "y" && ascertain != "Y") {
								cout << "取消删除操作" << endl;
								break;
							}

							string id;
							if (__deleteTeacher(p->getId())) {
								cout << "删除成功！" << endl;
								system("pause");
								back = true;
							}
							else {
								cout << "删除失败！" << endl;
							}
							
							break;
						}
						case 0: {
							back = true;
							break;
						}
						}//switch
							if (back) break;
					}
					break;
				}
				case 3: {//删除教师
					deleteTeacher();
					break;
				}
				case 4: {//教师工作量统计
					displayWorkingStat();
					break;
				}
				case 5: {//浏览全体教师信息
					sortAndShowTeacher();
					break;
				}
				case 0: {
					back = true;
					break;
				}
				}//switch
				if (back) break;
			}
			break;
		}
		case 2: {
			changePassword();
			break;
		}
		case 0: {
			back = true;
			break;
		}

		}//switch
		if (back) break;
	}
}

bool TeacherManagementSystem::addTeacher()
{
	system("cls");
	__printLine();
	__offset("添加教师",21);
	__printLine();

	string id;
	cout << "请输入教师ID：";
	cin >> id;
	while (__isExisted(id)) {
		cout << "ID为" << id << "的教师已存在！" << endl;
		cout << "请重新输入：";
		cin >> id;
	}
	cout << "ID已成功设置为：" << id << endl;

	string name;
	cout << "请输入教师姓名：";
	cin >> name;
	cout << "姓名已成功设置为：" << name << endl;

	string gender;
	cout << "请输入教师性别（男/女）：";
	cin >> gender;
	while (gender != "男" && gender != "女") {
		cout << "输入错误！" << endl;
		cout << "请输入“男”或“女”：";
		cin >> gender;
	}
	cout << "性别已成功设置为：" << gender << endl;

	string post;
	cout << "请输入职称的编号" << endl;
	cout << "1-助教，2-讲师，3-副教授，4-教授" << endl;
	cin >> post;
	while (post != "1" && post != "2" && post != "3" && post != "4") {
		cout << "输入错误！" << endl;
		cout << "请输入整数1至4" << endl;
		cout << "1-助教，2-讲师，3-副教授，4-教授" << endl;
		cin >> post;
	}
	if (post == "1") post = "助教";
	else if (post == "2") post = "讲师";
	else if (post == "3") post = "副教授";
	else if (post == "4") post = "教授";
	else {
		cout << "未知错误！" << endl;
		return false;
	}
	cout << "职称已成功设置为：" << post << endl;

	Teacher *t = new Teacher(id, name, gender, post); 
	if (!__addTeacher(*t)) {
		cout << "添加教师失败！" << endl;
		return false;
	}

	cout << "教师已添加！" << endl;
	cout << "教师的信息为：" << endl;
	cout << *__getTeacherById(id) << endl;
	system("pause");
	return true;
}

void TeacherManagementSystem::reviseTeacher(Teacher *teacher)
{
	while (true) {
		bool back = false;
		teacher->showTeacherRevisionMenu();
		switch (__waitForRequest(4)) {
		case 1: {//ID
			string id;
			cout << "请输入新ID：";
			cin >> id;
			while (__isExisted(id)) {
				cout << "输入的ID已存在！请重新输入" << endl;
				cout << "请输入新ID：";
				cin >> id;
			}
			teacher->setId(id);
			cout << "已成功修改ID为：" << id << endl;
			system("pause");
			break;
		}
		case 2: {//姓名
			string name;
			cout << "请输入新姓名：";
			cin >> name;
			teacher->setName(name);
			cout << "已成功修改姓名为：" << name << endl;
			system("pause");
			break;
		}
		case 3: {//性别
			string gender;
			cout << "请输入新性别（男/女）：";
			cin >> gender;
			while (gender != "男" && gender != "女") {
				cout << "输入错误！请重新输入" << endl;
				cout << "请输入新性别（男/女）：";
				cin >> gender;
			}
			teacher->setGender(gender);
			cout << "已成功修改性别为：" << gender << endl;
			system("pause");
			break;
		}
		case 4: {//职称
			string post;
			cout << "请输入新职称的编号" << endl;
			cout << "1-助教，2-讲师，3-副教授，4-教授" << endl;
			cin >> post;
			while (post != "1" && post != "2" && post != "3" && post != "4") {
				cout << "输入错误！" << endl;
				cout << "请输入整数1至4" << endl;
				cout << "1-助教，2-讲师，3-副教授，4-教授" << endl;
				cin >> post;
			}
			if (post == "1") post = "助教";
			else if (post == "2") post = "讲师";
			else if (post == "3") post = "副教授";
			else if (post == "4") post = "教授";
			else {
				cout << "未知错误！" << endl;
				break;
			}
			teacher->setPost(post);
			cout << "已成功修改职称为：" << post << endl;
			break;
		}
		case 0: {
			back = true;
			break;
		}
		}//switch
		if (back) break;
	}
	system("cls");
	cout << "已完成修改,现在该教师信息如下：" << endl;
	cout << *teacher << endl;
	system("pause");
}

void TeacherManagementSystem::loadData()
{
	ifstream ifs("tms.dat");
	if (!ifs.good()) {
		ifs.close();
		return;
	}

	
	while (ifs.good()) {
		int nTeacher = 0;
		ifs >> nTeacher;
		while (nTeacher--) {
			string id, name, gender, post;
			ifs >> id >> name >> gender >> post;
			Teacher *t = new Teacher(id, name, gender, post);
			__addTeacher(*t);
			
			int nTT;
			ifs >> nTT;//教学任务数量
			while (nTT--) {
				double exp = 0, pra = 0;
				string subName;
				int nClass; //班级数量
				ifs >> exp >> pra >> subName >> nClass;
				TeachingTask *tt = new TeachingTask(subName, exp, pra);
				while (nClass--) {
					string className;
					ifs >> className;
					tt->addClass(className);
				}
				__getTeacherById(id)->__assignTask(*tt);
			}
		}
	}


	cout << "数据加载成功！" << endl;
	cout << "已成功载入" << m_teacherList.size() << "位教师的数据！" << endl;
	system("pause");
	ifs.close();
}

void TeacherManagementSystem::saveData()
{
	ofstream ofs("tms.dat");

	ofs << m_teacherList.size() << endl;
	for (MyIterator<Teacher> it = m_teacherList.begin(); it != m_teacherList.end(); it++) {
		ofs << it->getId() << " " << it->getName() << " "
			<< it->getGender() << " " << it->getPost() << " ";
		ofs << it->__toString() ;
		ofs << endl;
	}
	ofs.close();

	cout << "已成功将" << m_teacherList.size() << "条数据写入tms.dat文件中！" << endl;
	cout << "请不要手动修改tms.dat文件，避免造成不必要的数据损失" << endl;
	system("pause");
}

void TeacherManagementSystem::login()
{
	ifstream ifs("key.dat");

	if (!ifs.good()) {
		ifs.close();
		cout << "欢迎第一次使用本系统！" << endl;
		cout << "请设置密码(请输入英文和数字)：";
		ofstream ofs("key.dat");
		string ps;
		cin >> ps;
		for (unsigned i = 0; i < ps.length(); i++) {
			ps[i] += 100; //简单的加密
		}
		ofs << ps;
		ofs.close();
		return;
	}

	string ps;
	ifs >> ps;
	ifs.close();

	for (unsigned i = 0; i < ps.length(); i++) {
		ps[i] -= 100;
	}
	cout << "请输入密码：";
	string password;
	cin >> password;
	int n = 5;
	while (password != ps && n--) {
		cout << "密码错误！还剩" << n + 1 << "次机会！" << endl;
		cout << "请再次输入密码：";
		cin >> password;
	}
	if (password != ps) {
		cout << "密码错误次数过多，请重新打开程序!" << endl;
		system("pause");
		exit(0);
	}
	cout << "欢迎回来！" << endl;
}

void TeacherManagementSystem::changePassword()
{
	
		cout << "请设置新的密码(请输入英文和数字)：";
		ofstream ofs("key.dat");
		string ps;
		cin >> ps;
		for (unsigned i = 0; i < ps.length(); i++) {
			ps[i] += 100; //简单的加密
		}
		ofs << ps;
		cout << "密码修改成功！" << endl;
		system("pause");
		ofs.close();
}

bool TeacherManagementSystem::deleteTeacher()
{
	system("cls");
	__printLine();
	__offset("删除教师", 21);
	__printLine();

	if (m_teacherList.size() == 0) {
		cout << "请先添加教师！" << endl;
		system("pause");
		return false;
	}

	__listTeacher();
	cout << "请输入要删除的教师ID：";
	string id;
	cin >> id;
	if (!__deleteTeacher(id)) {
		cout << "该ID的教师不存在！" << endl;
		system("pause");
		return false;
	}
	cout << "ID为" << id << "的教师删除成功！" << endl;
	system("pause");
	return true;
}

void TeacherManagementSystem::sortAndShowTeacher()
{
	system("cls");
	__printLine();
	__offset("全体教师信息", 18);
	__printLine();

	if (m_teacherList.size() == 0) {
		cout << "无教师信息" << endl;
		system("pause");
		return;
	}

	MyOrderedList<Teacher> teacherInOrder;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		teacherInOrder.insert(*it);
	}
	MyIterator<Teacher> it2 = teacherInOrder.begin();
	for (; it2 != teacherInOrder.end(); it2++) {
		cout << *it2 << endl;
	}
	system("pause");
}



void TeacherManagementSystem::displayWorkingStat()
{
	system("cls");
	__printLine();
	__offset("教师工作量统计");
	__printLine();
	cout << "教师总人数为：" << m_teacherList.size() << endl;
	cout << "全体教师总工作量为：" << __getAllWorkload() << endl;
	double ave1 = 0;
	if (m_teacherList.size() != 0) ave1 = __getAllWorkload() / m_teacherList.size();
	cout << "全体教师平均工作量为：" << ave1 << endl;

	cout << "--------------------------------" << endl;
	pair<double, int> female, male;
	female = __getFemaleWorkloadAndNum();
	male = __getMaleWorkloadAndNum();
	cout << "女教师总人数为：" << female.second << endl;
	cout << "女教师总工作量为：" << female.first << endl;
	double ave2 = 0;
	if (female.second != 0) ave2 = female.first / female.second;
	cout << "女教师平均工作量为：" << ave2 << endl;	
	cout << "--------------------------------" << endl;

	cout << "男教师总人数为：" << male.second << endl;
	cout << "男教师总工作量为：" << male.first << endl;
	double ave3 = 0;
	if (male.second != 0) ave3 = male.first / male.second;
	cout << "男教师平均工作量为：" << ave3 << endl;
	system("pause");
}

void TeacherManagementSystem::__showMainMenu()
{
	system("cls");
	__printLine();
	__offset("欢迎来到教师管理系统");
	cout << endl;
	__offset("主菜单",23);
	cout << endl;
	__offset("1 - 进入教师管理系统");
	__offset("2 - 修改登录密码");
	__offset("0 - 退出系统");

	__printLine();
	
}

void TeacherManagementSystem::__showTeacherMenu()
{
	system("cls");
	__printLine();
	__offset("教师管理菜单",19);
	cout << endl;
	__offset("1 - 录入新教师");
	__offset("2 - 查询与管理教师");
	__offset("3 - 删除教师");
	__offset("4 - 教师工作量统计");
	__offset("5 - 浏览全体教师信息");
	__offset("0 - 返回上一级菜单");
	__printLine();

}

void TeacherManagementSystem::__showTeacherManagementMenu(const Teacher & teacher)
{
	system("cls");
	__printLine();
	__offset("教师编辑菜单", 19);
	cout << endl;
	cout << "当前教师为：" << endl;
	cout << teacher << endl;
	__offset("1 - 教学任务管理");
	__offset("2 - 查看该教师详细信息");
	__offset("3 - 修改该教师信息");
	__offset("4 - 删除该教师");
	__offset("0 - 返回上一级菜单");
	__printLine();
}

void TeacherManagementSystem::__showTeachingMissionMenu()
{
	system("cls");
	__printLine();
	__offset("教学任务管理菜单", 18);
	cout << endl;
	__offset("1 - 查看该教师已有的教学任务");
	__offset("2 - 添加教学任务");
	__offset("3 - 修改教学任务");
	__offset("4 - 删除教学任务");
	__offset("0 - 返回上一级菜单");
	__printLine();
}

//添加新教师对象进入集合，成功返回true，若id重复，则返回false
bool TeacherManagementSystem::__addTeacher(Teacher & teacher)
{
	string id = teacher.getId();

	if (__isExisted(id)) return false;
	
	m_teacherList.push_back(teacher);
	return true;
}

//删除教师对象，如果成功返回true，教师id不存在返回false
bool TeacherManagementSystem::__deleteTeacher(string id)
{
	Teacher* tmp;
	if (!(tmp=__getTeacherById(id))) return false;
	m_teacherList.erase(*tmp);
	return true;
}

void TeacherManagementSystem::__printLine(int n)
{
	while (n--) cout << '*';
	cout << endl;
}

//如果id已存在返回true，否则返回false
bool TeacherManagementSystem::__isExisted(string id)
{
	if (!__getTeacherById(id)) return false;
	return true;
}

void TeacherManagementSystem::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

int TeacherManagementSystem::__waitForRequest(int max)
{
	int ret, count = 1;
	cout << "请输入0至" << max << "的指令编号：";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入0至"<< max << "的整数：";
		cin >> ret;
		count++;
		if (count == 5) return -1;
	}
	return ret;
}

double TeacherManagementSystem::__getAllWorkload()
{
	double ret = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		ret += it->getTotalWorkload();
	}

	return ret;
}

pair<double,int> TeacherManagementSystem::__getMaleWorkloadAndNum()
{
	double ret = 0;
	int count = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getGender() == "男") {
			ret += it->getTotalWorkload();
			count++;
		}
	}

	return make_pair(ret, count);
}

pair<double,int> TeacherManagementSystem::__getFemaleWorkloadAndNum()
{
	double ret = 0;
	int count = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getGender() == "女") {
			ret += it->getTotalWorkload();
			count++;
		}
	}

	return make_pair(ret, count);
}

Teacher * TeacherManagementSystem::__getTeacherById(string id)
{
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getId() == id) {
			return &(*it);
		}
	}
	return nullptr;
}

void TeacherManagementSystem::__listTeacher() const
{
	cout << "现有教师如下：" << endl;
	if (m_teacherList.size() == 0) {
		cout << "无" << endl;
		return;
	}

	unsigned int count = 1;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++, count++) {
		cout << it->getId() << ":" << it->getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if (count % 3 != 1) cout << endl;

}
