/*
8579 ��ʽ���Ա�Ļ�������
ʱ������:1000MS  �ڴ�����:1000K
�ύ����:5567 ͨ������:2176

����: �����   ����: G++;GCC
Description ��д�㷨������һ������n��Ԫ�صĴ�ͷ���ĵ�����L��ʵ�ֲ��롢ɾ������������������Ŀ�ṩ���ִ��룬�벹ȫ���ݡ�
*/
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int getlength(LinkList &L)
{
    int length = 0;
    LinkList p = L->next;
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}

int CreateLink_L(LinkList &L,int n){
// ��������n��Ԫ�صĵ�����
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // �Ƚ���һ����ͷ���ĵ�����
  //q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
	 scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // �����½��
    // �벹ȫ����
    if(!q) return ERROR;
    p->data = e;
    p->next = NULL;
    q->next = p;
    q = q->next;
  }
  return OK;
}

int LoadLink_L(LinkList &L){
// ���������
 LinkList p = L->next;

 if(!p)printf("The List is empty!"); // �����
 else
 {
	 printf("The LinkList is:");
	 while(p)    // �����
	 {
		printf("%d ",p->data);
		p = p->next;    // �����
	 }
 }
 printf("\n");
 return OK;
}

int LinkInsert_L(LinkList &L,int i,ElemType e){
// �㷨2.9
// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
// �벹ȫ����
    if(i < 1 || i > getlength(L) + 1) return ERROR;
    LinkList p = L->next, q = L;
    q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = NULL;
    if(i == 1)
    {
        q->next = L->next;
        L->next = q;
        return OK;
    }
    i -= 2;
    while(i--) p = p->next;
    q->next = p->next;
    p->next = q;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e){
// �㷨2.10
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
// �벹ȫ����
    if(i < 1 || i > getlength(L)) return ERROR;
    LinkList p = L->next, q;
    if(i == 1)
    {
        L->next = p->next;
        p->next = NULL;
        e = p->data;
        free(p);
        p = NULL;
        return OK;
    }
    i -= 2;
    while(i--) p = p->next;
    q = p->next;
    p->next = q->next;
    q->next = NULL;
    e = p->data;
    free(q);
    q = NULL;
    return OK;
}

int main()
{
 LinkList T;
 int a,n,i;
 ElemType x, e;
 printf("Please input the init size of the linklist:\n");
 scanf("%d",&n);
 printf("Please input the %d element of the linklist:\n", n);
 if(CreateLink_L(T, n))     // �ж������Ƿ񴴽��ɹ��������
 {
	 printf("A Link List Has Created.\n");
	 LoadLink_L(T);
	 //printf("%d\n", T->next->next->next->next->data);
 }
 while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(!LinkInsert_L(T, i, x)) printf("Insert Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Inserted!\n", x);
				  break;
			case 2: scanf("%d",&i);
				  if(!LinkDelete_L(T, i, e)) printf("Delete Error!\n"); // �ж�iֵ�Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 0: return 1;
		}
	}
}

/*

�����ʽ
����������ʽ˵����
���ݲ˵�������
1������1����ʾҪʵ�ֲ��������������Ҫ��������λ�ú�Ԫ�أ��ÿո�ֿ�
2������2����ʾҪʵ��ɾ��������������Ҫ����ɾ����λ��
3������3����ʾҪ���˳��������Ԫ��
4������0����ʾ�������


��������
3
3 6 9
3
1
4 12
2
1
3
0


�������
Please input the init size of the linklist:
Please input the 3 element of the linklist:
A Link List Has Created.
The LinkList is:3 6 9
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:3 6 9
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 12 is Successfully Inserted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 3 is Successfully Deleted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The LinkList is:6 9 12
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
*/
