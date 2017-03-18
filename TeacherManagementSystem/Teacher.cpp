#include "Teacher.h"
#include "TeachingMission.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;





Teacher::Teacher()
{
}

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

double Teacher::getTotalWorkload() const
{
	double ret = 0;
	set<TeachingMission>::const_iterator it = m_missionSet.begin();
	for (; it != m_missionSet.end(); it++) ret += it->getTotalClassHour();
	return ret;
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

bool Teacher::__deleteMission(unsigned int no)
{
	if (no > m_missionSet.size() || no < 1) {
		return false;
	}
	set<TeachingMission>::iterator it = m_missionSet.begin();
	for (unsigned int i = 1; i < no; i++) it++;
	m_missionSet.erase(it);
	return true;
}

void Teacher::__printLine(int n)
{
	while (n--) cout << '*';
	cout << endl;
}

const TeachingMission & Teacher::__getMissionAt(unsigned int no) const
{
	if (no > m_missionSet.size() || no < 1) return TeachingMission();
	set<TeachingMission>::iterator it = m_missionSet.begin();
	for (unsigned int i = 1; i < no; i++) it++;
	return *it;
}

bool Teacher::assignMission()
{
	system("cls");
	__printLine();
	__offset("��ӽ�ѧ����", 18);
	__printLine();
	string subjectName;
	cout << "������γ����ƣ�";
	cin >> subjectName;
	while (m_missionSet.find(TeachingMission(subjectName, 0, 0)) != m_missionSet.end()) {
		cout << subjectName << "�Ѿ����ڣ�����������γ����ƣ�";
		cin >> subjectName;
	}

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

	//TeachingMission *tm = new TeachingMission(subjectName, expTime, praTime);
	//for(int i=0;i<n;i++) tm->addClass(vt.at(i));

	TeachingMission tm(subjectName, expTime, praTime);
	for(int i=0;i<n;i++) tm.addClass(vt.at(i));

	if (!__assignMission(tm)) {
		cout << "��ӿγ�ʧ�ܣ�" << endl;
		return false;
	}
	cout << "��ӿγ̳ɹ���" << endl;
	cout << "��ѧ��Ϣ���£�" << endl;
	cout << tm << endl;
	system("pause");
	return true;
}

bool Teacher::deleteMission()
{
	system("cls");
	__printLine();
	__offset("ɾ����ѧ����", 18);
	__printLine();

	if (m_missionSet.size() == 0) {
		cout << "û�н�ѧ����" << endl;
		system("pause");
		return false;
	}


	__listMission();
	size_t no;

	cout << "������Ҫɾ���Ľ�ѧ�����ţ�����������0����" ;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> no;
	}
	if (no == 0) {
		return false;
	}
	if (!__deleteMission(no)) {
		cout << "����ı������Ӧ�Ľ�ѧ���񲻴��ڣ�" << endl;
		system("pause");
		return false;
	}
	cout << "ɾ���ɹ���" << endl;
	cout << "ʣ��Ľ�ѧ����Ϊ��";
	__listMission();
	return true;
}

void Teacher::__showRevisionMenu()
{
	cout << "������Ҫ�޸ĵ����ݱ�ţ�";
	cout << "1 - �޸Ŀγ�����" << endl;
	cout << "2 - ��Ӱ༶" << endl;
	cout << "3 - ɾ���༶" << endl;
	cout << "4 - �޸�ʵ���ʱ" << endl;
	cout << "5 - �޸����ۿ�ʱ" << endl;
	cout << "6 - ����޸�" << endl;
}

void Teacher::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

bool Teacher::reviseMission()
{
	system("cls");
	__printLine();
	__offset("�޸Ľ�ѧ����", 18);
	__printLine();

	if (m_missionSet.size() == 0) {
		cout << "û�н�ѧ����" << endl;
		system("pause");
		return false;
	}


	__listMission();

	unsigned int no;
	cout << "������Ҫ�޸ĵĽ�ѧ�����ţ�";
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> no;
	}
	if (no > m_missionSet.size() || no < 1) {
		cout << "û�ж�Ӧ��ŵĽ�ѧ����" << endl;
		__printLine();
		return false;
	}

	TeachingMission tmp(__getMissionAt(no));

	while (true) { //��ʼ�޸�
		cout << tmp;
		__showRevisionMenu();
		string op;
		cin >> op;
		if (op == "1") {
			cout << "�������޸ĺ�Ŀγ����ƣ�";
			string newName;
			cin >> newName;
			tmp.setName(newName);
			cout << "�γ��������޸�Ϊ��" << tmp.getName() << endl;
		}
		else if(op == "2"){
			cout << "������Ҫ��ӵİ༶���ƣ�";
			string newClass;
			cin >> newClass;
			if (!tmp.addClass(newClass)) cout << "�༶�Ѵ��ڣ����ڵİ༶�У�";
			else cout << "��ӳɹ������ڵİ༶�У�";
			tmp.listClass();
		}
		else if (op == "3") {
			tmp.listClass();
			cout << "������Ҫɾ���İ༶���ƣ�";
			string classToDelete;
			cin >> classToDelete;
			if (!tmp.deleteClass(classToDelete)) cout << "����İ༶�����ڣ�" << endl;
			else cout << "ɾ���ɹ���" << endl;
			cout << "ʣ��İ༶���У�";
			tmp.listClass();
		}
		else if (op == "4") {
			double expTime;
			cout << "�������޸ĺ��ʵ���ʱ��";
			cin >> expTime;
			while (cin.fail() || cin.peek() != '\n') { //���������
				cin.clear();
				while (cin.get() != '\n');
				cout << "�����ʽ�������������֣�";
				cin >> expTime;
			}
			tmp.setExpTime(expTime);
			cout << "ʵ���ʱ���޸�Ϊ��" << tmp.getExpTime() << endl;
		}
		else if (op == "5") {
			double praTime;
			cout << "�������޸ĺ�����ۿ�ʱ��";
			cin >> praTime;
			while (cin.fail() || cin.peek() != '\n') { //���������
				cin.clear();
				while (cin.get() != '\n');
				cout << "�����ʽ�������������֣�";
				cin >> praTime;
			}
			tmp.setPraTime(praTime);
			cout << "ʵ���ʱ���޸�Ϊ��" << tmp.getPraTime() << endl;
		}
		else if (op == "6") {
			break;
		}
		else {
			cout << "ָ�������������������!" << endl;
		}
	}
	



	if (!__deleteMission(no)) {
		cout << "�޸�ʧ�ܣ��޷�ɾ��ԭ����" << endl;
		return false;
	}
	if (!__assignMission(tmp)) {
		cout << "�޸�ʧ�ܣ��޷����������" << endl;
		return false;
	}


	cout << "�޸ĳɹ���" << endl;
	cout << tmp << endl;
	system("pause");
	return true;
}

void Teacher::displayMission()
{
	system("cls");
	__printLine();
	__offset("��ϸ��ѧ�����嵥");
	__printLine();
	cout << "           ";
	cout << m_name << m_post <<"һ����" << m_missionSet.size() << "����ѧ����" << endl;

	set<TeachingMission>::iterator it;
	for (it = m_missionSet.begin(); it != m_missionSet.end(); it++) {
		cout << *it;
	}
	cout << endl;
	system("pause");
}

bool Teacher::operator<(const Teacher & other) const
{
	if (getTotalWorkload() > other.getTotalWorkload()) return true;
	return getId() < other.getId();
}

ostream & operator<<(ostream & out, const Teacher & teacher)
{
	out << "[" << "ID��" << teacher.getId() << "��������" << teacher.getName()
		<< "��ְ�ƣ�" << teacher.getPost() << "���ܽ�ѧ��������" 
		<< teacher.getTotalWorkload() << "]";
	return out;
}
