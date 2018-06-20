#include <stdio.h>
int main()
{
	double m, sum = 0, money = 0.01;
	int day = 0;
	scanf("%lf", &m);
	do
	{
		sum += money;
		money *= 2;
		day++;
	}while(m * day >= sum);
	printf("%d", day);
	return 0;
}
