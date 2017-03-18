#pragma once

#include <map>
#include "Teacher.h"

using namespace std;

class TeacherManagementSystem {

private:
	map<string,Teacher> m_teacherMap;	//教师集合


public:
	//initalization
	TeacherManagementSystem();

	//启动系统
	void start();

	//teacher management
	bool addTeacher();
	bool deleteTeacher();
	void sortAndShowTeacher();


private:
	void __listTeacher() const;
	bool __addTeacher(Teacher &teacher);
	bool __deleteTeacher(string id);
	void __printLine(int n = 50);
	bool __isExisted(string id);
	void __offset(string text, int offset = 16);
	int __waitForRequest(int max);
	
	//Menu
	void __showMainMenu();
	void __showTeacherMenu();
	void __showTeacherManagementMenu(const Teacher &teacher);
	void __showTeachingMissionMenu();

};