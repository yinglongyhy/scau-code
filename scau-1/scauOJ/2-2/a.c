#include <stdio.h>
int main()
{
	float a;
	int b, c;
	char d, e;
	a = 3.5;
	b = a;
	c = 330;
	d = c;
	e = '\141';
	printf("%f,%d,%d,%c,%c", a, b, c, d, e);

	return 0;
}
