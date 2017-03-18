#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

void TeacherManagementSystem::__listTeacher() const
{
	if (m_teacherSet.size() == 0) {
		cout << "нч" << endl;
		return;
	}

	unsigned int count = 1;
	set<Teacher>::iterator it = m_teacherSet.begin();
	for (; it != m_teacherSet.end(); it++, count++) {
		cout << (*it).getId() << ":" << (*it).getName() << endl;
	}


}
