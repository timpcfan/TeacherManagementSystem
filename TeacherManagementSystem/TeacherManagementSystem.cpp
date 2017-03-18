#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

//添加新教师对象进入集合，成功返回true，若id重复，则返回false
bool TeacherManagementSystem::__addTeacher(Teacher & teacher)
{
	string id = teacher.getId();

	if (m_teacherMap.find(id) != m_teacherMap.end()) return false;
	
	m_teacherMap.insert(make_pair(id,teacher));
	return true;
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
