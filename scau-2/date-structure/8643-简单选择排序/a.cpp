/*
8643 简单选择排序
时间限制:1000MS  内存限制:1000K
提交次数:2235 通过次数:1301

题型: 编程题   语言: G++;GCC
Description
用函数实现简单选择排序，并输出每趟排序的结果
*/
#include <stdio.h>
#include <malloc.h>

void EasySort(int *a)
{
    int t;
    for(int i = 1; i < a[0]; ++i)
    {
        t = i;
        for(int j = i + 1; j <= a[0]; ++j)
        {
            if(a[t] > a[j]) t = j;
        }
        int temp = a[t];
        a[t] = a[i];
        a[i] = temp;
        for(int k = 1; k <= a[0]; ++k) printf("%d ", a[k]);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    a[0] = n;
    EasySort(a);
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
0 4 8 5 9 3 2 6 7 1
0 1 8 5 9 3 2 6 7 4
0 1 2 5 9 3 8 6 7 4
0 1 2 3 9 5 8 6 7 4
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
