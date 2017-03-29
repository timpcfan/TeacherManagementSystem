#pragma once

#include <string>
#include "MyDisorderedList.h"
#include "TeachingTask.h"

using namespace std;

class Teacher {
private:
	string m_id;								//教师号
	string m_name;								//姓名
	string m_gender;							//性别
	string m_post;								//职称
	MyDisorderedList<TeachingTask> m_taskList;	//教学任务

public:
	//initialization
	Teacher();
	Teacher(string id, string name, string gender, string post);
	
	//setter and getter
	string getId() const;
	void setId(string id);
	string getName() const;
	void setName(string name);
	string getGender() const;
	void setGender(string gender);
	string getPost() const;
	void setPost(string post);
	int getTaskNum() const;
	double getTotalWorkload() const; //统计并返回该教师总工作量

public:
	//主要功能函数
	bool assignTask();													//分配教学任务
	bool deleteMission();												//删除教学任务
	bool reviseTask();													//修改教学任务
	void displayTask();													//显示所有教学任务详情
	void showDetailInfo();												//显示教师详细信息
	void showTeacherRevisionMenu();										//显示教师修改菜单

public:
	//TeachingMissionManagement
	void __listTask();													//输出该教师所有教学任务
	void __displayTask();												//显示所有教学任务详情
	void __printLine(int n = 50);										//打印分界线
	int  __waitForRequest(int max);										//接收用户输入的指令
	bool __deleteTask(unsigned int no);									//删除教学任务
	void __offset(string text, int offset = 16);						//格式化输出
	bool __assignTask(TeachingTask &teachingTask);						//分配教学任务
	void __showTaskRevisionMenu(const TeachingTask &teachingTask);		//显示教学任务修改菜单
	TeachingTask * __getTaskAt(unsigned no);							//获取教学任务对象
	string __toString();

public:
	//comparator
	bool operator<(const Teacher& other) const;// <运算符重载
	bool operator==(const Teacher& other) const;// ==运算符重载
	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);// <<运算符重载
};