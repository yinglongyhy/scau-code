/*
8639 折半插入排序
时间限制:1000MS  内存限制:1000K
提交次数:1738 通过次数:1371

题型: 编程题   语言: G++;GCC
Description
用函数实现折半插入排序，并输出每趟排序的结果.
*/

#include <stdio.h>
#include <malloc.h>
int main()
{
	int n;
	scanf("%d", &n);
	int *p = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; i++) scanf("%d", p + i);
	for(int i = 2; i <= n; i++) 
	{
		int low = 1, high = i - 1;
		p[0] = p[i];
		while(low <= high)
		{
			int m = (low + high) / 2;
			if(p[0] > p[m]) low = m + 1;
			else high = m - 1;
		}
		for(int j = i - 1; j >= high + 1; j--) p[j + 1] = p[j];
		p[high + 1] = p[0];
		for(int j = 1; j <= n; j++) printf("%d ", p[j]);
		printf("\n");
	}
	return 0;
}








/*
输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出一趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 8 0 9 3 2 6 7 1
4 5 8 0 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 3 4 5 8 9 2 6 7 1
0 2 3 4 5 8 9 6 7 1
0 2 3 4 5 6 8 9 7 1
0 2 3 4 5 6 7 8 9 1
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
