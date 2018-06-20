#include <stdio.h>
#include <string.h>
int main()
{
	char s[100] = "";
	char a[30];
	char b[30] = "", c[30] = "";
	char ch;
	int i;
	i = 0;
	while('\n' != (ch = getchar()))
		a[i++] = ch;
	a[i] = '\0';
	i = 0;
	while('\n' != (ch = getchar()))
		b[i++] = ch;
	i = 0;
	while('\n' != (ch = getchar()))
		c[i++] = ch;
	strcat(s, a);
	strcat(s, b);
	strcat(s, c);
	printf("%s\n", s);
	return 0;
}
