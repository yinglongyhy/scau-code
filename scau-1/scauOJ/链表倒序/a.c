#include "stdio.h" 
#include "malloc.h" 
#define LEN sizeof(struct student) 

struct student 
{ 
     long num; 
     int score; 
     struct student *next; 
}; 

struct student *create(int n) 
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

void print(struct student *head) 
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

struct student *reverse(struct student *head) 
{ 
	struct student *len = head, *head1 = NULL, *p = NULL;
	int lg = 0, i;
	while(NULL != len)//计算节点长度
	{
		lg++;
		len = len -> next;
	}
	while(0 != lg)
	{
		len = head;
		for(i = 1; i < lg; i++)
			len = len -> next;
		if(len -> next == NULL)
		{
			p = len;
			p -> next = NULL;
			head1 = p;
		}
		else
		{
			p -> next = len;
			p = len;
		}
		lg--;
	}
	p -> next = NULL;
	return head1;
} 

int main() 
{ 
    struct student *head,*stu; 
    int n; 
    scanf("%d",&n);   
    head=create(n); 
    print(head); 
    head=reverse(head); 
    print(head); 
	return 0;
}
