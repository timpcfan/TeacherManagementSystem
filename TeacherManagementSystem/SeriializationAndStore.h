#pragma once

#include <fstream>
#include "TeacherManagementSystem.h"
#include <boost\serialization\string.hpp>
#include <boost\serialization\access.hpp>
#include <boost\archive\text_iarchive.hpp>
#include <boost\archive\text_oarchive.hpp>




void save(const TeacherManagementSystem &s, const char * filename) {

	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << s; //��TMS����s���л��󴢴��oa��д���ļ�
	std::cout << "�����ѱ�����" << filename << "�ļ���" << endl;
}

void restore(TeacherManagementSystem &s, const char * filename){

	std::ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "��ӭ�״�ʹ�ñ�ϵͳ��" << endl;
		system("pause");
		return;
	}
	else {
		cout << "�����ѳɹ����룡" << endl;
		system("pause");
	}
	boost::archive::text_iarchive ia(ifs);
	ia >> s; //���ļ��ж�ȡ����TMS�������л���ָ���s
}