#pragma once

#include <string>
#include <set>

using namespace std;

class TeachingInfo {
private:
	string m_subjectName;		//�ν̿γ�
	set<string> m_classesSet;	//�༶
	double m_expTime;			//ʵ���ʱ
	double m_praTime;			//���ۿ�ʱ

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