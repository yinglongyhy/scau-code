#include <stdio.h>
int main()
{
	int nums1[80], nums2[80];
	int nums[81];
	char ch;
	int temp = 0;
	int i = 0, j, t1, t2, n;
	while('\n' != (ch = getchar()))//输入nums1
	{	
		nums1[i] = ch - 48;
		i++;
	}
	t1 = i - 1;//最大下标
	i = 0;

	while('\n' != (ch = getchar()))//输入nums2
	{	
		nums2[i] = ch - 48;
		i++;
	}
	t2 = i - 1;//最大下标

	for(i = 0; i < 81; i++)//初始化nums
		nums[i] = 0;
	
	for(i = t1, j = t2, n = 80; i >= 0 && j >= 0; i--, j--, n--)
	{
		nums[n] = (nums1[i] + nums2[j] + temp) % 10;
		temp = (nums1[i] + nums2[j] + temp) / 10;
	}
	
	while(i >= 0)//nums1有剩余
	{
		nums[n] = (nums1[i] + temp) % 10;
		temp = (nums1[i] + temp) / 10;
		i--;
		n--;
	}

	while(j >= 0)
	{
		nums[n] = (nums2[j] + temp) % 10;
		temp = (nums2[j] + temp) / 10;
		j--;
		n--;
	}
	if(0 != temp)
		nums[n] = temp;

	i = 0;
	while(0 == nums[i])//排除0
		i++;
	
	for(; i < 81; i++)
		printf("%d", nums[i]);
	
	return 0;
}
