#pragma once
#include "MyDisorderedList.h"
#include "Teacher.h"

using namespace std;

class TeacherManagementSystem {

private:
	MyDisorderedList<Teacher> m_teacherList;		//��ʦ����

public:
	//initialization
	TeacherManagementSystem();

	//����ϵͳ
	void start();									//����������

	//��Ҫ���ܺ���
	bool addTeacher();								//��ӽ�ʦ
	bool deleteTeacher();							//ɾ����ʦ
	void sortAndShowTeacher();						//������ʾ��ʦ
	void displayWorkingStat();						//��ʾ������ͳ����Ϣ
	void reviseTeacher(Teacher *p);					//�޸Ľ�ʦ��Ϣ
	void loadData();								//��ȡ����
	void saveData();								//�洢����

private:
	void __listTeacher() const;						//������ʾ��ʦ
	bool __addTeacher(Teacher &teacher);			//��ӽ�ʦ
	bool __deleteTeacher(string id);				//ɾ�����Ϊid�Ľ�ʦ
	void __printLine(int n = 50);					//��ӡ�ֽ���
	bool __isExisted(string id);					//���ID�Ƿ����
	void __offset(string text, int offset = 16);	//��ʽ�����
	int __waitForRequest(int max);					//�����û������ָ��
	double __getAllWorkload();						//��ȡȫ��������
	pair<double,int> __getMaleWorkloadAndNum();		//��ȡȫ�����Խ�ʦ������������
	pair<double,int> __getFemaleWorkloadAndNum();	//��ȡȫ��Ů�Խ�ʦ������������
	Teacher * __getTeacherById(string id);
	
	//Menu
	void __showMainMenu();										//��ʾ���˵�
	void __showTeacherMenu();									//��ʾ��ʦ����˵�
	void __showTeacherManagementMenu(const Teacher &teacher);	//��ʾ��ʦ�༭�˵�
	void __showTeachingMissionMenu();							//��ʾ��ѧ�������˵�
};