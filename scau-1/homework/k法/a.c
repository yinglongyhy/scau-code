#include <stdio.h>
#include <math.h>
int maxlen(int num1, int num2)
{
	int i = 1, j = 1;
	while(num1 /= 10)	i++;
	while(num2 /= 10)	j++;
	if(i < j)			i = j;
	while(log2(i) != (int)log2(i))		i++;
	return i;
}

int gethigh(int num, int len)
{
	return (num / (int)pow(10, len));
}

int getlow(int num, int len)
{
	return (num % (int)pow(10, len));
}

int karatsuba(int num1, int num2, int len)
{
	if(num1 < 10|| num2 < 10)
		return num1 * num2;
	len /= 2;
	int high1, high2, low1, low2;
	high1 = gethigh(num1, len);
	high2 = gethigh(num2, len);
	low1 = getlow(num1, len);
	low2 = getlow(num2, len);
	return (high1*high2 * (int)pow(10, 2*len) + (high1 * high2 + low1 * low2 - (low1 - high1) * (low2 - high2)) * (int)pow(10, len) + low1*low2);

}

int main()
{
	int num1, num2;
	int len;
	scanf("%d%d", &num1, &num2);
	len = maxlen(num1, num2);
	printf("%d\n", karatsuba(num1, num2, len));
	return 0;
}
