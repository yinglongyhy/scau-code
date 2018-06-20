#include <stdio.h>
int main()
{
	int i;
	int j = 0;
	char p[25];
	char q[25];
	fgets(p, 26, stdin);
	for(i = 0; i < 25; i++)
	{
		if(p[i] != ' ' && (p[i] < '0' || p[i] > '9'))
		{
			q[j++] = p[i];
		}
	}
	q[j + 1] = '\0';
	printf("%s", q);
	return 0;
}
