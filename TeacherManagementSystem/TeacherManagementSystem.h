#pragma once

#include <set>
#include "Teacher.h"

using namespace std;

class TeacherManagementSystem {

private:
	set<Teacher> m_teacherSet;	//教师集合


public:
	TeacherManagementSystem();

	//启动系统
	void start();

	//teacher management
	void addTeacher(Teacher &teacher);
	void deleteTeacher();

};