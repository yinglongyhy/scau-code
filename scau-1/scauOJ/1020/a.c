#include <stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	if(x > 0)
		printf("positive\n");
	else
		printf("negative\n");
	if(0 == x % 2)
		printf("even\n");
	else
		printf("odd\n");
	return 0;
}
