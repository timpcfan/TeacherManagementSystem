#include "TeachingInfo.h"
#include <set>

TeachingInfo::TeachingInfo(string subjectName, double expTime, double praTime)
	:m_subjectName(subjectName),m_expTime(expTime),m_praTime(praTime)
{
}

void TeachingInfo::setName(string name)
{
	m_subjectName = name;
}

string TeachingInfo::getName()
{
	return m_subjectName;
}

void TeachingInfo::setExpTime(double time)
{
	m_expTime = time;
}

double TeachingInfo::getExpTime()
{
	return m_expTime;
}

void TeachingInfo::setPraTime(double time)
{
	m_praTime = time;
}

double TeachingInfo::getPraTime()
{
	return m_praTime;
}

int TeachingInfo::getNumOfClasses()
{
	return m_classesSet.size();
}

//����༶������ɹ�����true�����Ѵ���ͬ���İ༶����false
bool TeachingInfo::addClass(string className)
{
	if (m_classesSet.find(className) != m_classesSet.end()) return false;
	m_classesSet.insert(className);
	return true;
}

//ɾ���༶��ɾ���ɹ�����true���༶�����ڷ���false
bool TeachingInfo::deleteClass(string className)
{
	set<string>::iterator it;
	it = m_classesSet.find(className);
	if (it == m_classesSet.end()) return false;
	m_classesSet.erase(it);
	return true;
}

bool TeachingInfo::operator<(const TeachingInfo & other) const
{
	return this->m_subjectName < other.m_subjectName;
}
