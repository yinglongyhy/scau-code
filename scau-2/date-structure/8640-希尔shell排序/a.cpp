/*
8640 希尔(shell)排序
时间限制:1000MS  内存限制:1000K
提交次数:1858 通过次数:1304

题型: 编程题   语言: G++;GCC
Description
用函数实现希尔(shell)排序，并输出每趟排序的结果,初始增量d=n/2,其后d=d/2
*/
#include <stdio.h>
#include <malloc.h>


void Insert(int *a, int length, int dk)
{
    int t = length;
    while(t - dk > 0)
    {
        if(a[t - dk] < a[0])
        {
            for(int i = length; i > t; i -= dk) a[i] = a[i - dk];
            a[t] = a[0];
            return;
        }
        t -= dk;
    }
    for(int i = length; i > t; i -= dk) a[i] = a[i - dk];
    a[t] = a[0];
}

void ShellInsert(int *a, int dk, int length)
{
    for(int i = 1; i <= dk; i++)
    {
        for(int j = i + dk; j <= length; j += dk)
        {
            a[0] = a[j];
            Insert(a, j, dk);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = n / 2; i > 0; i /= 2)
    {
        ShellInsert(a, i, n);
        for(int k = 1; k <= n; k++) printf("%d ", a[k]);
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
3 2 6 0 1 5 4 8 7 9
1 0 3 2 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
