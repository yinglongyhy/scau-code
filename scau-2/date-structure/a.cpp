#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L)
{  // �㷨2.3
  // ����һ���յ����Ա�L��
  L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if (!L.elem) return OK;        // �洢����ʧ��
  L.length = 0;                  // �ձ���Ϊ0
  L.listsize = LIST_INIT_SIZE;   // ��ʼ�洢����
  return OK;
} // InitList_Sq

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{  // �㷨2.4
  // ��˳�����Ա�L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)+1
  ElemType *p;
  if (i < 1 || i > L.length+1) return ERROR;  // iֵ���Ϸ�
  if (L.length >= L.listsize) {   // ��ǰ�洢�ռ���������������
    ElemType *newbase = (ElemType *)realloc(L.elem,
                  (L.listsize+LISTINCREMENT)*sizeof (ElemType));
    if (!newbase) return ERROR;   // �洢����ʧ��
    L.elem = newbase;             // �»�ַ
    L.listsize += LISTINCREMENT;  // ���Ӵ洢����
  }
  ElemType *q = &(L.elem[i-1]);   // qΪ����λ��
  for (p = &(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
                                  // ����λ�ü�֮���Ԫ������
  *q = e;       // ����e
  ++L.length;   // ����1
  return OK;
} // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{  // �㷨2.5
  // ��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ��
  // i�ĺϷ�ֵΪ1��i��ListLength_Sq(L)��
  ElemType *p, *q;
  if (i<1 || i>L.length) return ERROR;  // iֵ���Ϸ�
  p = &(L.elem[i-1]);                   // pΪ��ɾ��Ԫ�ص�λ��
  e = *p;                               // ��ɾ��Ԫ�ص�ֵ����e
  q = L.elem+L.length-1;                // ��βԪ�ص�λ��
  for (++p; p<=q; ++p) *(p-1) = *p;     // ��ɾ��Ԫ��֮���Ԫ������
  --L.length;                           // ����1
  return OK;
} // ListDelete_Sq

int main()
{
    SqList A,B;
    InitList_Sq(A);
    InitList_Sq(B);
    int a,b,i,j;
    scanf("%d",&a);
    A.length=a;
    for(i=0;i<a;i++)
    {
        scanf("%d",&A.elem[i]);
    }
    scanf("%d",&b);
    for(i=0;i<b;i++)
    {
        scanf("%d",&B.elem[i]);
    }
    printf("List A:");
    for(i=0;i<a;i++)
        printf("%d ",A.elem[i]);
    i=0;
    for(j=0;j<b;j++)
    {
            for(i=0;i<a;i++)
                {
                    if(B.elem[j]>=A.elem[i])
                    {
                        ListInsert_Sq(A,i + 1,B.elem[j]);
                    }
                }
    }
    printf("\nList B:");
    for(i=0;i<b;i++)
        printf("%d ",B.elem[i]);
    printf("\nList C:");
    for(i=0;i<a+b;i++)
        printf("%d ",A.elem[i]);
    printf("\n");
    return 0;
}
