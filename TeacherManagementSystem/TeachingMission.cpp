#include "TeachingMission.h"
#include <set>

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

size_t TeachingMission::getNumOfClasses() const
{
	return m_classesSet.size();
}

//插入班级，插入成功返回true，若已存在同样的班级返回false
bool TeachingMission::addClass(string className)
{
	if (m_classesSet.find(className) != m_classesSet.end()) return false;
	m_classesSet.insert(className);
	return true;
}

//删除班级，删除成功返回true，班级不存在返回false
bool TeachingMission::deleteClass(string className)
{
	set<string>::iterator it;
	it = m_classesSet.find(className);
	if (it == m_classesSet.end()) return false;
	m_classesSet.erase(it);
	return true;
}

bool TeachingMission::operator<(const TeachingMission & other) const
{
	return this->m_subjectName < other.m_subjectName;
}
