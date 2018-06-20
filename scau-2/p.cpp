#include <iostream>
#include <fstream>
using namespace std;

struct St{
	string a;
};
int main()
{
	string a;
	ifstream in("save.in", ios::in);
	if(!in) 
	{
		cout << "翻车了" << endl;
		return 0;
	}
	in >> a;
	cout << a << endl;
	in >> a;
	cout << a << endl;
	in.close();
	return 0;
}
