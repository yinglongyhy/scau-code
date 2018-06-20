/*
8638 直接插入排序
时间限制:1000MS  内存限制:1000K
提交次数:2050 通过次数:1393

题型: 编程题   语言: G++;GCC
Description
用函数实现直接插入排序，并输出每趟排序的结果.
*/

#include <stdio.h>
#include <malloc.h>

void teavral(int *p, int n)
{
	for(int i = 0; i < n; i++) printf("%d ", p[i]);
	printf("\n");
}

void insert(int *p, int i, int j)
{
	int t = p[i];
	for(; i > j ; i--) p[i] = p[i - 1];
	p[j] = t;
}

int make(int *p, int n)
{
	if(n == 0) return 0;
	if(n == 1) {teavral(p, n); return 0;}
	int i = 1;
	for(; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(p[j] > p[i]) insert(p, i, j);
		}
		teavral(p, n);
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *p = (int *)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) scanf("%d", p + i);
	make(p, n);
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
