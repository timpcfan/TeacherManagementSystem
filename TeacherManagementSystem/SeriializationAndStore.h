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
	oa << s; //将TMS对象s序列化后储存进oa并写入文件
}

void restore(TeacherManagementSystem &s, const char * filename){

	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);
	ia >> s; //从文件中读取并将TMS对象反序列化后恢复到s
}