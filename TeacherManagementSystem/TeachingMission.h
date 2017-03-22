#pragma once

#include <string>
#include <set>

#include <boost\serialization\access.hpp>
#include <boost\serialization\set.hpp>
#include <boost\serialization\string.hpp>

using namespace std;

class TeachingMission {

private://����Ƕ������л��Ĵ��룬��������Ա�浵�浵
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int) {
		ar & m_classesSet;
		ar & m_subjectName;
		ar & m_expTime & m_praTime;
	}


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
	unsigned int getNumOfClasses() const;	//��ȡ�༶����
	double getTotalClassHour() const;		//���㲢���ص�����ѧ�����ܿ�ʱ

	//class management
	bool addClass(string className);	//��Ӱ༶
	bool deleteClass(string className);	//ɾ���༶
	void listClass() const;				//�г��༶���������

public:
	//comparator
	bool operator<(const TeachingMission& other) const;	// <���������
	//stream
	friend ostream & operator<<(ostream& out, const TeachingMission& other);// <<���������
};