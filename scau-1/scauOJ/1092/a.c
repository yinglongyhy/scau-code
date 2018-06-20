#include <stdio.h>
#include <string.h>
int f(char *s)
{
	return (strlen(s));
}
int main()
{
	char s[80];
	int i;
	scanf("%s", s);
	i = f(s);
	printf("%d", i);
	return 0;
}

struct student{
	char name[10];
	char sex;
	int num;
	float score;
};
