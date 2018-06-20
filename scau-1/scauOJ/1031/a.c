#include <stdio.h>
int main()
{
	int count = 0;
	char cha;
	int i = 0;
	cha = getchar();
	while('\n' != cha)
	{
		if(32 == cha)
		{
			count++;
			while(32 == (cha = getchar()));
			continue;
		}
		cha = getchar();
	}
	count++;
	printf("%d", count);
	return 0;
}
