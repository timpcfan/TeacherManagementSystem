#include "TeachingMission.h"
#include <set>
#include <iostream>

using namespace std;

TeachingMission::TeachingMission()
	:m_subjectName("null"), m_expTime(0), m_praTime(0)
{
}

TeachingMission::TeachingMission(string subjectName, double expTime, double praTime)
	:m_subjectName(subjectName),m_expTime(expTime),m_praTime(praTime)
{
}

void TeachingMission::setName(string name)
{
	m_subjectName = name;
}

string TeachingMission::getName() const
{
	return m_subjectName;
}

void TeachingMission::setExpTime(double time)
{
	m_expTime = time;
}

double TeachingMission::getExpTime() const
{
	return m_expTime;
}

void TeachingMission::setPraTime(double time)
{
	m_praTime = time;
}

double TeachingMission::getPraTime() const
{
	return m_praTime;
}

unsigned int TeachingMission::getNumOfClasses() const
{
	return m_classesSet.size();
}

double TeachingMission::getTotalClassHour() const
{
	double ret = 0;
	if (getNumOfClasses() <= 2) ret = 1.5 * (getPraTime() + getExpTime());
	else if(getNumOfClasses() <= 3) ret = 2 * (getPraTime() + getExpTime());
	else  ret = 2.5 * (getPraTime() + getExpTime());
	return ret;
}

//����༶������ɹ�����true�����Ѵ���ͬ���İ༶����false
bool TeachingMission::addClass(string className)
{
	if (m_classesSet.find(className) != m_classesSet.end()) return false;
	m_classesSet.insert(className);
	return true;
}

//ɾ���༶��ɾ���ɹ�����true���༶�����ڷ���false
bool TeachingMission::deleteClass(string className)
{
	set<string>::iterator it;
	it = m_classesSet.find(className);
	if (it == m_classesSet.end()) return false;
	m_classesSet.erase(it);
	return true;
}

void TeachingMission::listClass() const
{
	if (m_classesSet.size() == 0) {
		cout << "��" << endl;
		return;
	}

	set<string>::iterator it = m_classesSet.begin();
	int count = 1;
	for (; it != m_classesSet.end(); it++, count++) {
		cout << *it << " ";
		/*if (count % 6 == 0) cout << endl;*/
	}
	/*if (count % 6 != 1) cout << endl;*/
	cout << endl;
}

bool TeachingMission::operator<(const TeachingMission & other) const
{
	return this->m_subjectName < other.m_subjectName;
}

ostream & operator<<(ostream & out, const TeachingMission & other)
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
