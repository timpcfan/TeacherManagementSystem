#include "Teacher.h"
#include "TeachingTask.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


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
	MyIterator<TeachingTask> it = m_taskList.begin();
	for (; it != m_taskList.end(); it++) ret += it->getTotalClassHour();
	return ret;
}

bool Teacher::__assignMission(TeachingTask & teachingTask)
{
	m_taskList.push_back(teachingTask);
	return true;
}

void Teacher::__listTask()
{
	MyIterator<TeachingTask> it;
	int count = 1;
	for (it = m_taskList.begin(); it != m_taskList.end(); it++, count++) {
		cout << count << ":" << (*it).getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if(count % 3 != 1) cout << endl;
}

bool Teacher::__deleteTask(unsigned int no)
{
	if (no > m_taskList.size() || no < 1) {
		return false;
	}
	MyIterator<TeachingTask> it = m_taskList.begin();
	for (unsigned int i = 1; i < no; i++) it++;
	m_taskList.erase(*it);
	return true;
}

void Teacher::__printLine(int n)
{
	while (n--) cout << '*';
	cout << endl;
}

TeachingTask * Teacher::__getTaskAt(unsigned no)
{
	assert(no <= m_taskList.size() && no >= 1);

	MyIterator<TeachingTask> it = m_taskList.begin();
	for (unsigned i = 1; i < no; i++) it++;
	return &(*it);
}

bool Teacher::assignTask()
{
	system("cls");
	__printLine();
	__offset("��ӽ�ѧ����", 18);
	__printLine();
	string subjectName;
	cout << "������γ����ƣ�";
	cin >> subjectName;
	while (m_taskList.contains(TeachingTask(subjectName, 0, 0))) {
		cout << subjectName << "�Ѿ����ڣ�����������γ����ƣ�";
		cin >> subjectName;
	}
	cout << "�γ������ѳɹ�����Ϊ��" << subjectName << endl;


	double expTime, praTime;
	cout << "������ʵ���ʱ��";
	cin >> expTime;
	while (cin.fail() || cin.peek() != '\n' || expTime < 0 || expTime > 200 || expTime - floor(expTime) > 0) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������������0��200��������";
		cin >> expTime;
	}
	cout << "ʵ���ʱ�ѳɹ�����Ϊ��" << expTime << endl;
	cout << "���������ۿ�ʱ��";
	cin >> praTime;
	while (cin.fail() || cin.peek() != '\n' || praTime < 0 || praTime > 200 || praTime - floor(praTime) > 0) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������������0��200��������";
		cin >> praTime;
	}
	cout << "ʵ���ʱ�ѳɹ�����Ϊ��" << praTime << endl;

	TeachingTask *tm = new TeachingTask(subjectName, expTime, praTime);

	int n;
	cout << "������༶������";
	cin >> n;

	while (cin.fail() || cin.peek() != '\n' || n < 0 || n > 10) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�������������С��10����������";
		cin >> n;
	}
	for (int i = 1; i <= n; i++) {
		string tmp;
		cout << "�������" << i << "���༶��" ;
		cin >> tmp;
		while (!tm->addClass(tmp)) {
			cout << tmp << "�Ѵ���,���������룡" << endl;
			cout << "�������" << i << "���༶��";
			cin >> tmp;
		}
	}


	if (!__assignMission(*tm)) {
		cout << "��ӿγ�ʧ�ܣ�" << endl;
		return false;
	}
	cout << "��ӿγ̳ɹ���" << endl;
	cout << "��ѧ��Ϣ���£�" << endl;
	cout << *tm << endl;
	system("pause");
	return true;
}

bool Teacher::deleteMission()
{
	system("cls");
	__printLine();
	__offset("ɾ����ѧ����", 18);
	__printLine();

	if (m_taskList.size() == 0) {
		cout << "û�н�ѧ����" << endl;
		system("pause");
		return false;
	}


	__listTask();
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
	if (!__deleteTask(no)) {
		cout << "����ı������Ӧ�Ľ�ѧ���񲻴��ڣ�" << endl;
		system("pause");
		return false;
	}
	cout << "ɾ���ɹ���" << endl;
	cout << "ʣ��Ľ�ѧ����Ϊ��";
	__listTask();
	return true;
}

void Teacher::__showTaskRevisionMenu(const TeachingTask & teachingMission)
{
	system("cls");
	__printLine();
	__offset("�޸Ľ�ѧ����", 18);
	__printLine();
	cout << teachingMission << endl;
	__offset("1 - �޸Ŀγ�����");
	__offset("2 - ��Ӱ༶");
	__offset("3 - ɾ���༶");
	__offset("4 - �޸�ʵ���ʱ");
	__offset("5 - �޸����ۿ�ʱ");
	__offset("0 - ����޸�");
	__printLine();
}

void Teacher::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

bool Teacher::reviseTask()
{
	system("cls");
	__printLine();
	__offset("�޸Ľ�ѧ����", 18);
	__printLine();

	if (m_taskList.size() == 0) {
		cout << "û�н�ѧ����" << endl;
		system("pause");
		return false;
	}

	__listTask();

	unsigned int no;
	cout << "������Ҫ�޸ĵĽ�ѧ������(����������0)��" << endl;
	cin >> no;
	while (cin.fail() || cin.peek() != '\n') { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ�������������֣�";
		cin >> no;
	}
	if (no == 0) return false;
	if (no > m_taskList.size() || no < 1) {
		cout << "û�ж�Ӧ��ŵĽ�ѧ����" << endl;
		system("pause");
		return false;
	}

	TeachingTask *tmp = __getTaskAt(no);

	while (true) { //��ʼ�޸�
		__showTaskRevisionMenu(*tmp);
		cout << "������Ҫ�޸ĵı�ţ�";
		string op;
		cin >> op;
		if (op == "1") {
			cout << "�������޸ĺ�Ŀγ����ƣ�";
			string newName;
			cin >> newName;
			tmp->setName(newName);
			cout << "�γ��������޸�Ϊ��" << tmp->getName() << endl;
			system("pause");

		}
		else if(op == "2"){
			cout << "������Ҫ��ӵİ༶���ƣ�";
			string newClass;
			cin >> newClass;
			if (!tmp->addClass(newClass)) cout << "�༶�Ѵ��ڣ����ڵİ༶�У�";
			else cout << "��ӳɹ������ڵİ༶�У�";
			tmp->listClass();
			system("pause");

		}
		else if (op == "3") {
			tmp->listClass();
			cout << "������Ҫɾ���İ༶���ƣ�";
			string classToDelete;
			cin >> classToDelete;
			if (!tmp->deleteClass(classToDelete)) cout << "����İ༶�����ڣ�" << endl;
			else cout << "ɾ���ɹ���" << endl;
			cout << "ʣ��İ༶���У�";
			tmp->listClass();
			system("pause");
		}
		else if (op == "4") {
			double expTime;
			cout << "�������޸ĺ��ʵ���ʱ��";
			cin >> expTime;
			while (cin.fail() || cin.peek() != '\n' || expTime < 0 || expTime > 200 || expTime - floor(expTime) > 0) { //���������
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������������0��200��������";
				cin >> expTime;

			}
			tmp->setExpTime(expTime);
			cout << "ʵ���ʱ���޸�Ϊ��" << tmp->getExpTime() << endl;
			system("pause");
		}
		else if (op == "5") {
			double praTime;
			cout << "�������޸ĺ�����ۿ�ʱ��";
			cin >> praTime;
			while (cin.fail() || cin.peek() != '\n' || praTime < 0 || praTime > 200 || praTime - floor(praTime) > 0) { //���������
				cin.clear();
				while (cin.get() != '\n');
				cout << "�������������0��200��������";
				cin >> praTime;
			}
			tmp->setPraTime(praTime);
			cout << "ʵ���ʱ���޸�Ϊ��" << tmp->getPraTime() << endl;
			system("pause");

		}
		else if (op == "0") {
			break;
		}
		else {
			cout << "ָ�������������������!" << endl;
		}
	}
	
	system("cls");
	cout << "�޸ĳɹ���" << endl;
	cout << "�޸ĺ����ϢΪ��" << endl;
	cout << *tmp << endl;
	system("pause");
	return true;
}

void Teacher::__displayTask()
{
	cout << "           ";
	cout << m_name << m_post << "һ����" << m_taskList.size() << "����ѧ����" << endl;

	MyIterator<TeachingTask> it;
	for (it = m_taskList.begin(); it != m_taskList.end(); it++) {
		cout << *it;
	}
	cout << endl;
}


void Teacher::showTeacherRevisionMenu()
{
	system("cls");
	__printLine();
	__offset("��ʦ��Ϣ�޸Ĳ˵�");
	cout << endl;
	cout << *this << endl;
	cout << "������Ҫ�޸ĵ����ݱ�ţ�" << endl;
	__offset("1 - ID");
	__offset("2 - ����");
	__offset("3 - �Ա�");
	__offset("4 - ְ��");
	__offset("0 - ����޸�");
	__printLine();

}

int Teacher::__waitForRequest(int max)
{
	int ret, count = 1;
	cout << "������0��" << max << "��ָ���ţ�";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ����������0��" << max << "��������";
		cin >> ret;
		count++;
		if (count == 5) return -1;
	}
	return ret;
}

void Teacher::displayTask()
{
	system("cls");
	__printLine();
	__offset("��ϸ��ѧ�����嵥");
	__printLine();
	__displayTask();
	system("pause");
}

void Teacher::showDetailInfo()
{
	system("cls");
	__printLine();
	__offset(this->getName() + "����ϸ��Ϣ");
	__printLine();
	cout << *this << endl;
	cout << "--------------------------------------------------" << endl;
	__displayTask();
	system("pause");
}

bool Teacher::operator<(const Teacher & other) const
{
	if (getTotalWorkload() > other.getTotalWorkload()) return true;
	return false;
}

bool Teacher::operator==(const Teacher & other) const
{
	return getId() == other.getId();
}

ostream & operator<<(ostream & out, const Teacher & teacher)
{
	out << "[" << "ID:" << teacher.getId() << ",����:" << teacher.getName()
		<< ",�Ա�:" << teacher.getGender()
		<< ",ְ��:" << teacher.getPost() << ",�ܹ�����:" 
		<< teacher.getTotalWorkload() << "]";
	return out;
}
