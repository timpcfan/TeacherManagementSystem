#pragma once

#include <string>
#include <set>

using namespace std;

class TeachingMission {
private:
	string m_subjectName;		//�ν̿γ�
	set<string> m_classesSet;	//�༶
	double m_expTime;			//ʵ���ʱ
	double m_praTime;			//���ۿ�ʱ

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