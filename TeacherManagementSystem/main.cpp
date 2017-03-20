#include <cstdlib>
#include <iostream>
#include <fstream>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"
#include "SeriializationAndStore.h"

#include <boost\archive\text_iarchive.hpp>
#include <boost\archive\text_oarchive.hpp>
#include <boost\serialization\string.hpp>
#include <boost\serialization\access.hpp>

using namespace std;


int main() {

	TeacherManagementSystem tms;
	
	restore(tms, "testfile");//恢复数据

	tms.start(); //启动系统

	save(tms, "testfile");//储存数据

	system("pause");
	return 0;
}

