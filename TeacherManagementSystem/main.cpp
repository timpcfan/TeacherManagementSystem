#include <iostream>
#include <string>
#include <cstdlib>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"

using namespace std;


int main() {
	
	Teacher one("t01", "老王", "male", "讲师");

	TeachingMission a("中国古代史", 20, 60);
	TeachingMission b("中国近代史", 20, 60);
	TeachingMission c("中国未来史", 20, 60);
	TeachingMission d("欧洲近代史", 20, 60);
	TeachingMission e("非洲近代史", 20, 60);
	TeachingMission f("远古史", 20, 60);


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