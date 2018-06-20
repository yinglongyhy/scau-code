#include <stdio.h>
#include <math.h>
void binary(int n)
{
	int i = 0;
	while(n >= pow(2, i))
		i++;
	i--;
	for(i; i >= 0; i--)
	{
		printf("%d", n / (int)pow(2, i));
		n %= (int)pow(2, i);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	binary(n);
	return 0;
}
