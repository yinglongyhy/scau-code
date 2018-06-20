#include <stdio.h>
#include <string.h>
int main()
{
	char ch1[100] = "", ch2[100] = "";
	scanf("%s", ch1);
	scanf("%s", ch2);
	printf("%d", strstr(ch1, ch2) - ch1 + 1);
	return 0;
}
