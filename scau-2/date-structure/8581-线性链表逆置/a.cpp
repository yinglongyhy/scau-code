/*
8581 线性链表逆置
时间限制:1000MS  内存限制:1000K
提交次数:2811 通过次数:2032

题型: 编程题   语言: G++;GCC
Description
线性链表的基本操作如下：
*/
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;   
  int j = 0;
  while (p && j < i-1) {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  } 
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L

void ListOut(LinkList &L)
{
    LinkList p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void ListCreate(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        ListInsert_L(L, i + 1, e);
    }
}

void Listback(LinkList &L)
{
    LinkList p = L->next, q = L;
    L->next = NULL;
    while(p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

int main()
{
    LinkList L;
    ListCreate(L);
    printf("The List is:");
    ListOut(L);
    Listback(L);
    printf("The turned List is:");
    ListOut(L);
}
/*
设有一线性表A=（a0,a1,..., ai,...an-1)，其逆线性表定义为A'=( an-1,..., ai,...,a1, a0)，设计一个算法，将线性表逆置，要求线性表仍占用原线性表的空间。



输入格式
第一行：输入n，表示单链表的元素个数
第二行：输入单链表的各元素，用空格分开


输出格式
第一行：输出单链表逆置前的元素列表
第二行：输出单链表逆置后的元素列表


输入样例
8
32 97 54 65 35 84 61 75


输出样例
The List is:32 97 54 65 35 84 61 75 
The turned List is:75 61 84 35 65 54 97 32


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
