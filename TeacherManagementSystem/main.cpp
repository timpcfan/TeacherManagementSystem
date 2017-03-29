#include <cstdlib>
#include "TeacherManagementSystem.h"

using namespace std;

int main() {

	TeacherManagementSystem tms;

	tms.loadData();
	tms.start();
	tms.saveData();

	system("pause");
	return 0;
}