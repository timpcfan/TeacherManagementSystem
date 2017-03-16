#pragma once

#include <set>
#include "Teacher.h"

using namespace std;

class TeacherManagementSystem {

private:
	set<Teacher> m_teacherSet;	//��ʦ����


public:
	TeacherManagementSystem();

	//����ϵͳ
	void start();

	//teacher management
	void addTeacher(Teacher &teacher);
	void deleteTeacher();

};