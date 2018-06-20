#include <stdio.h>
int i, j;
void input(int (*p)[3])
{
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &p[i][j]);
		}
	}

}
int main()
{
	int nums[3][3];
	input(nums);
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", nums[i][j]);
		}
		printf("\n");
	}
	return 0;
}
