#pragma once

#include <set>
#include "Teacher.h"

using namespace std;

class TeacherManagementSystem {

private:
	set<Teacher> m_teacherSet;	//��ʦ����


public:
	//initalization
	TeacherManagementSystem();

	//����ϵͳ
	void start();

	//teacher management
	void addTeacher(Teacher &teacher);
	void deleteTeacher();

	//Menu
	void showMainMenu();
	void showTeacherMenu();
	void showTeachingInfoMenu();

};