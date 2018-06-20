#include <stdio.h>
#include <stdlib.h>
struct record{
	char name[20];
	int level;
	double atk;
	struct record *next;
};
struct record *input()
{
	struct record *p1, *p2, *head;
	p1 = p2 = (struct record *)malloc(sizeof(struct record));
	
	printf("name:");
	scanf("%s", p1 -> name);
	printf("level:");
	scanf("%d", &p1 -> level);
	printf("atk:");
	scanf("%lf", &p1 -> atk);
	head = NULL;

	while(0 < p1 -> level)
	{
		if(NULL == head)
			head = p1;
		else
			p2 -> next = p1;	

		p2 = p1;
		
		p1 = (struct record *)malloc(sizeof(struct record));	
		printf("name:");
		scanf("%s", p1 -> name);
		printf("level:");
		scanf("%d", &p1 -> level);
		printf("atk:");
		scanf("%lf", &p1 -> atk);
		
	}
	p2 -> next = NULL;
	return head;
}
int main()
{
	struct record *p;
	FILE *fp;
	p = input();
	fp = fopen("filel.txt", "w");
	fprintf(fp, "name      level     atk\n");
	while(NULL != p)
	{
		fprintf(fp, "%-10s%-10d%.2lf\n", p -> name, p -> level, p -> atk);
		p = p -> next;
	}
	fclose(fp);

	return 0;
}
