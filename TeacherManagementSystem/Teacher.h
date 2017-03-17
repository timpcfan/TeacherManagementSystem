#pragma once

#include <string>
#include <set>
#include "TeachingMission.h"

using namespace std;

class Teacher {
private:
	string m_id;					//教师号
	string m_name;					//姓名
	string m_gender;				//性别
	string m_post;					//职称
	set<TeachingMission> m_missionSet;	//教学任务


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


public: //临时改公有，测试用
	//TeachingMissionMangement
	bool __assignMission(TeachingMission &teachingMission);			//分配教学任务
	void __listMission();											//输出该教师所有教学任务
	bool __deleteMission(unsigned int no);							//删除教学任务
	void __printLine(int n=50);										//打印分界线
	bool __reviseMission(unsigned int no);							//修改教学任务
	const TeachingMission & __getMissionAt(unsigned int no) const;	//获取教学任务对象
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