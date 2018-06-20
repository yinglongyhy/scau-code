#include <stdio.h>
int main()
{
	int nums[200];
	nums[0] = 2;
	int i = 3, j = 0, max = 0;
	for(i = 3; i <= 200; i++)
	{
		for(j = 0; j <= max; j++)
		{
			if(i % nums[j] == 0) 
				break;
			else if(j == max)
			{	
				max++;
				nums[max] = i;
				break;
			}
		}
	}
	for(j = 0; j <= max; j++)
		printf("%d\n", nums[j]);
	return 0;
}
