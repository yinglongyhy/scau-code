//已知有两个链表a和b，结点类型相同，均包括一个int类型的数据。编程把两个链表合并成一个，结点按升序排列。

#include "stdio.h" 
#include "malloc.h" 
#define LEN sizeof(struct DATA) 

struct DATA 
{ 
     long num; 
     struct DATA *next; 
}; 

struct DATA *create(int n) 
{ 
     struct DATA *head=NULL,*p1=NULL,*p2=NULL; 
     int i; 
     for(i=1;i<=n;i++) 
     {  p1=(struct DATA *)malloc(LEN); 
        scanf("%ld",&p1->num); 
        p1->next=NULL; 
        if(i==1) head=p1; 
        else p2->next=p1; 
        p2=p1; 
      } 
      return(head); 
} 

struct DATA *merge(struct DATA *head, struct DATA *head2) 
{ 
	struct DATA *p = head;
	while(p -> next != NULL) p = p -> next;
	p -> next = head2;
    return head; 
}

struct DATA *insert(struct DATA *head, struct DATA *d) 
{ 

    return head; 
} 

struct DATA *sort(struct DATA *head)  
{  
	int len = 0;
	int i, j;
	struct DATA *p = head, *pNext = NULL;
	while(p != NULL)
	{
		len++;
		p = p -> next;
	}
	for(i = 0; i < len - 1; i++)
	{
		p = head;
		for(j = 0; j < len - 1 - i; j++)
		{
			if(0 == j)
			{
				if(p -> num > p -> next -> num)
				{
					p = head -> next;
					head -> next = p -> next;
					p -> next = head;
					head = p;
				}
			}
			else
			{
				pNext = p -> next;
				if(pNext -> num > pNext -> next -> num)
				{
					p -> next = pNext -> next;
					pNext -> next = pNext -> next -> next;
					p -> next -> next = pNext;
				}
				p = p -> next;
			}
		}
	}
    return head; 
}  

void print(struct DATA *head) 
{ 
    struct DATA *p; 
    p=head; 
    while(p!=NULL) 
    { 
        printf("%ld",p->num); 
        p=p->next; 
        printf("\n"); 
    } 
} 

int main() 
{ 
    struct DATA *head, *head2; 
    int n; 
    long del_num; 
    scanf("%d",&n); 
    head=create(n); 
    scanf("%d",&n); 
    head2=create(n); 
    head = merge(head, head2); 
    head = sort(head); 
    print(head); 
	return 0;
} 
/*

输入格式
第一行一个数n，表示第一个列表的数据个数
每二行为n个数
第三行为一个数m
第四行为m个数


输出格式
输出合并后的有序的数据，一行一个数


输入样例
2
4 8
3
9 1 5


输出样例
1
4
5
8
9
*/
