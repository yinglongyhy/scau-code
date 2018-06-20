#include <stdio.h>
long fanc(int n)
{
	if(n == 1 || n == 0)
		return 1;
	n = n * fanc(n - 1);
	return n;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%ld\n", fanc(n));
	return 0;
}
