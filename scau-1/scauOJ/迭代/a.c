#include <stdio.h>
#include <math.h>
int main()
{
	float a, m, n;
	scanf("%f", &a);
	n = 1;
	do
	{
		m = n;
		n = (n + a / n) / 2;
	}while(fabs(m - n) >= (1E-5));
	printf("%.4f\n", n);
	return 0;
}
