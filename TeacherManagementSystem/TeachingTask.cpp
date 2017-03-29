#include "TeachingTask.h"
#include <iostream>
#include <sstream>

using namespace std;

TeachingTask::TeachingTask()
	:m_subjectName("null"), m_expTime(0), m_praTime(0)
{
}

TeachingTask::TeachingTask(string subjectName, double expTime, double praTime)
	:m_subjectName(subjectName),m_expTime(expTime),m_praTime(praTime)
{
}

void TeachingTask::setName(string name)
{
	m_subjectName = name;
}

string TeachingTask::getName() const
{
	return m_subjectName;
}

void TeachingTask::setExpTime(double time)
{
	m_expTime = time;
}

double TeachingTask::getExpTime() const
{
	return m_expTime;
}

void TeachingTask::setPraTime(double time)
{
	m_praTime = time;
}

double TeachingTask::getPraTime() const
{
	return m_praTime;
}

unsigned TeachingTask::getNumOfClasses() const
{
	return m_classesList.size();
}

double TeachingTask::getTotalClassHour() const
{
	double ret = 0;
	if (getNumOfClasses() <= 2) ret = 1.5 * (getPraTime() + getExpTime());
	else if(getNumOfClasses() <= 3) ret = 2 * (getPraTime() + getExpTime());
	else  ret = 2.5 * (getPraTime() + getExpTime());
	return ret;
}

//插入班级，插入成功返回true，若已存在同样的班级返回false
bool TeachingTask::addClass(string className)
{
	if (m_classesList.contains(className)) return false;
	m_classesList.insert(className);
	return true;
}

//删除班级，删除成功返回true，班级不存在返回false
bool TeachingTask::deleteClass(string className)
{
	if (!m_classesList.contains(className)) return false;
	return m_classesList.erase(className);
}

void TeachingTask::listClass() const
{
	if (m_classesList.size() == 0) {
		cout << "无" << endl;
		return;
	}

	MyIterator<string> it = m_classesList.begin();
	int count = 1;
	for (; it != m_classesList.end(); it++, count++) {
		cout << *it << " ";
		if (count % 5 == 0) cout << endl;
	}
	if (count % 5 != 1) cout << endl;
	cout << endl;
}

string TeachingTask::toString()
{
	stringstream ss;
	ss << m_classesList.size() << " ";
	for (MyIterator<string> it = m_classesList.begin(); it != m_classesList.end(); it++) {
		ss << *it << " ";
	}
	string s = ss.str();
	return s;
}

bool TeachingTask::operator<(const TeachingTask & other) const
{
	return this->m_subjectName < other.m_subjectName;
}

bool TeachingTask::operator==(const TeachingTask & other) const
{
	return this->m_subjectName == other.m_subjectName;
}

ostream & operator<<(ostream & out, const TeachingTask & other)
{
	out << "-------------------------------------------------" << endl;
	out << "课程名称：" << other.getName() << "，实验课时：" << other.getExpTime()
		<< "，理论课时：" << other.getPraTime() << endl;
	out	<< "班级数目：" << other.getNumOfClasses() << endl;
	out << "班级列表：";
	other.listClass();
	/*out << "-------------------------------------------------" << endl;*/
	return out;
}
