#include <stdio.h>
#include <string.h>
int main()
{
	char ch1[100] = {'\0'}, ch2[100] = {'\0'}, ch;
	int i = 0, j, k, len1, len2;
	int temp = 0;
	int nums1[100] = {0}, nums2[100] = {0};
	int matrix[100][200] = {0};
	int result[200] = {0};
	printf("请输入第一个长整数：");
	while('\n' != (ch = getchar()))
		ch1[i++] = ch;
	i = 0;
	printf("请输入第二个长整数：");
	while('\n' != (ch = getchar()))
		ch2[i++] = ch;
	len1 = strlen(ch1);
	len2 = strlen(ch2);
	for(i = 0; i < len1; i++)
		nums1[i] = ch1[i] - 48;
	for(i = 0; i < len2; i++)
		nums2[i] = ch2[i] - 48;
	for(k = len2 - 1; k >= 0; k--)//i乘j——短乘  
	{
		temp = 0;
		for(i = len1 - 1; i >= 0; i--)
		{
			matrix[k][(i + 1) + (k + 1) - 1] = (nums1[i] * nums2[k] + temp) % 10;
			if(len2 == k + 1)
				result[(i + 1) + (k + 1) - 1] = matrix[k][(i + 1) + (k + 1) - 1];
			temp = (nums1[i] * nums2[k] + temp) / 10;
			if(0 == i)
			{
				matrix[k][(i + 1) + (k + 1) - 1 - 1] = temp;
				if(len2 == k + 1)
					result[(i + 1) + (k + 1) - 1 - 1] = matrix[k][(i + 1) + (k + 1) - 1 - 1];
			}
		}
	}

	for(k = len2 - 1; k > 0; k--)//i乘j——长加
	{
		temp = 0;
		for(i = len1; i >= 0; i--)
		{
			j = (result[i + k - 1] + temp + matrix[k - 1][i + k - 1]) % 10;
			temp = (result[i + k - 1] + temp + matrix[k - 1][i + k - 1]) / 10;
			result[i + k - 1] = j;
		}
	}
	for(i = 0; i < len1 + len2; i++)//输出结果
	{
		if(0 == result[i] && 0 == i)
			continue;
		printf("%d", result[i]);
	}
	printf("\n");
	return 0;
}
