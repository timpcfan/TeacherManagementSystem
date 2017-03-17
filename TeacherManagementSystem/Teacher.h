#pragma once

#include <string>
#include <set>
#include "TeachingMission.h"

using namespace std;

class Teacher {
private:
	string m_id;					//��ʦ��
	string m_name;					//����
	string m_gender;				//�Ա�
	string m_post;					//ְ��
	set<TeachingMission> m_missionSet;	//��ѧ����


public:
	//initalization
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


public: //��ʱ�Ĺ��У�������
	//TeachingMissionMangement
	bool __assignMission(TeachingMission &teachingMission);			//�����ѧ����
	void __listMission();											//����ý�ʦ���н�ѧ����
	bool __deleteMission(unsigned int no);							//ɾ����ѧ����
	void __printLine(int n=50);										//��ӡ�ֽ���
	bool __reviseMission(unsigned int no);							//�޸Ľ�ѧ����
	const TeachingMission & __getMissionAt(unsigned int no) const;	//��ȡ��ѧ�������
	void __showRevisionMenu();
public:
	bool assignMission();
	bool deleteMission();
	bool reviseMission();
	void displayMission() const;



	//stream
	friend ostream& operator<<(ostream& out, const Teacher& teacher);


public:
	//comparator
	bool operator<(const Teacher& other);


};