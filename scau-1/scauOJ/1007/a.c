#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	int i = 0;
	scanf("%d", &a);
	while(i * i <= a)
	{
		if(i * i == a)
		{
			printf("Y");
			exit(0);
		}
		i++;
	}
	printf("N");
	return 0;
}
