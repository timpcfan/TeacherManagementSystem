#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

bool TeacherManagementSystem::addTeacher()
{
	__printLine();
	cout << "��ӽ�ʦ" << endl;
	__printLine();

	string id;
	cout << "�������ʦID��" << endl;
	cin >> id;
	while (__isExisted(id)) {
		cout << "IDΪ" << id << "�Ľ�ʦ�Ѵ��ڣ�" << endl;
		cout << "���������룺" << endl;
	}
	cout << "ID�ѳɹ�����Ϊ��" << id << endl;

	string name;
	cout << "�������ʦ������" << endl;
	cin >> name;
	cout << "�����ѳɹ�����Ϊ��" << name << endl;

	string gender;
	cout << "�������ʦ�Ա���/Ů��:" << endl;
	while (gender != "��" && gender != "Ů") {
		cout << "�������" << endl;
		cout << "�����롰�С���Ů����" << endl;
		cin >> gender;
	}

	string post;
	cout << "������ְ�Ƶı��" << endl;
	cout << "1-���̣�2-��ʦ��3-�����ڣ�4-����" << endl;
	cin >> post;
	while (post != "1" && post != "2" && post != "3" && post != "4") {
		cout << "�������" << endl;
		cout << "����������1��4" << endl;
		cout << "1-���̣�2-��ʦ��3-�����ڣ�4-����" << endl;
		cin >> post;
	}
	if (post == "1") post == "����";
	else if (post == "2") post == "��ʦ";
	else if (post == "3") post == "������";
	else if (post == "4") post == "����";
	else {
		cout << "δ֪����" << endl;
		return false;
	}

	
	if (!__addTeacher(Teacher(id, name, gender, post))) {
		cout << "��ӽ�ʦʧ�ܣ�" << endl;
		return false;
	}

	cout << "��ʦ����ӣ�" << endl;
	//TODO ��ӽ�ʦ��Ϣ��ʾ
	return true;
}

//����½�ʦ������뼯�ϣ��ɹ�����true����id�ظ����򷵻�false
bool TeacherManagementSystem::__addTeacher(Teacher & teacher)
{
	string id = teacher.getId();

	if (__isExisted(id)) return false;
	
	m_teacherMap.insert(make_pair(id,teacher));
	return true;
}

//ɾ����ʦ��������ɹ�����true����ʦid�����ڷ���false
bool TeacherManagementSystem::__deleteTeacher(string id)
{
	if (!__isExisted(id)) return false;

	m_teacherMap.erase(id);
	return true;
}

void TeacherManagementSystem::__printLine(int n)
{
	while (n--) cout << '*';
	cout << endl;
}

//���id�Ѵ��ڷ���true�����򷵻�false
bool TeacherManagementSystem::__isExisted(string id)
{
	if (m_teacherMap.find(id) == m_teacherMap.end()) return false;
	return true;
}

void TeacherManagementSystem::__listTeacher() const
{
	if (m_teacherMap.size() == 0) {
		cout << "��" << endl;
		return;
	}

	unsigned int count = 1;
	map<string,Teacher>::const_iterator it = m_teacherMap.begin();
	for (; it != m_teacherMap.end(); it++, count++) {
		cout << it->first << ":" << it->second << "\t";
		if (count % 4 == 0) cout << endl;
	}
	if (count % 4 != 1) cout << endl;

}
