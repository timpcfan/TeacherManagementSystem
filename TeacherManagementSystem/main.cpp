#include <iostream>
#include <string>
#include <cstdlib>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"

using namespace std;


int main() {
	
	Teacher one("t01", "����", "male", "��ʦ");

	one.assignMission();

	system("pause");
}