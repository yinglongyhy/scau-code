#include <stdio.h>
#include <stdlib.h>
struct record {
	char name[20];
	int level;
	double atk;
	struct record *next;

};

struct record *creat()
{
	struct record *head, *p1, *p2;
	int n = 0;
	p1 = p2 = (struct record *)malloc(sizeof(struct record));
	printf("\t\t请输入第%d组数据\n", ++n);
	printf("name is ");
	scanf("%s", p1 -> name);
	printf("level is ");
	scanf("%d", &p1 -> level);
	printf("atk is ");
	scanf("%lf", &p1 -> atk);
	head = NULL;
	while(0 != p1 -> level)
	{
		if(1 == n)
			head = p1;
		else
			p2 -> next = p1;
		p2 = p1;
		n++;
		
		p1 = (struct record *)malloc(sizeof(struct record));
		printf("\t\t请输入第%d组数据\n", n);
		printf("name is ");
		scanf("%s", p1 -> name);
		printf("level is ");
		scanf("%d", &p1 -> level);
		printf("atk is ");
		scanf("%lf", &p1 -> atk);
	}
	p2 -> next = NULL;

	return head;
}

void output(struct record *p)
{
	printf("名字\t\t等级\t战斗力\n");
	while(NULL != p)
	{
		fputs(p -> name, stdout);
		printf("\t\t%d\t%.2lf\n", p -> level, p -> atk);
		p = p -> next;
	}
}


int main()
{
	struct record *p;
	p = creat();
	output(p);
	return 0;
}
