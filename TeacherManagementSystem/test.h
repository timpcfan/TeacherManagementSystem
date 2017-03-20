#pragma once
#include <boost\serialization\string.hpp>
#include <boost\serialization\access.hpp>
#include <boost\archive\text_iarchive.hpp>
#include <boost\archive\text_oarchive.hpp>


class test {

private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & _tag;
		ar & _text;
	}
	int _tag;
	std::string _text;

public:
	test(int tag, std::string text) :_tag(tag), _text(text) {}
	test() {}
	int getTag() { return _tag; }
	std::string getText() { return _text; }
};


void save(const TeacherManagementSystem &s, const char * filename) {
	// make an archive
	std::ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	oa << s;
}

void restore(TeacherManagementSystem &s, const char * filename)
{
	// open the archive
	std::ifstream ifs(filename);
	boost::archive::text_iarchive ia(ifs);

	// restore the schedule from the archive
	ia >> s;
}