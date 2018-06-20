
//使用一个函数求整形数组的最大或最小值
#include <stdio.h>


int find(int *arr, int len, int is_max)
{
	int temp = arr[0];
	for(int i = 1; i < len; i++)	
	{
		if(is_max)	
		{
			temp < arr[i] ? temp = arr[i] : temp;	
		}
		else
		{	
			temp > arr[i] ? temp = arr[i] : temp;	
		}
	}

	return temp;
}

int main()
{
	int arr[4] = {1, 2, 3, 4};
	int is_max = 0;
	scanf("%d", &is_max);
	printf("%d\n", find(arr, 4, is_max));
	return 0;
}
