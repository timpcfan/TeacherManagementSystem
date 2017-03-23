#include <cstdlib>
#include "TeacherManagementSystem.h"
#include "Teacher.h"
#include "TeachingMission.h"
#include "MyDisorderedList.h"
#include "MyOrderedList.h"
#include <ctime>

using namespace std;


int main() {
	
	//TeacherManagementSystem tms;
	//tms.start();


	int arr[10] = { 100,8,7,6,5,4,3,3,120,1 };

	MyOrderedList<int> l(arr,10);
	MyDisorderedList<int> dl(arr, 10);

	for (unsigned i = 1; i <= l.size(); i++) {
		cout << l.get(i) << " ";
	}	
	cout << endl;
	for (unsigned i = 1; i <= dl.size(); i++) {
		cout << dl.get(i) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}