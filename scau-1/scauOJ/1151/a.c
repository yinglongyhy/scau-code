#include <stdio.h>
int F(int x)
{
	if(x < 3)
		return x;
	else if(x >= 3 && x % 3 == 0)
		return (F(x / 3) * 2);
	else if(x >= 3 && x % 3 == 1)
		return (F((x - 1) / 3) + 1);
	else
		return (F((x - 2) / 3) + 2);

}

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", F(x));
	return 0;
}
