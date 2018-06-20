#include <stdio.h>
int main()
{
	double i = 2, j = 1;//分子 分母
	double temp, sum = 0;
	double count;
	int n;

	scanf("%d", &n);
	for(count = 0; count < n; count++)
	{
		sum += i / j;
		temp = i;
		i = i + j;
		j = temp;
	}
	printf("%.4lf", sum);

	return 0;
}
