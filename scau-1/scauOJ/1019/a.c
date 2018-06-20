#include <stdio.h>
int main()
{
	int nums[5];
	int i;
	scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
	for(i = 0; i < 5; i++)
	{
		if(0 == nums[i] % 27)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
