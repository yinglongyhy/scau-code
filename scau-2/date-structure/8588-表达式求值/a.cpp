/*
8588 表达式求值
时间限制:1000MS  内存限制:1000K
提交次数:3462 通过次数:1255

题型: 编程题   语言: G++;GCC
Description
顺序栈的基本操作如下：
*/
#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{   
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
	 S.top=S.base;
	 S.stacksize=STACK_INIT_SIZE;
	 return OK;
}

Status Push(SqStack &S,SElemType e)   
{   
// 在栈S中插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return ERROR;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}

int Pop(SqStack &S)   
{   
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
    S.top--;
	 return *S.top;
}

Status GetTop(SqStack S)   
{    
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base) return -99999;
    S.top-=1;
	return *S.top;
}

int StackLength(SqStack S) 
{   
// 返回栈S的元素个数
	int i;
    i=S.top-S.base;
	return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
	p = S.top;       
	if(S.top==S.base)printf("The Stack is Empty!");  
	else
	{
		printf("The Stack is: ");
		p--;
		while(p>=S.base)             
		{
			printf("%d ", *p);
			p--;               
		}
	}
	printf("\n");
	return OK;
}

int input()
{
    SqStack num, cha;
    InitStack(num);
    InitStack(cha);
    char ch = getchar();
    int e = 0, flag = 0;
    while(ch != '=')
    {
        if(ch >= '0' && ch <= '9')
        {
            flag = 1;
            e = e * 10 + ch - 48;
            ch = getchar();
            continue;
        }
        StackTraverse(num);
        if(flag)
        {
            Push(num, e);
            flag = 0;
        }
        e = 0;
        if(GetTop(cha) == 3 || GetTop(cha) == 4)
        {
            if(ch != '(')
            {
                e = Pop(num);
                if(GetTop(cha) == 3) e = Pop(num) * e;
                if(GetTop(cha) == 4) e = Pop(num) / e;
                Push(num, e);
                e = 0;
            }
        }
        switch(ch)
        {// (1 )2 *3 /4 +5 -6
            case '(': Push(cha, 1); break;
            case ')': 
                      while(GetTop(cha) != 1)
                      {
                          if(Pop(cha) == 6) e += -Pop(num);
                          else e += Pop(num);
                      }
                      e += Pop(num);
                      Pop(cha);
                      Push(num, e);
                      e = 0;
                      //printf("%d\n", e);
                      break;
            case '*': Push(cha, 3); break;
            case '/': Push(cha, 4); break;
            case '+':
            case '-': 
                      if(GetTop(cha) == 3)
                      {
                          e = Pop(num) * e; 
                          Pop(cha);
                      }
                      if(GetTop(cha) == 4)
                      {
                          e = Pop(num) / e;
                          Pop(cha);
                      }
                      if(ch == '+') Push(cha, 5);
                      else Push(cha, 6);
                      break;
        }
        ch = getchar();
    }
    //Push(num, e);
    StackTraverse(num);
    StackTraverse(cha);
    int *p = num.base, *q = cha.base;
    if(p != num.top)
    {
        e = *p;
        p++;
    }
    while(p != num.top)
    {
        /*
        if(*p == 0)
        {
            p++;
            continue;
        }
        if(*q == 0)
        {
            q++;
            continue;
        }
        */
        if(*q == 3) e *= *p;
        if(*q == 4) e /= *p;
        if(*q == 5) e += *p;
        if(*q == 6) e -= *p;
        p++;
        q++;
    }
    printf("%d\n", e);

}

int main()
{
    input();
    return 0;
}
/*
利用栈编写表达式求值程序：输入含有“+”、“-”、“*”、“/”四则运算的表达式，其中负数要用（0-正数）表示，并以=结束。要求输出表达式的值（两运算符号的优先关系见教材表3.1）。



输入格式
第一行：一个算术表达式


输出格式
第一行：算术表达式的值


输入样例
3*(9-7)=


输出样例
6


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
