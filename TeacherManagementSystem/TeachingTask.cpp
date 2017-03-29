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

//����༶������ɹ�����true�����Ѵ���ͬ���İ༶����false
bool TeachingTask::addClass(string className)
{
	if (m_classesList.contains(className)) return false;
	m_classesList.insert(className);
	return true;
}

//ɾ���༶��ɾ���ɹ�����true���༶�����ڷ���false
bool TeachingTask::deleteClass(string className)
{
	if (!m_classesList.contains(className)) return false;
	return m_classesList.erase(className);
}

void TeachingTask::listClass() const
{
	if (m_classesList.size() == 0) {
		cout << "��" << endl;
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
	out << "�γ����ƣ�" << other.getName() << "��ʵ���ʱ��" << other.getExpTime()
		<< "�����ۿ�ʱ��" << other.getPraTime() << endl;
	out	<< "�༶��Ŀ��" << other.getNumOfClasses() << endl;
	out << "�༶�б�";
	other.listClass();
	/*out << "-------------------------------------------------" << endl;*/
	return out;
}
