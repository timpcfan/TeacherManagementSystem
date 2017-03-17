#include "Teacher.h"
#include "TeachingMission.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;





Teacher::Teacher(string id, string name, string gender, string post)
	:m_id(id), m_name(name), m_gender(gender), m_post(post)
{

}

string Teacher::getId() const
{
	return m_id;
}

void Teacher::setId(string id)
{
	m_id = id;
}

string Teacher::getName() const
{
	return m_name;
}

void Teacher::setName(string name)
{
	m_name = name;
}

string Teacher::getGender() const
{
	return m_gender;
}

void Teacher::setGender(string gender)
{
	m_gender = gender;
}

string Teacher::getPost() const
{
	return m_post;
}

void Teacher::setPost(string post)
{
	m_post = post;
}

bool Teacher::__assignMission(TeachingMission & teachingMission)
{
	m_missionSet.insert(teachingMission);
	return true;
}

void Teacher::__listMission()
{
	set<TeachingMission>::iterator it;
	int count = 1;
	for (it = m_missionSet.begin(); it != m_missionSet.end(); it++, count++) {
		cout << count << ":" << (*it).getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if(count % 3 != 1) cout << endl;
}

bool Teacher::__deleteMission(size_t no)
{
	if (no > m_missionSet.size() || no < 1) {
		return false;
	}
	set<TeachingMission>::iterator it = m_missionSet.begin();
	for (size_t i = 1; i < no; i++) it++;
	m_missionSet.erase(it);
	return true;
}

bool Teacher::assignMission()
{
	string subjectName;
	cout << "������γ����ƣ�";
	cin >> subjectName;
	int n;
	cout << "������༶������";
	cin >> n;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ����������������";
		cin >> n;
	}
	vector<string> vt;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cout << "�������" << i << "���༶��" ;
		cin >> tmp;
		vt.push_back(tmp);
	}
	double expTime, praTime;
	cout << "������ʵ���ʱ��" ;
	cin >> expTime;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> expTime;
	}
	cout << "���������ۿ�ʱ��" ;
	cin >> praTime;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> praTime;
	}

	TeachingMission *tm = new TeachingMission(subjectName, expTime, praTime);
	for(int i=0;i<n;i++) tm->addClass(vt.at(i));

	if (!__assignMission(*tm)) {
		cout << "��ӿγ�ʧ�ܣ�" << endl;
		return false;
	}
	cout << "��ӿγ̳ɹ���" << endl;
	return true;
}

bool Teacher::deleteMission()
{
	__listMission();
	size_t no;

	cout << "������Ҫɾ���Ľ�ѧ�����ţ�" ;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> no;
	}
	if (!__deleteMission(no)) {
		cout << "����ı������Ӧ�Ľ�ѧ���񲻴��ڣ�" << endl;
		return false;
	}
	cout << "ɾ���ɹ���" << endl;
	cout << "ʣ��Ľ�ѧ����Ϊ��" << endl;
	__listMission();
	return true;
}



