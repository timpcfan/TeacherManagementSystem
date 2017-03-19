#pragma once

#include <string>
#include <set>
#include "TeachingMission.h"

using namespace std;

class Teacher {
private:
	string m_id;						//教师号
	string m_name;						//姓名
	string m_gender;					//性别
	string m_post;						//职称
	set<TeachingMission> m_missionSet;	//教学任务

public:
	//initialization
	Teacher();
	Teacher(string id,string name,string gender,string post);
	
	//setter and getter
	string getId() const;
	void setId(string id);
	string getName() const;
	void setName(string name);
	string getGender() const;
	void setGender(string gender);
	string getPost() const;
	void setPost(string post);
	double getTotalWorkload() const; //统计并返回该教师总工作量

public:
	//主要功能函数
	bool assignMission();	//分配教学任务
	bool deleteMission();	//删除教学任务
	bool reviseMission();	//修改教学任务
	void displayMission();	//显示所有教学任务详情
	void showDetailInfo();	//显示教师详细信息

private:
	//TeachingMissionManagement
	bool __assignMission(TeachingMission &teachingMission);			//分配教学任务
	void __listMission();											//输出该教师所有教学任务
	bool __deleteMission(unsigned int no);							//删除教学任务
	void __printLine(int n = 50);									//打印分界线
	const TeachingMission & __getMissionAt(unsigned int no) const;	//获取教学任务对象
	void __showRevisionMenu(const TeachingMission &teachingMission);//显示教学任务修改菜单
	void __offset(string text, int offset = 16);					//格式化输出
	void __displayMission();										//显示所有教学任务详情

public:
	//comparator
	bool operator<(const Teacher& other) const;// <运算符重载
	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);// <<运算符重载
};