//完成插入链表结点的函数(按学号顺序)，并调试通过、提交。

#include <stdio.h> 
#include <malloc.h> 
#define LEN sizeof(struct student) 

struct student 
{ 
     long num; 
     int score; 
     struct student *next; 
}; 

struct student *create(int n) //创建链表
{  
     struct student *head=NULL,*p1=NULL,*p2=NULL; 
     int i; 
     for(i=1;i<=n;i++) 
     {  p1=(struct student *)malloc(LEN); 
        scanf("%ld",&p1->num);     
        scanf("%d",&p1->score);     
        p1->next=NULL; 
        if(i==1) head=p1; 
        else p2->next=p1; 
        p2=p1; 
      } 
      return(head); 
} 

void print(struct student *head) //打印链表
{ 
    struct student *p; 
    p=head; 
    while(p!=NULL) 
    { 
        printf("%8ld%8d",p->num,p->score); 
        p=p->next; 
        printf("\n"); 
    } 
} 

struct student *insert(struct student *head, struct student *stud) //插入链表
{   
	struct student *p = head;
	if(NULL == p)
		head = stud;
	if(p -> num >= stud -> num)
	{
		stud -> next = p;
		head = stud;
	}
	else if(NULL == p -> next)
		p -> next = stud;
	while(p -> next != NULL)
	{
		if(p -> next -> num >= stud -> num)	
		{
			stud -> next = p -> next;
			p -> next = stud;
			break;
		}
		p = p -> next;
	}
	return head;
} 

int main() 
{ 
    struct student *head,*stu; 
    int n; 
    scanf("%d",&n);    
    head=create(n); 
    print(head); 
    stu=(struct student *)malloc(LEN); 
    scanf("%ld",&stu->num);         
    scanf("%d",&stu->score);     
    stu->next = NULL; 
    head=insert(head,stu); 
    print(head); 
	return 0;
} 
/*
输入样例
3			（3 students）
1			（code of no.1 student）
98			（score of no.1 student）
3			（code of no.2 student）
99			（score of no.2 student）
5			（code of no.3 student）
87			（score of no.3 student）
4			（code of no.3 student needs be inserted）
77			（score of no.3 student needs be inserted）


输出样例
       1      98
       3      99
       5      87
       1      98
       3      99
       4      77
       5      87
*/
