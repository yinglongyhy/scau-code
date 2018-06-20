#include <iostream>
#include <string.h>
#include <fstream>
#include <malloc.h>
#include <string>
using namespace std;

typedef struct yhy{
	string a;
}Yhy;

typedef struct hong{
	char a[100];
}Hong;

int main()
{
	Yhy *p = new Yhy;
	Hong *t = new Hong;
	ifstream in("save.txt", ios::in | ios::binary);
	in.read((char *)t, sizeof(Hong));
	int i;
	p->a = t->a;
	for(i = 0; i < strlen(t->a); i++) p->a[i] = t->a[i];
	cout << i << endl;
	p->a[i] = 0;
	cout << p->a << endl;;
	in.read((char *)t, sizeof(Hong));
	p->a = t->a;
	for(i = 0; i < strlen(t->a); i++) p->a[i] = t->a[i];
	p->a[i] = 0;
	cout << i << endl;
	cout << p->a;
	return 0;
}
