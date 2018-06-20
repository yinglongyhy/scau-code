#include <iostream>
#include <string>
#include "Teacher.h"
using namespace std;
int main()
{
	Teacher t("fisjf", 28);
	cout << t.getName() << endl;
	cout << t.getScore() << endl;

	return 0;
}

