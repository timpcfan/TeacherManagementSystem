#include "Teacher.h"
#include "TeachingTask.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


Teacher::Teacher()
{
}

Teacher::Teacher(string id, string name, string gender, string post)
	:m_id(id), m_name(name), m_gender(gender), m_post(post)
{

}

string Teacher::getId() const
{
	return m_id;
}

void Teacher::setId(string id)
{
	m_id = id;
}

string Teacher::getName() const
{
	return m_name;
}

void Teacher::setName(string name)
{
	m_name = name;
}

string Teacher::getGender() const
{
	return m_gender;
}

void Teacher::setGender(string gender)
{
	m_gender = gender;
}

string Teacher::getPost() const
{
	return m_post;
}

void Teacher::setPost(string post)
{
	m_post = post;
}

double Teacher::getTotalWorkload() const
{
	double ret = 0;
	MyIterator<TeachingTask> it = m_taskList.begin();
	for (; it != m_taskList.end(); it++) ret += it->getTotalClassHour();
	return ret;
}

bool Teacher::__assignMission(TeachingTask & teachingTask)
{
	m_taskList.push_back(teachingTask);
	return true;
}

void Teacher::__listTask()
{
	MyIterator<TeachingTask> it;
	int count = 1;
	for (it = m_taskList.begin(); it != m_taskList.end(); it++, count++) {
		cout << count << ":" << (*it).getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if(count % 3 != 1) cout << endl;
}

bool Teacher::__deleteTask(unsigned int no)
{
	if (no > m_taskList.size() || no < 1) {
		return false;
	}
	MyIterator<TeachingTask> it = m_taskList.begin();
	for (unsigned int i = 1; i < no; i++) it++;
	m_taskList.erase(*it);
	return true;
}

void Teacher::__printLine(int n)
{
	while (n--) cout << '*';
	cout << endl;
}

TeachingTask * Teacher::__getTaskAt(unsigned no)
{
	assert(no <= m_taskList.size() && no >= 1);

	MyIterator<TeachingTask> it = m_taskList.begin();
	for (unsigned i = 1; i < no; i++) it++;
	return &(*it);
}

bool Teacher::assignTask()
{
	system("cls");
	__printLine();
	__offset("添加教学任务", 18);
	__printLine();
	string subjectName;
	cout << "请输入课程名称：";
	cin >> subjectName;
	while (m_taskList.contains(TeachingTask(subjectName, 0, 0))) {
		cout << subjectName << "已经存在，请重新输入课程名称：";
		cin >> subjectName;
	}
	cout << "课程名称已成功设置为：" << subjectName << endl;


	double expTime, praTime;
	cout << "请输入实验课时：";
	cin >> expTime;
	while (cin.fail() || cin.peek() != '\n' || expTime < 0 || expTime > 200 || expTime - floor(expTime) > 0) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入错误，请输入0至200的整数：";
		cin >> expTime;
	}
	cout << "实验课时已成功设置为：" << expTime << endl;
	cout << "请输入理论课时：";
	cin >> praTime;
	while (cin.fail() || cin.peek() != '\n' || praTime < 0 || praTime > 200 || praTime - floor(praTime) > 0) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入错误，请输入0至200的整数：";
		cin >> praTime;
	}
	cout << "实验课时已成功设置为：" << praTime << endl;

	TeachingTask *tm = new TeachingTask(subjectName, expTime, praTime);

	int n;
	cout << "请输入班级数量：";
	cin >> n;

	while (cin.fail() || cin.peek() != '\n' || n < 0 || n > 10) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入错误，请输入小于10的正整数：";
		cin >> n;
	}
	for (int i = 1; i <= n; i++) {
		string tmp;
		cout << "请输入第" << i << "个班级：" ;
		cin >> tmp;
		while (!tm->addClass(tmp)) {
			cout << tmp << "已存在,请重新输入！" << endl;
			cout << "请输入第" << i << "个班级：";
			cin >> tmp;
		}
	}


	if (!__assignMission(*tm)) {
		cout << "添加课程失败！" << endl;
		return false;
	}
	cout << "添加课程成功！" << endl;
	cout << "教学信息如下：" << endl;
	cout << *tm << endl;
	system("pause");
	return true;
}

bool Teacher::deleteMission()
{
	system("cls");
	__printLine();
	__offset("删除教学任务", 18);
	__printLine();

	if (m_taskList.size() == 0) {
		cout << "没有教学任务！" << endl;
		system("pause");
		return false;
	}


	__listTask();
	size_t no;

	cout << "请输入要删除的教学任务编号（返回请输入0）：" ;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入数字：";
		cin >> no;
	}
	if (no == 0) {
		return false;
	}
	if (!__deleteTask(no)) {
		cout << "输入的编号所对应的教学任务不存在！" << endl;
		system("pause");
		return false;
	}
	cout << "删除成功！" << endl;
	cout << "剩余的教学任务为：";
	__listTask();
	return true;
}

void Teacher::__showTaskRevisionMenu(const TeachingTask & teachingMission)
{
	system("cls");
	__printLine();
	__offset("修改教学任务", 18);
	__printLine();
	cout << teachingMission << endl;
	__offset("1 - 修改课程名称");
	__offset("2 - 添加班级");
	__offset("3 - 删除班级");
	__offset("4 - 修改实验课时");
	__offset("5 - 修改理论课时");
	__offset("0 - 完成修改");
	__printLine();
}

void Teacher::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

bool Teacher::reviseTask()
{
	system("cls");
	__printLine();
	__offset("修改教学任务", 18);
	__printLine();

	if (m_taskList.size() == 0) {
		cout << "没有教学任务！" << endl;
		system("pause");
		return false;
	}

	__listTask();

	unsigned int no;
	cout << "请输入要修改的教学任务编号(返回请输入0)：" << endl;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入数字：";
		cin >> no;
	}
	if (no == 0) return false;
	if (no > m_taskList.size() || no < 1) {
		cout << "没有对应编号的教学任务！" << endl;
		system("pause");
		return false;
	}

	TeachingTask *tmp = __getTaskAt(no);

	while (true) { //开始修改
		__showTaskRevisionMenu(*tmp);
		cout << "请输入要修改的编号：";
		string op;
		cin >> op;
		if (op == "1") {
			cout << "请输入修改后的课程名称：";
			string newName;
			cin >> newName;
			tmp->setName(newName);
			cout << "课程名称已修改为：" << tmp->getName() << endl;
			system("pause");

		}
		else if(op == "2"){
			cout << "请输入要添加的班级名称：";
			string newClass;
			cin >> newClass;
			if (!tmp->addClass(newClass)) cout << "班级已存在，现在的班级有：";
			else cout << "添加成功，现在的班级有：";
			tmp->listClass();
			system("pause");

		}
		else if (op == "3") {
			tmp->listClass();
			cout << "请输入要删除的班级名称：";
			string classToDelete;
			cin >> classToDelete;
			if (!tmp->deleteClass(classToDelete)) cout << "输入的班级不存在！" << endl;
			else cout << "删除成功！" << endl;
			cout << "剩余的班级还有：";
			tmp->listClass();
			system("pause");
		}
		else if (op == "4") {
			double expTime;
			cout << "请输入修改后的实验课时：";
			cin >> expTime;
			while (cin.fail() || cin.peek() != '\n' || expTime < 0 || expTime > 200 || expTime - floor(expTime) > 0) { //输入错误处理
				cin.clear();
				while (cin.get() != '\n');
				cout << "输入错误，请输入0至200的整数：";
				cin >> expTime;

			}
			tmp->setExpTime(expTime);
			cout << "实验课时已修改为：" << tmp->getExpTime() << endl;
			system("pause");
		}
		else if (op == "5") {
			double praTime;
			cout << "请输入修改后的理论课时：";
			cin >> praTime;
			while (cin.fail() || cin.peek() != '\n' || praTime < 0 || praTime > 200 || praTime - floor(praTime) > 0) { //输入错误处理
				cin.clear();
				while (cin.get() != '\n');
				cout << "输入错误，请输入0至200的整数：";
				cin >> praTime;
			}
			tmp->setPraTime(praTime);
			cout << "实验课时已修改为：" << tmp->getPraTime() << endl;
			system("pause");

		}
		else if (op == "0") {
			break;
		}
		else {
			cout << "指令输入错误，请重新输入!" << endl;
		}
	}
	
	system("cls");
	cout << "修改成功！" << endl;
	cout << "修改后的信息为：" << endl;
	cout << *tmp << endl;
	system("pause");
	return true;
}

void Teacher::__displayTask()
{
	cout << "           ";
	cout << m_name << m_post << "一共有" << m_taskList.size() << "个教学任务" << endl;

	MyIterator<TeachingTask> it;
	for (it = m_taskList.begin(); it != m_taskList.end(); it++) {
		cout << *it;
	}
	cout << endl;
}


void Teacher::showTeacherRevisionMenu()
{
	system("cls");
	__printLine();
	__offset("教师信息修改菜单");
	cout << endl;
	cout << *this << endl;
	cout << "请输入要修改的内容编号：" << endl;
	__offset("1 - ID");
	__offset("2 - 姓名");
	__offset("3 - 性别");
	__offset("4 - 职称");
	__offset("0 - 完成修改");
	__printLine();

}

int Teacher::__waitForRequest(int max)
{
	int ret, count = 1;
	cout << "请输入0至" << max << "的指令编号：";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入0至" << max << "的整数：";
		cin >> ret;
		count++;
		if (count == 5) return -1;
	}
	return ret;
}

void Teacher::displayTask()
{
	system("cls");
	__printLine();
	__offset("详细教学任务清单");
	__printLine();
	__displayTask();
	system("pause");
}

void Teacher::showDetailInfo()
{
	system("cls");
	__printLine();
	__offset(this->getName() + "的详细信息");
	__printLine();
	cout << *this << endl;
	cout << "--------------------------------------------------" << endl;
	__displayTask();
	system("pause");
}

bool Teacher::operator<(const Teacher & other) const
{
	if (getTotalWorkload() > other.getTotalWorkload()) return true;
	return false;
}

bool Teacher::operator==(const Teacher & other) const
{
	return getId() == other.getId();
}

ostream & operator<<(ostream & out, const Teacher & teacher)
{
	out << "[" << "ID:" << teacher.getId() << ",姓名:" << teacher.getName()
		<< ",性别:" << teacher.getGender()
		<< ",职称:" << teacher.getPost() << ",总工作量:" 
		<< teacher.getTotalWorkload() << "]";
	return out;
}
