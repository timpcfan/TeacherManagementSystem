#pragma once

#include <string>
#include "MyOrderedList.h"

using namespace std;

class TeachingTask {
private:
	double m_expTime;						//ʵ���ʱ
	double m_praTime;						//���ۿ�ʱ
	string m_subjectName;					//�ν̿γ�
	MyOrderedList<string> m_classesList;	//�༶����

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
	unsigned int getNumOfClasses() const;	//��ȡ�༶����
	double getTotalClassHour() const;		//���㲢���ص�����ѧ�����ܿ�ʱ

	//class management
	bool addClass(string className);		//��Ӱ༶
	bool deleteClass(string className);		//ɾ���༶
	void listClass() const;					//�г��༶���������

public:
	//comparator
	bool operator<(const TeachingTask& other) const;	// <���������
	bool operator==(const TeachingTask& other) const;	// ==���������
	//stream
	friend ostream & operator<<(ostream& out, const TeachingTask& other);// <<���������
};