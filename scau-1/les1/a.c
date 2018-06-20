#include <stdio.h>
int main()
{
	int a, b;
	double c;
	printf("a =");
	scanf("%d", &a);
	printf("b =");
	scanf("%d", &b);
	c = (a + b) / 1.00;
	printf("结果是：%.2lf", c);

	return 0;
}
