#include <stdio.h>
#include <malloc.h>

void HeapAdjust(int *a, int s, int m)
{
    int temp = a[s];
    for(int j = 2 * s; j <= m; j *= 2)
    {
        if(j < m && a[j] < a[j + 1]) ++j;
        if(temp >= a[j]) break;
        a[s] = a[j];
        s = j;
    }
    a[s] = temp;
}

void HeapSort(int *a)
{
    for(int i = a[0] / 2; i > 0; --i) HeapAdjust(a, i, a[0]);
    for(int i = a[0]; i > 1; --i)
    {
        for(int j = 1; j <= a[0]; ++j) printf("%d ", a[j]);
        printf("\n");

        int t = a[1];
        a[1] = a[i];
        a[i] = t;

        HeapAdjust(a, 1, i - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if(!n) return 0;
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    a[0] = n;
    HeapSort(a);
    for(int j = 1; j <= a[0]; ++j) printf("%d ", a[j]);
    printf("\n");
}
