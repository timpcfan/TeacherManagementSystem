#include <iostream>
#include <string>
#include <cstdlib>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"

using namespace std;


int main() {
	
	Teacher one("t01", "����", "male", "��ʦ");

	TeachingMission a("�й��Ŵ�ʷ", 20, 60);
	TeachingMission b("�й�����ʷ", 20, 60);
	TeachingMission c("�й�δ��ʷ", 20, 60);
	TeachingMission d("ŷ�޽���ʷ", 20, 60);
	TeachingMission e("���޽���ʷ", 20, 60);
	TeachingMission f("Զ��ʷ", 20, 60);


	//one.__assignMission(a);
	//one.__assignMission(b);
	//one.__assignMission(c);
	//one.__assignMission(d);
	//one.__assignMission(e);
	//one.__assignMission(f);


	//one.deleteMission();
	//one.deleteMission();
	
	one.assignMission();
	one.assignMission();

	one.__listMission();

	one.deleteMission();

	system("pause");
}