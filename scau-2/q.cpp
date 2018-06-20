#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct St{
	string a;
};

int main()
{
	struct St *p = new struct St;
	struct St *q = new struct St;
	p->a = "safjsafj";
	q->a = "safjsafj";
	ofstream out("save.in", ios::out);
	out << p->a << endl;
	out << q->a;
	out.close();
	return 0;
}
