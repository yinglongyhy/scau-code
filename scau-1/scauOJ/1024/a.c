#include <stdio.h>
int main()
{
	int n, i = 1, sum = 1;
	scanf("%d", &n);
	for(i; i <= n; i++)
	{
		sum *= i;
	}
	printf("%d", sum);
	return 0;
}
