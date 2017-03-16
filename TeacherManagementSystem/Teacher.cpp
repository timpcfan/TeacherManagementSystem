#include "Teacher.h"
#include <iostream>

using std::cout;
using std::endl;





Teacher::Teacher(string id, string name, string gender, string post)
	:m_id(id), m_name(name), m_gender(gender), m_post(post)
{

}

string Teacher::getId()
{
	return m_id;
}

void Teacher::setId(string id)
{
	m_id = id;
}

string Teacher::getName()
{
	return m_name;
}

void Teacher::setName(string name)
{
	m_name = name;
}

string Teacher::getGender()
{
	return m_gender;
}

void Teacher::setGender(string gender)
{
	m_gender = gender;
}

string Teacher::getPost()
{
	return m_post;
}

void Teacher::setPost(string post)
{
	m_post = post;
}

bool Teacher::assignMission(TeachingInfo & teachingInfo)
{
	m_missionSet.insert(teachingInfo);
	return true;
}

void Teacher::printInfo()
{
	cout << "[" << m_id << "," << m_name << "," << m_gender << "," << m_post << "]" << endl;

}
