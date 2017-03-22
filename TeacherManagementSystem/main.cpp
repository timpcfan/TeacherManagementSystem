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
	
	restore(tms, "tms.dat");//�ָ�����

	tms.start(); //����ϵͳ

	save(tms, "tms.dat");//��������

	system("pause");
	return 0;
}

