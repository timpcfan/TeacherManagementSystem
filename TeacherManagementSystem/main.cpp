#include <iostream>
#include <string>
#include <cstdlib>
#include "Teacher.h"


using namespace std;


int main() {
	

	TeachingInfo one("chinese",16,32);
	
	cout << one.addClass("G4D2") << endl;
	cout << one.addClass("G4D3") << endl;
	cout << one.addClass("G4D2") << endl;

	system("pause");
}