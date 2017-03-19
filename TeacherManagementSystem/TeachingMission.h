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
	unsigned int getNumOfClasses() const;
	double getTotalClassHour() const;

	//class management
	bool addClass(string className);
	bool deleteClass(string className);
	void listClass() const;


	//stream
	friend ostream & operator<<(ostream& out, const TeachingMission& other);

	//comparator
	bool operator<(const TeachingMission& other) const;

};