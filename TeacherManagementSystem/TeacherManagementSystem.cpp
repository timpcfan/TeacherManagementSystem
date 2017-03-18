#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

bool TeacherManagementSystem::addTeacher()
{
	__printLine();
	cout << "添加教师" << endl;
	__printLine();

	string id;
	cout << "请输入教师ID：" << endl;
	cin >> id;
	while (__isExisted(id)) {
		cout << "ID为" << id << "的教师已存在！" << endl;
		cout << "请重新输入：" << endl;
	}
	cout << "ID已成功设置为：" << id << endl;

	string name;
	cout << "请输入教师姓名：" << endl;
	cin >> name;
	cout << "姓名已成功设置为：" << name << endl;

	string gender;
	cout << "请输入教师性别（男/女）:" << endl;
	while (gender != "男" && gender != "女") {
		cout << "输入错误！" << endl;
		cout << "请输入“男”或“女”：" << endl;
		cin >> gender;
	}

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
	if (post == "1") post == "助教";
	else if (post == "2") post == "讲师";
	else if (post == "3") post == "副教授";
	else if (post == "4") post == "教授";
	else {
		cout << "未知错误！" << endl;
		return false;
	}

	
	if (!__addTeacher(Teacher(id, name, gender, post))) {
		cout << "添加教师失败！" << endl;
		return false;
	}

	cout << "教师已添加！" << endl;
	//TODO 添加教师信息显示
	return true;
}

bool TeacherManagementSystem::deleteTeacher()
{
	__printLine();
	cout << "删除教师" << endl;
	__printLine();

	__listTeacher();
	cout << "请输入要删除的教师id：" << endl;
	string id;
	cin >> id;
	if (!__deleteTeacher(id)) {
		cout << "该ID的教师不存在！" << endl;
		return false;
	}
	cout << "ID为" << id << "的教师删除成功！" << endl;
	return true;
}

void TeacherManagementSystem::showMainMenu()
{
	__printLine();
	__offset("欢迎来到教师管理系统");
	cout << endl;
	__offset("主菜单",23);
	cout << endl;
	__offset("1 - 进入教师管理系统");
	__offset("0 - 退出系统");

	__printLine();
	
}

void TeacherManagementSystem::showTeacherMenu()
{
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

void TeacherManagementSystem::showTeacherManagementMenu()
{
	__printLine();
	__offset("教师编辑菜单", 19);
	cout << endl;
	__offset("1 - 教学任务管理");
	__offset("2 - 查看该教师详细信息");
	__offset("3 - 修改该教师信息");
	__offset("4 - 删除该教师");
	__offset("0 - 返回上一级菜单");
	__printLine();
}

void TeacherManagementSystem::showTeachingMissionMenu()
{
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

void TeacherManagementSystem::__listTeacher() const
{
	if (m_teacherMap.size() == 0) {
		cout << "无" << endl;
		return;
	}

	unsigned int count = 1;
	map<string,Teacher>::const_iterator it = m_teacherMap.begin();
	for (; it != m_teacherMap.end(); it++, count++) {
		cout << it->first << ":" << it->second << "\t";
		if (count % 4 == 0) cout << endl;
	}
	if (count % 4 != 1) cout << endl;

}
