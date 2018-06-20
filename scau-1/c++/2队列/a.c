#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int *p = NULL, head, tail;//队列数组指针  下标
int len = 0;      //队列元素个数
int capacity = 0; //队列数组容量

void myQueue();				//创建队列
void killQueue();			//销毁队列
void clearQueue();			//清空队列
int is_Queue();				//判断队列是否有空
void enQueue();				//插入成员
void enQueue();				//插入成员
void deQueue();				//删除成员
void outQueue();			//首元素出列
void traverQueue();			//遍历队列

void myQueue()//创建队列
{
	scanf("%d", &capacity);
	p = (int *)malloc(capacity * sizeof(int));
	head = 0;
	tail = 0;
	len = 0;
	traverQueue();	
}

void killQueue()//销毁队列
{
	free(p);
	p = NULL;
	printf("%p\n", p);
}

void clearQueue()//清空队列
{
	head = 0;
	tail = 0;
	len = 0;
	traverQueue();
}

int is_Queue()//判断队列是否有空
{
	return len < capacity ? 1 : 0;	
}

void enQueue()//插入成员
{
	if(is_Queue())
	{
		scanf("%d", &p[tail]);
		tail = (tail + 1) % 4;
		len++;
	}
	else
		printf("插入失败！\n");
	traverQueue();
}

void deQueue()//删除成员
{
	if(len)
	{
		int i;
		printf("输入想删除成员的下标\n");
		scanf("%d", &i);
		for(; i % capacity != tail; i = (i + 1) % capacity)
		{
			p[i] = p[(i + 1) % capacity];
		}
		tail = (tail + capacity - 1) % capacity;
		len--;
	}
	else
		printf("删除失败！当前成员为0。\n");
	traverQueue();
}

void outQueue()//首元素出列
{
	if(len)
	{
		head = (head + 1) % capacity;
		len--;
	}
	else
		printf("当前队列没有元素！");
	traverQueue();
}

void traverQueue()//遍历队列
{
	if(len > 0)
	{
		int i;
		printf("            len   capacity\n");
		for(i = head; i < head + len; i++)
		{
			printf("p[%d]   %-5d%-9d%d\n", i % capacity, p[i % capacity], len, capacity);
		}
	}
}

void print()
{
	printf("**********************************\n");
	printf("请选择：\n");
	printf("1、创建队列\n");
	printf("2、销毁队列\n");
	printf("3、清空队列\n");
	printf("4、新元素入队\n");
	printf("5、首元素出队\n");
	printf("6、遍历队列\n");
	printf("7、删除成员\n");
	printf("**********************************\n");
}

void choice()
{
	int i;
	int j;
	j = 0;
	print();
	scanf("%d", &i);
	switch(i)
	{
		case 1:
			myQueue(capacity);		
		break;
		case 2:
			killQueue();
		break;
		case 3:
			clearQueue();
		break;
		case 4:
			enQueue();
		break;
		case 5:
			outQueue();
		break;
		case 6:
			traverQueue();
		break;
		case 7:
			deQueue();
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


