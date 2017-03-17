#pragma once

#include <string>
#include <set>

using namespace std;

class TeachingMission {
private:
	string m_subjectName;		//任教课程
	set<string> m_classesSet;	//班级
	double m_expTime;			//实验课时
	double m_praTime;			//理论课时

public:
	//initalization
	TeachingMission(string subjectName,double expTime,double praTime);

	//getter and setter
	void setName(string name);
	string getName() const;
	void setExpTime(double time);
	double getExpTime() const;
	void setPraTime(double time);
	double getPraTime() const;
	size_t getNumOfClasses() const;

	//class management
	bool addClass(string className);
	bool deleteClass(string className);


	//comparator
	bool operator<(const TeachingMission& other) const;

};