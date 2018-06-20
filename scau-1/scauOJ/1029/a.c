#include <stdio.h>
void max(int *a, int *b)
{
	int temp;
	if(*a < *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
int gongYue(int a, int b)
{
	if(a % b == 0)
		return b;
	else
		gongYue(b, a % b);
}
int main()
{
	int a, b;
	scanf("%d,%d", &a, &b);
	max(&a, &b);
	printf("%d", gongYue(a, b));
	return 0;
}
