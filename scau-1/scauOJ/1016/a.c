#include <stdio.h>
int main()
{
	char ch[5];
	int i;
	for(i = 0; i < 5; i++)
	{
		ch[i] = getchar();
	}
	for(i = 0; i < 5; i++)
	{
		if(ch[i] >= 65 && ch[i] <= 96)
			ch[i] += 32;
		printf("%c", ch[i]);
	}
	return 0;
}
