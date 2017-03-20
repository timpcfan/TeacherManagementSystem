#pragma once

#include <map>
#include "Teacher.h"

#include <boost\serialization\access.hpp>
#include <boost\serialization\map.hpp>


using namespace std;

class TeacherManagementSystem {

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int) {
		ar & m_teacherMap;
	}

private:
	map<string,Teacher> m_teacherMap;	//教师集合


public:
	//initialization
	TeacherManagementSystem();

	//启动系统
	void start();	//主启动函数

	//主要功能函数
	bool addTeacher();							//添加教师
	bool deleteTeacher();						//删除教师
	void sortAndShowTeacher();					//排序并显示教师
	Teacher * reviseTeacher(Teacher &teacher);	//修改教师
	void displayWorkingStat();					//显示工作量统计信息
	void saveData();
	void loadData();

private:
	void __listTeacher() const;						//排列显示教师
	bool __addTeacher(Teacher &teacher);			//添加教师
	bool __deleteTeacher(string id);				//删除编号为id的教师
	void __printLine(int n = 50);					//打印分界线
	bool __isExisted(string id);					//检测ID是否存在
	void __offset(string text, int offset = 16);	//格式化输出
	int __waitForRequest(int max);					//接收用户输入的指令
	double __getAllWorkload();						//获取全部工作量
	pair<double,int> __getMaleWorkloadAndNum();		//获取全体男性教师工作量和数量
	pair<double,int> __getFemaleWorkloadAndNum();	//获取全体女性教师工作量和数量
	
	//Menu
	void __showMainMenu();										//显示主菜单
	void __showTeacherMenu();									//显示教师管理菜单
	void __showTeacherManagementMenu(const Teacher &teacher);	//显示教师编辑菜单
	void __showTeachingMissionMenu();							//显示教学任务管理菜单
	void __showTeacherRevisionMenu(const Teacher &teacher);		//显示教师修改菜单
};