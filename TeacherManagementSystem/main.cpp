#include <cstdlib>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"
#include "MyDisorderedList.h"
#include "MyOrderedList.h"
using namespace std;


int main() {
	
	//TeacherManagementSystem tms;
	//tms.start();


	MyDisorderedList<int> L;

	for (int i = 1; i < 1000; i++) {
		L.insert(L.size()+1,i);
	}


	for (unsigned i = 1;!L.empty(); i++) L.erase(i);
	for (unsigned i = 1; i < L.size(); i++) cout << L.get(i) << endl;



	system("pause");
	return 0;
}