/*
8606 二叉树的构建及遍历操作
时间限制:1000MS  内存限制:1000K
提交次数:2653 通过次数:1597

题型: 编程题   语言: G++;GCC
Description 构造二叉链表表示的二叉树：按先序次序输入二叉树中结点的值（一个字符），'#'字符表示空树，构造二叉链表表示的二叉树T；再输出三种遍历序列。本题只给出部分代码,请补全内容。
*/
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
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data = ch;// 生成根结点
    CreateBiTree(T->lchild);   // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree


Status PrintElement(ElemType e ) {  // 输出元素e的值
printf("%c", e ); 
return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
   // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
   //补全代码,可用多个语句
//    printf("%p\n", T);
    if(T == NULL) return ERROR;
    Visit(T->data);
    PreOrderTraverse(T->lchild, &PrintElement);
    PreOrderTraverse(T->rchild, &PrintElement);
    return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
    if(T == NULL) return ERROR;
    InOrderTraverse(T->lchild, &PrintElement);
    Visit(T->data);
    InOrderTraverse(T->rchild, &PrintElement);
    return OK;
    
  
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
     //补全代码,可用多个语句
    if(T == NULL) return ERROR;
    PostOrderTraverse(T->lchild, &PrintElement);
    PostOrderTraverse(T->rchild, &PrintElement);
    Visit(T->data);
    return OK;
    
} // PostOrderTraverse



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T, &PrintElement);                 //补充代码
    printf("\n");
    InOrderTraverse(T, &PrintElement);                 //补充代码
    printf("\n");
    PostOrderTraverse(T, &PrintElement);                 //补充代码
    printf("\n");
    return 0;
}//main



/*
输入格式
第一行：输入一棵二叉树的先序遍历序列


输出格式
第一行：二叉树的先序遍历序列
第二行：二叉树的中序遍历序列
第三行：二叉树的后序遍历序列


输入样例
AB##C##


输出样例
ABC
BAC
BCA


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
