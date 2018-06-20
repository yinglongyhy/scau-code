#include <stdio.h>
int main()
{
	int a[4] = {1, 2, 3, 4};
	int *p = a;
	int i;
	for(i = 0; i < 4; i++)
		printf("%d\n", p[i]);
	return 0;
}
