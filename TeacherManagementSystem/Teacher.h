#pragma once

#include <string>
#include "MyDisorderedList.h"
#include "TeachingTask.h"

using namespace std;

class Teacher {
private:
	string m_id;								//��ʦ��
	string m_name;								//����
	string m_gender;							//�Ա�
	string m_post;								//ְ��
	MyDisorderedList<TeachingTask> m_taskList;	//��ѧ����

public:
	//initialization
	Teacher();
	Teacher(string id, string name, string gender, string post);
	
	//setter and getter
	string getId() const;
	void setId(string id);
	string getName() const;
	void setName(string name);
	string getGender() const;
	void setGender(string gender);
	string getPost() const;
	void setPost(string post);
	int getTaskNum() const;
	double getTotalWorkload() const; //ͳ�Ʋ����ظý�ʦ�ܹ�����

public:
	//��Ҫ���ܺ���
	bool assignTask();													//�����ѧ����
	bool deleteMission();												//ɾ����ѧ����
	bool reviseTask();													//�޸Ľ�ѧ����
	void displayTask();													//��ʾ���н�ѧ��������
	void showDetailInfo();												//��ʾ��ʦ��ϸ��Ϣ
	void showTeacherRevisionMenu();										//��ʾ��ʦ�޸Ĳ˵�

public:
	//TeachingMissionManagement
	void __listTask();													//����ý�ʦ���н�ѧ����
	void __displayTask();												//��ʾ���н�ѧ��������
	void __printLine(int n = 50);										//��ӡ�ֽ���
	int  __waitForRequest(int max);										//�����û������ָ��
	bool __deleteTask(unsigned int no);									//ɾ����ѧ����
	void __offset(string text, int offset = 16);						//��ʽ�����
	bool __assignTask(TeachingTask &teachingTask);						//�����ѧ����
	void __showTaskRevisionMenu(const TeachingTask &teachingTask);		//��ʾ��ѧ�����޸Ĳ˵�
	TeachingTask * __getTaskAt(unsigned no);							//��ȡ��ѧ�������
	string __toString();

public:
	//comparator
	bool operator<(const Teacher& other) const;// <���������
	bool operator==(const Teacher& other) const;// ==���������
	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);// <<���������
};