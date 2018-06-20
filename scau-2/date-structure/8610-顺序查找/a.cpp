/*
8610 顺序查找
时间限制:1000MS  内存限制:1000K
提交次数:2303 通过次数:1423

题型: 编程题   语言: G++;GCC
Description 编写Search_Seq函数，实现在一个无序表ST中采用顺序查找算法查找值为key的元素的算法.
*/
#include"malloc.h" /* malloc()等 */ 
#include"stdio.h"
#include"stdlib.h"

typedef int ElemType; 
typedef struct /*静态查找表的顺序存储结构 */ 
{ 
	ElemType *elem; /* 数据元素存储空间基址，建表时按实际长度分配，0号单元留空 */ 
	int length; /* 表长度 */ 
}SSTable; 

void Creat_Seq(SSTable &ST,int n) 
{ /* 操作结果: 构造一个含n个数据元素的静态顺序查找表ST(数据来自数组r) */ 
	int i,temp; 
	ST.elem=(ElemType *)malloc((n+1) * sizeof(ElemType)); /* 动态生成n个数据元素空间(0号单元不用) */ 
	if(!(ST).elem) 
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/ 
	for(i=1;i<=n;i++) 
	{ 
		scanf("%d",&temp); 
		*(ST.elem+i)=temp; /* 依次赋值给ST */ 
	} 
	ST.length=n; 
} 

int Search_Seq(SSTable &ST,ElemType key) 
{ /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为 */ 
/* 该元素在表中的位置，否则为0。算法9.1 */ 
	int i;
	for(i = 1; i <= ST.length; i++)
		if(ST.elem[i] == key) return i;
	return 0;
} 

int main() 
{ 
	SSTable ST; 
	int loc,key; 
	int n; 
	scanf("%d",&n); 
	Creat_Seq(ST,n); 
	//printf("Please input the key value："); 
	scanf("%d",&key); 
	loc = Search_Seq(ST,key); 
	if(loc!=0) 
		printf("The element position is %d.\n",loc); 
	else 
		printf("The element is not exist.\n"); 
	return 0;
}


/*
输入格式
第一行:元素个数n 
第二行：依次输入n个元素的值 
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形： 
1.如果key值存在，则输出其在表中的位置x(表位置从1开始),格式为The element position is x. 
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
The element position is 3.


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
