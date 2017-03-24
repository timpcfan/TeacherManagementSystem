#pragma once

#include <string>
#include <set>
#include "TeachingTask.h"

using namespace std;

class Teacher {
private:
	string m_id;						//��ʦ��
	string m_name;						//����
	string m_gender;					//�Ա�
	string m_post;						//ְ��
	set<TeachingTask> m_taskSet;		//��ѧ����

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
	bool assignTask();		//�����ѧ����
	bool deleteMission();	//ɾ����ѧ����
	bool reviseTask();		//�޸Ľ�ѧ����
	void displayTask();		//��ʾ���н�ѧ��������
	void showDetailInfo();	//��ʾ��ʦ��ϸ��Ϣ

private:
	//TeachingMissionManagement
	bool __assignMission(TeachingTask &teachingMission);			//�����ѧ����
	void __listTask();												//����ý�ʦ���н�ѧ����
	bool __deleteTask(unsigned int no);								//ɾ����ѧ����
	void __printLine(int n = 50);									//��ӡ�ֽ���
	const TeachingTask & __getTaskAt(unsigned int no) const;		//��ȡ��ѧ�������
	void __showRevisionMenu(const TeachingTask &teachingMission);	//��ʾ��ѧ�����޸Ĳ˵�
	void __offset(string text, int offset = 16);					//��ʽ�����
	void __displayTask();											//��ʾ���н�ѧ��������

public:
	//comparator
	bool operator<(const Teacher& other) const;// <���������
	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);// <<���������
};