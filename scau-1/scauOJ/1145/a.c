#include <stdio.h>
#include <string.h>
int main()
{
	char a[80], b[80];
	int i, l, t;
	scanf("%s", a);
	l = strlen(a);
	strcpy(b, a);
	for(i = 0; i < l / 2; i++)
	{
		t = b[i];
		b[i] = b[l - 1 - i];
	}
	if(strcmp(a, b) == 0)
		printf("Y");
	else
		printf("N");

	return 0;
}
