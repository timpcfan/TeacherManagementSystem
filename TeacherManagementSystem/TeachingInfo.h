#pragma once

#include <string>
#include <set>

using namespace std;

class TeachingInfo {
private:
	string m_subjectName;		//任教课程
	set<string> m_classesSet;	//班级
	double m_expTime;			//实验课时
	double m_praTime;			//理论课时

public:
	//initation
	TeachingInfo(string subjectName,double expTime,double praTime);

	//getter and setter
	void setName(string name);
	string getName();
	void setExpTime(double time);
	double getExpTime();
	void setPraTime(double time);
	double getPraTime();
	int getNumOfClasses();

	//class management
	bool addClass(string className);
	bool deleteClass(string className);


	//comparator
	bool operator<(const TeachingInfo& other) const;

};