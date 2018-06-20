/*
8641 冒泡排序
时间限制:1000MS  内存限制:1000K
提交次数:3093 通过次数:1361

题型: 编程题   语言: G++;GCC
Description
用函数实现冒泡排序，并输出每趟排序的结果(要求当一趟冒泡过程中不再有数据交换，则排序结束)
*/
#include <stdio.h>
#include <malloc.h>

void doit(int *a)
{
    int t;
    int flag = 0;
    for(int i = 1; i < a[0]; i++)
    {
        for(int j = 1; j <= a[0] - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                flag = 1;
            }
        }
        for(int k = 1; k <= a[0]; k++) printf("%d ", a[k]);
        printf("\n");
        if(!flag) return;
        flag = 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc((n + 1) * sizeof(int));
    a[0] = n;
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    doit(a);
    return 0;
}




/*
输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 0 8 3 2 6 7 1 9
4 0 5 3 2 6 7 1 8 9
0 4 3 2 5 6 1 7 8 9
0 3 2 4 5 1 6 7 8 9
0 2 3 4 1 5 6 7 8 9
0 2 3 1 4 5 6 7 8 9
0 2 1 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
