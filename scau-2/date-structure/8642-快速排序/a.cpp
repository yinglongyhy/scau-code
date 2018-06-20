/*
8642 快速排序
时间限制:1000MS  内存限制:1000K
提交次数:2105 通过次数:1352

题型: 编程题   语言: G++;GCC
Description
用函数实现快速排序，并输出每次分区后排序的结果
*/

#include <stdio.h>
#include <malloc.h>

int Partition(int *a, int low, int high)
{
    a[0] = a[low];

    while(low < high)
    {
        while(low < high && a[high] >= a[0]) --high;
        a[low] = a[high];

        while(low < high && a[low] <= a[0]) ++low;
        a[high] = a[low];

    }
    a[low] = a[0];


    return low;
}

void QSort(int *a, int low, int high, int n)
{
    int k;
    if(low < high)
    {
        k = Partition(a, low, high);

        for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
        printf("\n");

        QSort(a, low, k - 1, n);
        QSort(a, k + 1, high, n);

    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    a[0] = n;
    for(int i = 1; i <= a[0]; i++) scanf("%d", a + i);
    QSort(a, 1, n, n);
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
1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
