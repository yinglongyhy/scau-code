#include <stdio.h>
int main()
{
	int temp, nums[20];
	int i, j, count = 1;
	for(i = 0; i < 20; i++)
	{
		scanf("%d", &temp);
		if(0 == i)
			nums[i] = temp;
		for(j = 0; j < count; j++)
		{
			if(temp == nums[j])
				break;
			else if(j == count - 1)
			{
				nums[++j] = temp;
				count++;
			}
		}
	}
	printf("%d\n", count);
	for(i = 0; i < count; i++)
		printf("%d  ", nums[i]);
	return 0;
}
