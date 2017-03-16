#pragma once

#include <string>
#include <set>
#include "TeachingInfo.h"

using namespace std;

class Teacher {
private:
	string m_id;					//��ʦ��
	string m_name;					//����
	string m_gender;				//�Ա�
	string m_post;					//ְ��
	set<TeachingInfo> m_teaMission;	//��ѧ����


public:
	//initation
	Teacher(string id,string name,string gender,string post);
	
	//setter and getter
	string getId();
	void setId(string id);
	string getName();
	void setName(string name);
	string getGender();
	void setGender(string gender);
	string getPost();
	void setPost(string post);

	//TeachingMissionMangement
	bool assignMission(TeachingInfo &teachingInfo);
	void printMission();
	bool deleteMission();

	//stream
	friend ostream& operator<<(const ostream& out, const Teacher& teacher);


	//comparator
	bool operator<(const Teacher& other);

	void printInfo();

};