#pragma once

#include <string>
#include "MyOrderedList.h"

using namespace std;

class TeachingTask {
private:
	double m_expTime;						//实验课时
	double m_praTime;						//理论课时
	string m_subjectName;					//任教课程
	MyOrderedList<string> m_classesList;	//班级链表

public:
	//initialization
	TeachingTask();
	TeachingTask(string subjectName,double expTime,double praTime);

	//getter and setter
	void setName(string name);
	string getName() const;
	void setExpTime(double time);
	double getExpTime() const;
	void setPraTime(double time);
	double getPraTime() const;
	unsigned int getNumOfClasses() const;	//获取班级数量
	double getTotalClassHour() const;		//计算并返回单个教学任务总课时

	//class management
	bool addClass(string className);		//添加班级
	bool deleteClass(string className);		//删除班级
	void listClass() const;					//列出班级并分配序号

public:
	//comparator
	bool operator<(const TeachingTask& other) const;	// <运算符重载
	bool operator==(const TeachingTask& other) const;	// ==运算符重载
	//stream
	friend ostream & operator<<(ostream& out, const TeachingTask& other);// <<运算符重载
};