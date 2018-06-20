/*
8646 基数排序
时间限制:1000MS  内存限制:1000K
提交次数:1581 通过次数:1071

题型: 编程题   语言: G++;GCC
Description
用函数实现基数排序，并输出每次分配收集后排序的结果
*/

#include <stdio.h>
#include <malloc.h>
#define MAX_NUM_OF_KEY 8
#define RADIX 10

typedef struct {
    int keys[MAX_NUM_OF_KEY];
    int next;
}SLCell;

typedef struct {
    SLCell *r;
    int keynum;//关键字个数
    int recnum;//比较数字个数
}SLList;

void Print(SLList &L)
{
    for(int i = L.r[0].next; i; i = L.r[i].next)
    {
        for(int j = L.keynum; j >= 0; j--) printf("%d", L.r[i].keys[j]);
        printf(" ");
    }
    printf("\n");
}

void Send(SLList &L, int r, int *f, int *n)
{
    int j;
    for(int i = 0; i < RADIX; ++i) f[i] = 0;
    for(int p = L.r[0].next; p; p = L.r[p].next)
    {
        j = L.r[p].keys[r];
        if(!f[j]) f[j] = p;
        else L.r[n[j]].next = p;
        n[j] = p;
    }
}

void Collect(SLList &L, int *f, int *n)
{
    int index = 0;
    for(int i = 0; i < RADIX; ++i)
    {
        if(!f[i]) continue;
        int t = 0;
        do
        {
            if(!t) t = f[i];
            else t = L.r[t].next;

            L.r[index].next = t;
            index = t;
        }while(t != n[i]);
    }
    L.r[index].next = 0;
}

void RadixSort(SLList &L)
{
    //将L改造成静态链表
    for(int i = 0; i < L.recnum; ++i) L.r[i].next = i+1;
    L.r[L.recnum].next = 0;

    int *f= (int *)malloc(sizeof(int)*RADIX);
    int *n= (int *)malloc(sizeof(int)*RADIX);

    for(int k = 0; k <= L.keynum; ++k)
    {
        Send(L, k, f, n);
        Collect(L, f, n);
        Print(L);
    }

}

int main()
{
    int temp;
    scanf("%d", &temp);
    SLList L;
    L.keynum = 0;
    L.recnum = temp;
    L.r = (SLCell *)malloc(sizeof(SLCell)*(L.recnum+1));//零号元素不存数据
    for(int i = 1; i <= L.recnum; i++) 
    {
        scanf("%d", &temp);
        for(int j = 0; j < MAX_NUM_OF_KEY; j++) L.r[i].keys[j] = 0;
        for(int j = 0; j < MAX_NUM_OF_KEY; j++)
        {
            L.r[i].keys[j] = temp % RADIX;
            temp /= RADIX;
            if(L.keynum < j) L.keynum = j;
            if(!temp) break;
        }
    }

    RadixSort(L);

    return 0;
}

/*
输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟每次分配收集后排序的结果，数据之间用一个空格分隔


输入样例
10
278 109 063 930 589 184 505 069 008 083


输出样例
930 063 083 184 505 278 008 109 589 069 
505 008 109 930 063 069 278 083 184 589 
008 063 069 083 109 184 278 505 589 930 


提示


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
