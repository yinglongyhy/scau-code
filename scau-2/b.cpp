#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
  int data;
  struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T,int ch)
  {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;
    T->lchild=NULL;
    T->rchild=NULL;
    return OK;
  }

Status EnterBiTree(BiTree &T, int ch) {  // �㷨6.4
  // �������������������н���ֵ��һ���ַ���
  //D:\����ר��Ŀ¼\���������������\main.cpp|87|error: expected primary-expression before ')' token| ������������ʾ�Ķ�����T��
  if(T==NULL)
  {
      CreateBiTree(T,ch);
      return OK;
  }
  else if(ch<T->data)
  {
      EnterBiTree(T->lchild,ch);
      return OK;
  }
  else
  {
      EnterBiTree(T->rchild,ch);
      return OK;
  }
} // CreateBiTree


Status PrintElement( ElemType e ) {  // ���Ԫ��e��ֵ
    printf("%d ", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
   // ǰ�����������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
   //��ȫ����,���ö�����
    if(T)
    {
    	Visit(T->data);
	    PreOrderTraverse( T->lchild, Visit );
		PreOrderTraverse( T->rchild, Visit );
    }
    return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
    //��ȫ����,���ö�����
    if(T)
    {
        InOrderTraverse( T->lchild, Visit );
        Visit(T->data);
        InOrderTraverse( T->rchild, Visit );
    }
    return OK;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
     //��ȫ����,���ö�����
    if(T)
    {
        PostOrderTraverse( T->lchild, Visit );
        PostOrderTraverse( T->rchild, Visit );
        Visit(T->data);
    }
    return OK;
} // PostOrderTraverseD:\����ר��Ŀ¼\���������������\main.cpp|87|error: expected primary-expression before ')' token|




int main()
{
    BiTree T;
    int i,num,num1,ch;
    scanf("%d\n",&num);
    scanf("%d ",&num1);
    if(!CreateBiTree(T,num1)) return ERROR;
    for(i=0;i<num-1;i++)
    {
        scanf("%d ",&ch);
        EnterBiTree(T,ch);
    }
    PreOrderTraverse(T,PrintElement);
    printf("\n") ;
    InOrderTraverse(T,PrintElement);
    printf("\n") ;
    PostOrderTraverse(T,PrintElement);
    printf("\n") ;
    return OK;
}







