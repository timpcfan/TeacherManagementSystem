#include "TeacherManagementSystem.h"
#include <iostream>
#include <fstream>

using namespace std;


TeacherManagementSystem::TeacherManagementSystem()
{
	login();
	loadData();
}

TeacherManagementSystem::~TeacherManagementSystem()
{
	saveData();
}

void TeacherManagementSystem::start()
{

	while (true) {
		bool back = false;
		__showMainMenu();
		switch (__waitForRequest(2)) {
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
					if (m_teacherList.size() == 0) {
						cout << "������ӽ�ʦ��" << endl;
						system("pause");
						break;
					}
					system("cls");
					__printLine();
					__offset("ѡ���ʦ", 21);
					__printLine();
					__listTeacher();
					cout << "�������ʦID������������0����" ;
					string id;
					cin >> id;

					Teacher *p;

					while (!(p=__getTeacherById(id)) && id != "0") {
						system("cls");
						__printLine();
						__offset("ѡ���ʦ", 21);
						__printLine();
						cout << "IDΪ" << id << "�Ľ�ʦ�����ڣ�" << endl;
						__listTeacher();
						cout << "���������루����������0����";
						cin >> id;
					}
					if (id == "0") break;


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
									p->displayTask();
									break;
								}
								case 2: {//��ӽ�ѧ����
									p->assignTask();
									break;
								}
								case 3: {//�޸Ľ�ѧ����
									p->reviseTask();
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
							p->showDetailInfo();
							break;
						}
						case 3: {//�޸ĸý�ʦ��Ϣ
							reviseTeacher(p);
							break;
						}
						case 4: {//ɾ���ý�ʦ
							cout << "ȷ��Ҫɾ��" << p->getName()
								<< p->getPost() << "������(Y/y)ȷ��ɾ����";
							string ascertain;
							cin >> ascertain;
							if (ascertain != "y" && ascertain != "Y") {
								cout << "ȡ��ɾ������" << endl;
								break;
							}

							string id;
							if (__deleteTeacher(p->getId())) {
								cout << "ɾ���ɹ���" << endl;
								system("pause");
								back = true;
							}
							else {
								cout << "ɾ��ʧ�ܣ�" << endl;
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
					break;
				}
				case 3: {//ɾ����ʦ
					deleteTeacher();
					break;
				}
				case 4: {//��ʦ������ͳ��
					displayWorkingStat();
					break;
				}
				case 5: {//���ȫ���ʦ��Ϣ
					sortAndShowTeacher();
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
		case 2: {
			changePassword();
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
	__offset("��ӽ�ʦ",21);
	__printLine();

	string id;
	cout << "�������ʦID��";
	cin >> id;
	while (__isExisted(id)) {
		cout << "IDΪ" << id << "�Ľ�ʦ�Ѵ��ڣ�" << endl;
		cout << "���������룺";
		cin >> id;
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

	Teacher *t = new Teacher(id, name, gender, post); 
	if (!__addTeacher(*t)) {
		cout << "��ӽ�ʦʧ�ܣ�" << endl;
		return false;
	}

	cout << "��ʦ����ӣ�" << endl;
	cout << "��ʦ����ϢΪ��" << endl;
	cout << *__getTeacherById(id) << endl;
	system("pause");
	return true;
}

void TeacherManagementSystem::reviseTeacher(Teacher *teacher)
{
	while (true) {
		bool back = false;
		teacher->showTeacherRevisionMenu();
		switch (__waitForRequest(4)) {
		case 1: {//ID
			string id;
			cout << "��������ID��";
			cin >> id;
			while (__isExisted(id)) {
				cout << "�����ID�Ѵ��ڣ�����������" << endl;
				cout << "��������ID��";
				cin >> id;
			}
			teacher->setId(id);
			cout << "�ѳɹ��޸�IDΪ��" << id << endl;
			system("pause");
			break;
		}
		case 2: {//����
			string name;
			cout << "��������������";
			cin >> name;
			teacher->setName(name);
			cout << "�ѳɹ��޸�����Ϊ��" << name << endl;
			system("pause");
			break;
		}
		case 3: {//�Ա�
			string gender;
			cout << "���������Ա���/Ů����";
			cin >> gender;
			while (gender != "��" && gender != "Ů") {
				cout << "�����������������" << endl;
				cout << "���������Ա���/Ů����";
				cin >> gender;
			}
			teacher->setGender(gender);
			cout << "�ѳɹ��޸��Ա�Ϊ��" << gender << endl;
			system("pause");
			break;
		}
		case 4: {//ְ��
			string post;
			cout << "��������ְ�Ƶı��" << endl;
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
				break;
			}
			teacher->setPost(post);
			cout << "�ѳɹ��޸�ְ��Ϊ��" << post << endl;
			break;
		}
		case 0: {
			back = true;
			break;
		}
		}//switch
		if (back) break;
	}
	system("cls");
	cout << "������޸�,���ڸý�ʦ��Ϣ���£�" << endl;
	cout << *teacher << endl;
	system("pause");
}

void TeacherManagementSystem::loadData()
{
	ifstream ifs("tms.dat");
	if (!ifs.good()) {
		ifs.close();
		return;
	}

	
	while (ifs.good()) {
		int nTeacher = 0;
		ifs >> nTeacher;
		while (nTeacher--) {
			string id, name, gender, post;
			ifs >> id >> name >> gender >> post;
			Teacher *t = new Teacher(id, name, gender, post);
			__addTeacher(*t);
			
			int nTT;
			ifs >> nTT;//��ѧ��������
			while (nTT--) {
				double exp = 0, pra = 0;
				string subName;
				int nClass; //�༶����
				ifs >> exp >> pra >> subName >> nClass;
				TeachingTask *tt = new TeachingTask(subName, exp, pra);
				while (nClass--) {
					string className;
					ifs >> className;
					tt->addClass(className);
				}
				__getTeacherById(id)->__assignTask(*tt);
			}
		}
	}


	cout << "���ݼ��سɹ���" << endl;
	cout << "�ѳɹ�����" << m_teacherList.size() << "λ��ʦ�����ݣ�" << endl;
	system("pause");
	ifs.close();
}

void TeacherManagementSystem::saveData()
{
	ofstream ofs("tms.dat");

	ofs << m_teacherList.size() << endl;
	for (MyIterator<Teacher> it = m_teacherList.begin(); it != m_teacherList.end(); it++) {
		ofs << it->getId() << " " << it->getName() << " "
			<< it->getGender() << " " << it->getPost() << " ";
		ofs << it->__toString() ;
		ofs << endl;
	}
	ofs.close();

	cout << "�ѳɹ���" << m_teacherList.size() << "������д��tms.dat�ļ��У�" << endl;
	cout << "�벻Ҫ�ֶ��޸�tms.dat�ļ���������ɲ���Ҫ��������ʧ" << endl;
	system("pause");
}

void TeacherManagementSystem::login()
{
	ifstream ifs("key.dat");

	if (!ifs.good()) {
		ifs.close();
		cout << "��ӭ��һ��ʹ�ñ�ϵͳ��" << endl;
		cout << "����������(������Ӣ�ĺ�����)��";
		ofstream ofs("key.dat");
		string ps;
		cin >> ps;
		for (unsigned i = 0; i < ps.length(); i++) {
			ps[i] += 100; //�򵥵ļ���
		}
		ofs << ps;
		ofs.close();
		return;
	}

	string ps;
	ifs >> ps;
	ifs.close();

	for (unsigned i = 0; i < ps.length(); i++) {
		ps[i] -= 100;
	}
	cout << "���������룺";
	string password;
	cin >> password;
	int n = 5;
	while (password != ps && n--) {
		cout << "������󣡻�ʣ" << n + 1 << "�λ��ᣡ" << endl;
		cout << "���ٴ��������룺";
		cin >> password;
	}
	if (password != ps) {
		cout << "�������������࣬�����´򿪳���!" << endl;
		system("pause");
		exit(0);
	}
	cout << "��ӭ������" << endl;
}

void TeacherManagementSystem::changePassword()
{
	
		cout << "�������µ�����(������Ӣ�ĺ�����)��";
		ofstream ofs("key.dat");
		string ps;
		cin >> ps;
		for (unsigned i = 0; i < ps.length(); i++) {
			ps[i] += 100; //�򵥵ļ���
		}
		ofs << ps;
		cout << "�����޸ĳɹ���" << endl;
		system("pause");
		ofs.close();
}

bool TeacherManagementSystem::deleteTeacher()
{
	system("cls");
	__printLine();
	__offset("ɾ����ʦ", 21);
	__printLine();

	if (m_teacherList.size() == 0) {
		cout << "������ӽ�ʦ��" << endl;
		system("pause");
		return false;
	}

	__listTeacher();
	cout << "������Ҫɾ���Ľ�ʦID��";
	string id;
	cin >> id;
	if (!__deleteTeacher(id)) {
		cout << "��ID�Ľ�ʦ�����ڣ�" << endl;
		system("pause");
		return false;
	}
	cout << "IDΪ" << id << "�Ľ�ʦɾ���ɹ���" << endl;
	system("pause");
	return true;
}

void TeacherManagementSystem::sortAndShowTeacher()
{
	system("cls");
	__printLine();
	__offset("ȫ���ʦ��Ϣ", 18);
	__printLine();

	if (m_teacherList.size() == 0) {
		cout << "�޽�ʦ��Ϣ" << endl;
		system("pause");
		return;
	}

	MyOrderedList<Teacher> teacherInOrder;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		teacherInOrder.insert(*it);
	}
	MyIterator<Teacher> it2 = teacherInOrder.begin();
	for (; it2 != teacherInOrder.end(); it2++) {
		cout << *it2 << endl;
	}
	system("pause");
}



void TeacherManagementSystem::displayWorkingStat()
{
	system("cls");
	__printLine();
	__offset("��ʦ������ͳ��");
	__printLine();
	cout << "��ʦ������Ϊ��" << m_teacherList.size() << endl;
	cout << "ȫ���ʦ�ܹ�����Ϊ��" << __getAllWorkload() << endl;
	double ave1 = 0;
	if (m_teacherList.size() != 0) ave1 = __getAllWorkload() / m_teacherList.size();
	cout << "ȫ���ʦƽ��������Ϊ��" << ave1 << endl;

	cout << "--------------------------------" << endl;
	pair<double, int> female, male;
	female = __getFemaleWorkloadAndNum();
	male = __getMaleWorkloadAndNum();
	cout << "Ů��ʦ������Ϊ��" << female.second << endl;
	cout << "Ů��ʦ�ܹ�����Ϊ��" << female.first << endl;
	double ave2 = 0;
	if (female.second != 0) ave2 = female.first / female.second;
	cout << "Ů��ʦƽ��������Ϊ��" << ave2 << endl;	
	cout << "--------------------------------" << endl;

	cout << "�н�ʦ������Ϊ��" << male.second << endl;
	cout << "�н�ʦ�ܹ�����Ϊ��" << male.first << endl;
	double ave3 = 0;
	if (male.second != 0) ave3 = male.first / male.second;
	cout << "�н�ʦƽ��������Ϊ��" << ave3 << endl;
	system("pause");
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
	__offset("2 - �޸ĵ�¼����");
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
	
	m_teacherList.push_back(teacher);
	return true;
}

//ɾ����ʦ��������ɹ�����true����ʦid�����ڷ���false
bool TeacherManagementSystem::__deleteTeacher(string id)
{
	Teacher* tmp;
	if (!(tmp=__getTeacherById(id))) return false;
	m_teacherList.erase(*tmp);
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
	if (!__getTeacherById(id)) return false;
	return true;
}

void TeacherManagementSystem::__offset(string text, int offset)
{
	for (int i = 0; i < offset; i++) cout << ' ';
	cout << text << endl;
}

int TeacherManagementSystem::__waitForRequest(int max)
{
	int ret, count = 1;
	cout << "������0��" << max << "��ָ���ţ�";
	cin >> ret;
	while (cin.fail() || cin.peek() != '\n' || ret < 0 || ret > max) { //���������
		cin.clear();
		while (cin.get() != '\n');
		cout << "�����ʽ����������0��"<< max << "��������";
		cin >> ret;
		count++;
		if (count == 5) return -1;
	}
	return ret;
}

double TeacherManagementSystem::__getAllWorkload()
{
	double ret = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		ret += it->getTotalWorkload();
	}

	return ret;
}

pair<double,int> TeacherManagementSystem::__getMaleWorkloadAndNum()
{
	double ret = 0;
	int count = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getGender() == "��") {
			ret += it->getTotalWorkload();
			count++;
		}
	}

	return make_pair(ret, count);
}

pair<double,int> TeacherManagementSystem::__getFemaleWorkloadAndNum()
{
	double ret = 0;
	int count = 0;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getGender() == "Ů") {
			ret += it->getTotalWorkload();
			count++;
		}
	}

	return make_pair(ret, count);
}

Teacher * TeacherManagementSystem::__getTeacherById(string id)
{
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++) {
		if (it->getId() == id) {
			return &(*it);
		}
	}
	return nullptr;
}

void TeacherManagementSystem::__listTeacher() const
{
	cout << "���н�ʦ���£�" << endl;
	if (m_teacherList.size() == 0) {
		cout << "��" << endl;
		return;
	}

	unsigned int count = 1;
	MyIterator<Teacher> it = m_teacherList.begin();
	for (; it != m_teacherList.end(); it++, count++) {
		cout << it->getId() << ":" << it->getName() << "\t";
		if (count % 3 == 0) cout << endl;
	}
	if (count % 3 != 1) cout << endl;

}
