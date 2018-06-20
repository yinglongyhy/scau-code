#include <iostream>
#include <stdio.h>
#include <fstream>
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
	Yhy *p = new Yhy();
	cin >> p->a;
	cout << p->a;

	cout << endl;

	Yhy *q = new Yhy();
	cin >> q->a;
	cout << q->a;

	Hong *t = new Hong;
	int i;
	for(i = 0; i < p->a.length(); i++) t->a[i] = p->a[i];
	t->a[i] = 0;
	ofstream out("save.txt", ios::out | ios:: binary);
	out.write((char *)t, sizeof(Hong));

	for(i = 0; i < q->a.length(); i++) t->a[i] = q->a[i];
	t->a[i] = 0;
	out.write((char *)t, sizeof(Hong));

	out.close();
	delete p;
	delete q;
	delete t;
	return 0;
}
