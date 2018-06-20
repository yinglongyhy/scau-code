#include <stdio.h>
int main()
{
	int nums[10];
	int temp = 10000;
	int i;
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
		if(temp > nums[i])
			temp = nums[i];
	}
	printf("%d", temp);
	return 0;
}
