/*
8645 归并排序（非递归算法）
时间限制:1000MS  内存限制:1000K
提交次数:2398 通过次数:1192

题型: 编程题   语言: G++;GCC
Description
用函数实现归并排序（非递归算法），并输出每趟排序的结果
*/
#include <stdio.h>
#include <malloc.h>

void show(int *a)
{
    for(int i = 1; i <= a[0]; i++) printf("%d ", a[i]);
    printf("\n");
}

void Merge(int *a, int s, int t)
{//a[s, s + t - 1], a[s + t, s + t - 1 + t]  范围 < a[0]
    if(s + t - 1 >= a[0]) return;
    int n;
    if(s + 2 * t - 1 <= a[0]) n = 2 * t;
    else n = a[0] - s + 1;
    int *temp = (int *)malloc((1 + n) * sizeof(int));
    temp[0] = n;
    int i, j, k;
    for(i = s, j = s + t, k = 1; i <= s + t - 1 && j <= a[0] && j <= s + t * 2 - 1; )
    {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    if(i <= s + t - 1)
        for( ; i <= s + t - 1; i++, k++) temp[k] = a[i];
    else if(j <= a[0] && j <= s + t * 2 - 1)
        for( ; j <= a[0] && j <= s + t * 2 - 1; j++, k++) temp[k] = a[j];

    for(i = s, k = 1; k <= temp[0]; i++, k++) a[i] = temp[k];
    free(temp);
    temp = NULL;
}


void MSort(int *a)
{
    for(int n = 1; n < a[0]; n *= 2)
    {
        for(int i = 0; i <= a[0] / n / 2; i++)
        {
            for(int k = 1; k <= a[0]; k += 2 * n)
            {//合并a[k, k + n - 1] a[k + n, k + 2 * n - 1]
                Merge(a, k, n);
            }
        }
        show(a);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    a[0] = n;
    MSort(a);
    return 0;
}





/*
输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 0 8 3 9 2 6 1 7
0 4 5 8 2 3 6 9 1 7
0 2 3 4 5 6 8 9 1 7
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
