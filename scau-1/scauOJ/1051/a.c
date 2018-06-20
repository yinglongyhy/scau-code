#include <stdio.h>
#include <string.h>
int main()
{
	int nums[3][4];
	int i, j, n, temp, k = 0;
	int	a[3][4], b[3];
	memset(a, -1, sizeof(a));	

	for(i = 0; i < 3; i++)
		for(j = 0; j < 4; j++)
			scanf("%d", &nums[i][j]);
	for(i = 0; i < 3; i++)//弄下标
	{
		j = 0;
		temp = nums[i][j] - 1;
		for(j = 0; j < 4; j++)
		{
			if(temp == nums[i][j])
			{
				a[i][n] = j;
				b[i] = n;
			}
			if(temp < nums[i][j])
			{
				temp = nums[i][j];
				a[i][n = 0] = j;
				b[i] = n;
				n++;

			}
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(n = 0; n <= b[i]; n++)
		{
			for(j = 0; j < 3; j++)	
				if(nums[j][a[i][n]] < nums[i][a[i][n]])//多个<指定
					break;
			if(3 == j)//输出
			{
				printf("%d\n", nums[i][a[i][n]]);
				k++;
			}
		}
	}
	if(0 == k)
		printf("NO");
	return 0;
}
