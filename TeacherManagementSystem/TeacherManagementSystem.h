#pragma once

#include <map>
#include "Teacher.h"

#include <boost\serialization\access.hpp>
#include <boost\serialization\map.hpp>


using namespace std;

class TeacherManagementSystem {

private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int) {
		ar & m_teacherMap;
	}

private:
	map<string,Teacher> m_teacherMap;	//��ʦ����


public:
	//initialization
	TeacherManagementSystem();

	//����ϵͳ
	void start();	//����������

	//��Ҫ���ܺ���
	bool addTeacher();							//��ӽ�ʦ
	bool deleteTeacher();						//ɾ����ʦ
	void sortAndShowTeacher();					//������ʾ��ʦ
	Teacher * reviseTeacher(Teacher &teacher);	//�޸Ľ�ʦ
	void displayWorkingStat();					//��ʾ������ͳ����Ϣ
	void saveData();
	void loadData();

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
	
	//Menu
	void __showMainMenu();										//��ʾ���˵�
	void __showTeacherMenu();									//��ʾ��ʦ����˵�
	void __showTeacherManagementMenu(const Teacher &teacher);	//��ʾ��ʦ�༭�˵�
	void __showTeachingMissionMenu();							//��ʾ��ѧ�������˵�
	void __showTeacherRevisionMenu(const Teacher &teacher);		//��ʾ��ʦ�޸Ĳ˵�
};