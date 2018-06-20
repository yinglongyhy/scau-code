#include <stdio.h>
int main()
{
	char cha[80], ch;
	int i;
	for(i = 0; i < 80; i++)
	{
		ch = getchar();
		if('\n' == ch)
			break;
		if(ch >= 'A' && ch <= 'Z')
			ch += 32;
		cha[i] = ch;

	}
	cha[i] = '\0';
	printf("%s", cha);
	return 0;
}
