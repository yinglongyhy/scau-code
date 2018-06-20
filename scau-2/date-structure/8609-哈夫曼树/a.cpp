/*
8609 哈夫曼树
时间限制:1000MS  内存限制:1000K
提交次数:3178 通过次数:1263

题型: 编程题   语言: G++;GCC
Description 利用静态链表建立赫夫曼树，建树过程中要求左子树权值小于右子树权值，求各结点的编码。要求：叶子结点的个数n及结点值由键盘录入。本题给出程序代码,要求修改以满足测试要求.
*/
#include "stdio.h"
#include "malloc.h"
#include "string.h"
typedef struct{
   unsigned int weight;
   unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree; 
typedef char **HuffmanCode;

void select(HuffmanTree &HT, int &s1, int &s2)
{
	int i = 1;
	int flag1 = 1, flag2 = 1;
	while(HT[i].weight)
	{
		if(!HT[i].parent)
		{
			if(flag1) 
			{
				flag1 = 0;
				s1 = i;
			}
			else if(flag2)
			{
				flag2 = 0;
				s2 = i;
				if(HT[s1].weight > HT[s2].weight)
				{
					int t = s1;
					s1 = s2;
					s2 = t;
				}
			}
			else if(HT[s1].weight > HT[i].weight || HT[s2].weight > HT[i].weight)
			{
				if(HT[s1].weight > HT[i].weight) 
				{
					s2 = s1;
					s1 = i;
				}
				else if(HT[s2].weight > HT[i].weight) s2 = i;
			}

		}
		i++;
	}
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
	int s1, s2;
	if(n <= 1) return;
	int m = 2 * n - 1;
	for(int i = 0; i < n; i++) 
	{
		HT[i + 1].weight = w[i];
		HT[i + 1].parent = 0;
		HT[i + 1].lchild = 0;
		HT[i + 1].rchild = 0;
	}
	for(int i = n + 1; i <= m; i++)
	{
		HT[i].weight = 0;
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	//构建赫夫曼树
	for(int i = n + 1; i <= m; i++)
	{
		select(HT, s1, s2);
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
	}
	//构建赫夫曼编码表
	char *p = (char *)malloc(20 * sizeof(char));
	for(int i = 1, j, t, start; i <= n; i++)
	{
		start = 20;
		HC[i] = (char *)malloc(20 * sizeof(char));
		p[--start] = 0;
		j = i;
		t = i;
		while(HT[j].parent)	
		{
			t = j;
			j = HT[j].parent;
			if(HT[j].lchild == t) p[--start] = '0';
			if(HT[j].rchild == t) p[--start] = '1';
		}
		strcpy(HC[i], &p[start]);
	}
}

int main()
{
   int i,n;
   int *w;
   HuffmanTree HT;
   HuffmanCode HC;
   scanf("%d",&n);  //权值个数
   w=(int *)malloc(n*sizeof(int));  
   for ( i=0;i<n;i++)  //录入权值
	 scanf("%d",&w[i]);
   
   HC=(char **)malloc((n+1)*sizeof(char*)); //0空间未用
   HT=(HuffmanTree)malloc((2*n)*sizeof(HTNode));//0空间未用
   HuffmanCoding(HT, HC, w, n);
   for (i = 1; i<n+1; i++){
	 puts(HC[i]);  //输出哈夫曼编码
	 free(HC[i]);  //释放空间
   }
   free(HC);
   free(HT);
   return 0;
}//main


/*
输入格式
第一行：权值个数
第二行：输入n个权值，用空格分隔


输出格式
输出n行
每行表示各权值对应的哈夫曼编码


输入样例
8
5 29 7 8 14 23 3 11


输出样例
0001
10
1110
1111
110
01
0000
001


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
