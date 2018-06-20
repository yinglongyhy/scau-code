#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int top = 0;
char (*p)[99] = NULL;

void MyStack();				//分配内存初始化空间，设定栈容量，栈顶
void killStack();			//回收栈空间内存
int stackEmpty();			//判定栈是否为空，为空返回1，非空返回0
int stackFull();			//判定栈是否为满，为满返回1，不满返回0
void clearStack();			//清空栈
void push();				//元素入栈，栈顶上升
void pop();					//元素出栈，栈顶下降
void stackTraverse();		//遍历栈中所有元素


void MyStack()		
{
	scanf("%d", &size);
	p = (char (*)[99])malloc(sizeof(char) * size * 99);		
	top = 0;
}

void killStack()	
{
	free(p);
	p = NULL;
}

int stackEmpty()	
{
	return 0 == top ? 1 : 0;
}

int stackFull()	
{
	return size == top ? 1 : 0;
}

void clearStack()
{
	top = 0;
    stackTraverse();

}

void push()
{
	if(!stackFull())
	{
		char ch[99];
		getchar();
		scanf("%s", ch);
		strcpy(p[top], ch);
		top++;
	}
	else
		printf("栈已满！");
	stackTraverse();

}

void pop()			
{
	if(!stackEmpty())
	{
		top--;
		printf("       %s\n", p[top]);	
	}
    stackTraverse();

}

void stackTraverse()
{
	int i = top - 1;
	printf("\n");
	for(; i >= 0; i--)
	{
		printf("***%s***\n", p[i]);
	}
	printf("*************\n");
}

void ctrl()
{
	printf("****************\n");
	printf("请选择：\n");
	printf("1、创建栈\n");
	printf("2、销毁栈\n");
	printf("3、成员入栈\n");
	printf("4、成员出栈\n");
	printf("5、遍历栈\n");
	printf("****************\n");
}

void choice()
{
	ctrl();
	int i;
	scanf("%d", &i);
	if(1 != i && NULL == p)
	{
		printf("栈不存在！\n");
		exit(0);
	}
	switch(i)
	{
		case 1:
			MyStack();
		  break;
		case 2:
			killStack();
		  break;
		case 3:
			push();
		  break;
		case 4:
			pop();
		  break;
		case 5:
			stackTraverse();
		  break;
		default: 
			exit(0);
	}
	choice();
}


int main()
{
	choice();
	return 0;
}
