#include <iostream>
#include <string>
using namespace std;
struct aaa{
	string a;
};
int main()
{
	struct aaa *p = new struct aaa;
	p->a = "jfasjfkj";
	cout << p->a.length() << endl;
	p->a = "jj";
	cout << p->a.length() << endl;
}
