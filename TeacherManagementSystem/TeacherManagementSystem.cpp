#include "TeacherManagementSystem.h"
#include <iostream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
}

void TeacherManagementSystem::start()
{
	while (true) {
		bool back = false;
		__showMainMenu();
		switch (__waitForRequest(1)) {
		case 1: {//�����ʦ����˵�
			while (true) {
				bool back = false;
				__showTeacherMenu();
				switch (__waitForRequest(5)) {
				case 1:{//¼���½�ʦ
					addTeacher();
					break;
				}
				case 2: {//��ѯ������ʦ
					if (m_teacherMap.size() == 0) {
						cout << "������ӽ�ʦ��" << endl;
						system("pause");
						break;
					}
					__listTeacher();
					cout << "�������ʦID��" ;
					string id;
					cin >> id;
					while (!__isExisted(id)) {
						cout << "IDΪ" << id << "�Ľ�ʦ�����ڣ�" << endl;
						__listTeacher();
						cout << "���������룺";
						cin >> id;
					}

					Teacher *p = &(m_teacherMap[id]);

					while (true) {
						bool back = false;
						__showTeacherManagementMenu(*p);
						switch (__waitForRequest(4)) {
						case 1: {//��ѧ�������
							while (true) {
								bool back = false;
								__showTeachingMissionMenu();
								switch (__waitForRequest(4)) {
								case 1: {//�鿴�ý�ʦ���н�ѧ����
									p->displayMission();
									break;
								}
								case 2: {//��ӽ�ѧ����
									p->assignMission();
									break;
								}
								case 3: {//�޸Ľ�ѧ����
									p->reviseMission();
									break;
								}
								case 4: {//ɾ����ѧ����
									p->deleteMission();
									break;
								}
								case 0: {
									back = true;
									break;
								}
								}//switch
								if (back) break;
							}
							break;
						}
						case 2: {//�鿴�ý�ʦ��ϸ��Ϣ

							break;
						}
						case 3: {//�޸ĸý�ʦ��Ϣ

							break;
						}
						case 4: {//ɾ���ý�ʦ

							break;
						}
						case 0: {
							back = true;
							break;
						}
						}//switch
							if (back) break;
					}
					break;
				}
				case 3: {//ɾ����ʦ
					deleteTeacher();
					break;
				}
				case 4: {//��ʦ������ͳ��

					break;
				}
				case 5: {//���ȫ���ʦ��Ϣ

					break;
				}
				case 0: {
					back = true;
					break;
				}
				}//switch
				if (back) break;
			}
			break;
		}

		case 0: {
			back = true;
			break;
		}

		}//switch
		if (back) break;
	}
}

bool TeacherManagementSystem::addTeacher()
{
	system("cls");
	__printLine();
	cout << "��ӽ�ʦ" << endl;
	__printLine();

	string id;
	cout << "�������ʦID��";
	cin >> id;
	while (__isExisted(id)) {
		cout << "IDΪ" << id << "�Ľ�ʦ�Ѵ��ڣ�" << endl;
		cout << "���������룺";
	}
	cout << "ID�ѳɹ�����Ϊ��" << id << endl;

	string name;
	cout << "�������ʦ������";
	cin >> name;
	cout << "�����ѳɹ�����Ϊ��" << name << endl;

	string gender;
	cout << "�������ʦ�Ա���/Ů����";
	cin >> gender;
	while (gender != "��" && gender != "Ů") {
		cout << "�������" << endl;
		cout << "�����롰�С���Ů����";
		cin >> gender;
	}
	cout << "�Ա��ѳɹ�����Ϊ��" << gender << endl;

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
	if (post == "1") post = "����";
	else if (post == "2") post = "��ʦ";
	else if (post == "3") post = "������";
	else if (post == "4") post = "����";
	else {
		cout << "δ֪����" << endl;
		return false;
	}
	cout << "ְ���ѳɹ�����Ϊ��" << post << endl;

	
	if (!__addTeacher(Teacher(id, name, gender, post))) {
		cout << "��ӽ�ʦʧ�ܣ�" << endl;
		return false;
	}

	cout << "��ʦ����ӣ�" << endl;
	cout << "��ʦ����ϢΪ��" << endl;
	cout << m_teacherMap[id] << endl;
	system("pause");
	return true;
}

bool TeacherManagementSystem::deleteTeacher()
{
	system("cls");
	__printLine();
	cout << "ɾ����ʦ" << endl;
	__printLine();

	__listTeacher();
	cout << "������Ҫɾ���Ľ�ʦid��";
	string id;
	cin >> id;
	if (!__deleteTeacher(id)) {
		cout << "��ID�Ľ�ʦ�����ڣ�" << endl;
		return false;
	}
	cout << "IDΪ" << id << "�Ľ�ʦɾ���ɹ���" << endl;
	return true;
}

void TeacherManagementSystem::__showMainMenu()
{
	system("cls");
	__printLine();
	__offset("��ӭ������ʦ����ϵͳ");
	cout << endl;
	__offset("���˵�",23);
	cout << endl;
	__offset("1 - �����ʦ����ϵͳ");
	__offset("0 - �˳�ϵͳ");

	__printLine();
	
}

void TeacherManagementSystem::__showTeacherMenu()
{
	system("cls");
	__printLine();
	__offset("��ʦ����˵�",19);
	cout << endl;
	__offset("1 - ¼���½�ʦ");
	__offset("2 - ��ѯ������ʦ");
	__offset("3 - ɾ����ʦ");
	__offset("4 - ��ʦ������ͳ��");
	__offset("5 - ���ȫ���ʦ��Ϣ");
	__offset("0 - ������һ���˵�");
	__printLine();

}

void TeacherManagementSystem::__showTeacherManagementMenu(const Teacher & teacher)
{
	system("cls");
	__printLine();
	__offset("��ʦ�༭�˵�", 19);
	cout << endl;
	cout << "��ǰ��ʦΪ��" << endl;
	cout << teacher << endl;
	__offset("1 - ��ѧ�������");
	__offset("2 - �鿴�ý�ʦ��ϸ��Ϣ");
	__offset("3 - �޸ĸý�ʦ��Ϣ");
	__offset("4 - ɾ���ý�ʦ");
	__offset("0 - ������һ���˵�");
	__printLine();
}

void TeacherManagementSystem::__showTeachingMissionMenu()
{
	system("cls");
	__printLine();
	__offset("��ѧ�������˵�", 18);
	cout << endl;
	__offset("1 - �鿴�ý�ʦ���еĽ�ѧ����");
	__offset("2 - ��ӽ�ѧ����");
	__offset("3 - �޸Ľ�ѧ����");
	__offset("4 - ɾ����ѧ����");
	__offset("0 - ������һ���˵�");
	__printLine();
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

void TeacherManagementSystem::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

int TeacherManagementSystem::__waitForRequest(int max)
{
	int ret;
	cout << "������0��" << max << "��ָ���ţ�";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ����������0��"<< max << "��������";
		cin >> ret;
	}
	return ret;
}

void TeacherManagementSystem::__listTeacher() const
{
	cout << "���н�ʦ���£�" << endl;
	if (m_teacherMap.size() == 0) {
		cout << "��" << endl;
		return;
	}

	unsigned int count = 1;
	map<string,Teacher>::const_iterator it = m_teacherMap.begin();
	for (; it != m_teacherMap.end(); it++, count++) {
		cout << it->first << ":" << it->second.getName() << "\t";
		if (count % 4 == 0) cout << endl;
	}
	if (count % 4 != 1) cout << endl;

}
