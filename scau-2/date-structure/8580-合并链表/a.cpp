/*
8580 合并链表
时间限制:1000MS  内存限制:1000K
提交次数:3724 通过次数:2077

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

Status ListCreat(LinkList &L)
{
    int n, e;
    scanf("%d", &n);
    if(n <= 0) return ERROR;

    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList p, q = L;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        if(!ListInsert_L(L, i + 1, e)) return ERROR;
    }
    return OK;
}

Status ListMix(LinkList &La, LinkList &Lb)
{
    LinkList la = La, lb = Lb->next;
    while(la->next && Lb->next)
    {
        lb = Lb->next;
        if(la->next->data > lb->data)
        {
            Lb->next = Lb->next->next;
            lb->next = la->next;
            la->next = lb;
            continue;
        }
        la = la->next;
    }
    if(Lb->next)
    {
        la->next = Lb->next;
    }
    return OK;
}

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

int main()
{
    LinkList La, Lb;
    ListCreat(La);
    ListCreat(Lb);
    printf("List A:");
    ListOut(La);
    printf("List B:");
    ListOut(Lb);
    ListMix(La, Lb);
    printf("List C:");
    ListOut(La);
    return 0;
}

/*
设计一个算法将两个非递减有序链表A和B合并成一个新的非递减有序链表C。



输入格式
第一行：单链表A的元素个数
第二行：单链表A的各元素（非递减），用空格分开
第三行：单链表B的元素个数
第四行：单链表B的各元素（非递减），用空格分开


输出格式
第一行：单链表A的元素列表
第二行：单链表B的元素列表
第三行：合并后单链表C的元素列表


输入样例
6
12 24 45 62 84 96
4
15 31 75 86


输出样例
List A:12 24 45 62 84 96 
List B:15 31 75 86 
List C:12 15 24 31 45 62 75 84 86 96

*/
