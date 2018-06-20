#include <stdio.h>
int main()
{
	double x, y;
	scanf("%lf,%lf", &x, &y);
	double distance;
	distance = x*x+y*y;
	if(distance <= 1)
		printf("Y");
	else
		printf("N");
	return 0;
}
