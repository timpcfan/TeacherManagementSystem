#pragma once

#include <string>
#include <set>
#include "TeachingMission.h"

#include <boost\serialization\access.hpp>
#include <boost\serialization\set.hpp>
#include <boost\serialization\string.hpp>

using namespace std;

class Teacher {

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int) {
		ar & m_missionSet;
		ar & m_id & m_name & m_gender & m_post;
	}

private:
	string m_id;						//��ʦ��
	string m_name;						//����
	string m_gender;					//�Ա�
	string m_post;						//ְ��
	set<TeachingMission> m_missionSet;	//��ѧ����

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
	double getTotalWorkload() const; //ͳ�Ʋ����ظý�ʦ�ܹ�����

public:
	//��Ҫ���ܺ���
	bool assignMission();	//�����ѧ����
	bool deleteMission();	//ɾ����ѧ����
	bool reviseMission();	//�޸Ľ�ѧ����
	void displayMission();	//��ʾ���н�ѧ��������
	void showDetailInfo();	//��ʾ��ʦ��ϸ��Ϣ

private:
	//TeachingMissionManagement
	bool __assignMission(TeachingMission &teachingMission);			//�����ѧ����
	void __listMission();											//����ý�ʦ���н�ѧ����
	bool __deleteMission(unsigned int no);							//ɾ����ѧ����
	void __printLine(int n = 50);									//��ӡ�ֽ���
	const TeachingMission & __getMissionAt(unsigned int no) const;	//��ȡ��ѧ�������
	void __showRevisionMenu(const TeachingMission &teachingMission);//��ʾ��ѧ�����޸Ĳ˵�
	void __offset(string text, int offset = 16);					//��ʽ�����
	void __displayMission();										//��ʾ���н�ѧ��������

public:
	//comparator
	bool operator<(const Teacher& other) const;// <���������
	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);// <<���������
};