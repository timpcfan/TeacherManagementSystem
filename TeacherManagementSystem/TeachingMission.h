#pragma once

#include <string>
#include <set>

#include <boost\serialization\access.hpp>
#include <boost\serialization\set.hpp>
#include <boost\serialization\string.hpp>

using namespace std;

class TeachingMission {

private://这段是对象序列化的代码，将各个成员存档存档
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int) {
		ar & m_classesSet;
		ar & m_subjectName;
		ar & m_expTime & m_praTime;
	}


private:
	string m_subjectName;		//任教课程
	set<string> m_classesSet;	//班级
	double m_expTime;			//实验课时
	double m_praTime;			//理论课时

public:
	//initialization
	TeachingMission();
	TeachingMission(string subjectName,double expTime,double praTime);

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
	bool addClass(string className);	//添加班级
	bool deleteClass(string className);	//删除班级
	void listClass() const;				//列出班级并分配序号

public:
	//comparator
	bool operator<(const TeachingMission& other) const;	// <运算符重载
	//stream
	friend ostream & operator<<(ostream& out, const TeachingMission& other);// <<运算符重载
};