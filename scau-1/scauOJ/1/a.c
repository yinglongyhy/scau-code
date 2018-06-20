#include <stdio.h>
int max(int a, int b)
{
	int temp;
	if(a >= b)
		temp = a;
	else
		temp = b;
	return temp;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", max(a, b));
	return 0;
}
