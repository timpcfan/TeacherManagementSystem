#include "Teacher.h"
#include "TeachingMission.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;





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

bool Teacher::__assignMission(TeachingMission & teachingMission)
{
	m_missionSet.insert(teachingMission);
	return true;
}

void Teacher::__listMission()
{
	set<TeachingMission>::iterator it;
	int count = 1;
	for (it = m_missionSet.begin(); it != m_missionSet.end(); it++, count++) {
		cout << count << ":" << (*it).getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if(count % 3 != 1) cout << endl;
}

bool Teacher::__deleteMission(size_t no)
{
	if (no > m_missionSet.size() || no < 1) {
		return false;
	}
	set<TeachingMission>::iterator it = m_missionSet.begin();
	for (size_t i = 1; i < no; i++) it++;
	m_missionSet.erase(it);
	return true;
}

bool Teacher::assignMission()
{
	string subjectName;
	cout << "请输入课程名称：";
	cin >> subjectName;
	int n;
	cout << "请输入班级数量：";
	cin >> n;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入整数：";
		cin >> n;
	}
	vector<string> vt;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cout << "请输入第" << i << "个班级：" ;
		cin >> tmp;
		vt.push_back(tmp);
	}
	double expTime, praTime;
	cout << "请输入实验课时：" ;
	cin >> expTime;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入数字：";
		cin >> expTime;
	}
	cout << "请输入理论课时：" ;
	cin >> praTime;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入数字：";
		cin >> praTime;
	}

	TeachingMission *tm = new TeachingMission(subjectName, expTime, praTime);
	for(int i=0;i<n;i++) tm->addClass(vt.at(i));

	if (!__assignMission(*tm)) {
		cout << "添加课程失败！" << endl;
		return false;
	}
	cout << "添加课程成功！" << endl;
	return true;
}

bool Teacher::deleteMission()
{
	__listMission();
	size_t no;

	cout << "请输入要删除的教学任务编号：" ;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //输入错误处理
		cin.clear();
		while (cin.get() != '\n');
		cout << "输入格式错误，请输入数字：";
		cin >> no;
	}
	if (!__deleteMission(no)) {
		cout << "输入的编号所对应的教学任务不存在！" << endl;
		return false;
	}
	cout << "删除成功！" << endl;
	cout << "剩余的教学任务为：" << endl;
	__listMission();
	return true;
}



