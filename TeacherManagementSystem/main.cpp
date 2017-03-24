#include <cstdlib>
#include <iostream>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingTask.h"
#include "MyDisorderedList.h"
#include "MyOrderedList.h"
#include <ctime>

using namespace std;


int main() {
	
	TeacherManagementSystem tms;
	tms.start();

	//MyOrderedList<string> l;
	//l.insert("banana");
	//l.insert("bad apple");
	//l.insert("apple");

	//cout << l.getFirst() << endl;
	//cout << l.getLast() << endl;

	//for (MyIterator<string> it = l.begin(); it != l.end(); it++) {
	//	cout << *it << endl;
	//}
	//for (MyIterator<string> it = l.begin(); it != l.end(); it++) {
	//	cout << *it << endl;
	//}

	system("pause");
	return 0;
}