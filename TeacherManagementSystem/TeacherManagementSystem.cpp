#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

void TeacherManagementSystem::start()
{
	while (true) {
		bool back = false;
		__showMainMenu();
		switch (__waitForRequest(1)) {
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
					if (m_teacherMap.size() == 0) {
						cout << "请先添加教师！" << endl;
						system("pause");
						break;
					}
					__listTeacher();
					cout << "请输入教师ID：" ;
					string id;
					cin >> id;
					while (!__isExisted(id)) {
						cout << "ID为" << id << "的教师不存在！" << endl;
						__listTeacher();
						cout << "请重新输入：";
						cin >> id;
					}

					Teacher *p = &(m_teacherMap[id]);

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
									p->displayMission();
									break;
								}
								case 2: {//添加教学任务
									p->assignMission();
									break;
								}
								case 3: {//修改教学任务
									p->reviseMission();
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

							break;
						}
						case 3: {//修改该教师信息

							break;
						}
						case 4: {//删除该教师

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

					break;
				}
				case 5: {//浏览全体教师信息

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
	cout << "添加教师" << endl;
	__printLine();

	string id;
	cout << "请输入教师ID：";
	cin >> id;
	while (__isExisted(id)) {
		cout << "ID为" << id << "的教师已存在！" << endl;
		cout << "请重新输入：";
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

	
	if (!__addTeacher(Teacher(id, name, gender, post))) {
		cout << "添加教师失败！" << endl;
		return false;
	}

	cout << "教师已添加！" << endl;
	cout << "教师的信息为：" << endl;
	cout << m_teacherMap[id] << endl;
	system("pause");
	return true;
}

bool TeacherManagementSystem::deleteTeacher()
{
	system("cls");
	__printLine();
	cout << "删除教师" << endl;
	__printLine();

	__listTeacher();
	cout << "请输入要删除的教师id：";
	string id;
	cin >> id;
	if (!__deleteTeacher(id)) {
		cout << "该ID的教师不存在！" << endl;
		return false;
	}
	cout << "ID为" << id << "的教师删除成功！" << endl;
	return true;
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
	
	m_teacherMap.insert(make_pair(id,teacher));
	return true;
}

//删除教师对象，如果成功返回true，教师id不存在返回false
bool TeacherManagementSystem::__deleteTeacher(string id)
{
	if (!__isExisted(id)) return false;

	m_teacherMap.erase(id);
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
	if (m_teacherMap.find(id) == m_teacherMap.end()) return false;
	return true;
}

void TeacherManagementSystem::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

int TeacherManagementSystem::__waitForRequest(int max)
{
	int ret;
	cout << "请输入0至" << max << "的指令编号：";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入0至"<< max << "的整数：";
		cin >> ret;
	}
	return ret;
}

void TeacherManagementSystem::__listTeacher() const
{
	cout << "现有教师如下：" << endl;
	if (m_teacherMap.size() == 0) {
		cout << "无" << endl;
		return;
	}

	unsigned int count = 1;
	map<string,Teacher>::const_iterator it = m_teacherMap.begin();
	for (; it != m_teacherMap.end(); it++, count++) {
		cout << it->first << ":" << it->second.getName() << "\t";
		if (count % 4 == 0) cout << endl;
	}
	if (count % 4 != 1) cout << endl;

}
