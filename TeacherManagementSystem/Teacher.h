#pragma once

#include <string>
#include <set>
#include "TeachingInfo.h"

using namespace std;

class Teacher {
private:
	string m_id;					//教师号
	string m_name;					//姓名
	string m_gender;				//性别
	string m_post;					//职称
	set<TeachingInfo> m_teaMission;	//教学任务


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