//使用一个函数求整形数组的最大或最小值
#include <iostream>

using namespace std;

int find(int arr[], int len, bool is_max)
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
	bool is_max = false;
	cin >> is_max;
	cout << find(arr, 4, is_max) << endl;
	return 0;
}
