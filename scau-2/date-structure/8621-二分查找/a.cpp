/*
8621 二分查找
时间限制:1000MS  内存限制:1000K
提交次数:4655 通过次数:1446

题型: 编程题   语言: G++;GCC
Description 编写Search_Bin函数，实现在一个递增有序数组ST中采用折半查找法确定元素位置的算法. 
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
	ST.elem=(ElemType *)malloc(n * sizeof(ElemType)); 
	if(!(ST).elem) 
	{
		printf("ERROR\n");
		exit(0);
	} /*内存分配失败结束程序*/ 
	for(i=0;i<n;i++) 
	{ 
		scanf("%d",&temp); 
		*(ST.elem+i)=temp; /* 依次赋值给ST */ 
	} 
	ST.length=n; 
} 

int Search_bin(SSTable &ST,ElemType key) 
{ /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为 */ 
/* 该元素在表中的位置，否则为0。算法9.1 */ 
	int pre = 0, last = ST.length - 1;
	int mid ;
	int flag = 1;
	if(ST.elem[last] == key) return last;
	while(flag)
	{
		mid = (pre + last) / 2;
		if(mid == pre || mid == last) flag = 0;
		if(ST.elem[mid] == key) return mid;
		else if(ST.elem[mid] < key) pre = mid;
		else last = mid;
	}
	return -1;
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
	loc = Search_bin(ST,key); 
	if(loc!=-1) 
		printf("The element position is %d.\n",loc); 
	else 
		printf("The element is not exist.\n"); 
	return 0;
}


/*
输入格式
第一行:元素个数n 
第二行：依次输入n个元素的值（有序） 
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形： 
1.如果key值存在，则输出其在表中的位置x(表位置从0开始),格式为The element position is x. 
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
The element position is 2.


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
