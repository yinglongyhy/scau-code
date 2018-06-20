/*
8586 括号匹配检验
时间限制:1000MS  内存限制:1000K
提交次数:4447 通过次数:1864

题型: 编程题   语言: G++;GCC
Description 利用栈编写满足下列要求的括号匹配检验程序：假设表达式中允许包含两种括号：圆括号和方括号，其嵌套的顺序随意，即([]())或[([][])]等为正确的格式，[(]或([())或(()])均为不正确的格式。输入一个包含上述括号的表达式，检验括号是否配对。本题给出部分check()函数，要求将check()函数补充完整，并完成整个程序。
*/
typedef char SElemType;
#include"malloc.h" 
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
struct SqStack
{
 SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
 SElemType *top; // 栈顶指针
 int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈
Status InitStack(SqStack &S)
{ 
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base) return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty(SqStack S)
{ 
    return S.base == S.top ? OK : ERROR;
}

Status Push(SqStack &S,SElemType e)
{
    if(S.top == S.base + S.stacksize)
    {
        SElemType *p = (SElemType *)realloc(S.base, S.stacksize + STACKINCREMENT);
        if(!p) return ERROR;
        S.base = p;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{ 
    if(StackEmpty(S)) return ERROR;
    S.top--;
    e = *S.top;
    return OK;
}

void check()
{ // 对于输入的任意一个字符串，检验括号是否配对
SqStack s;
SElemType ch[80],*p,e;
if(InitStack(s)) // 初始化栈成功
{
//printf("请输入表达式\n");
    gets(ch);
 p=ch;
 while(*p) // 没到串尾
   switch(*p)
   {
     case '(':
     case '[': Push(s, *p); p++;
              break; // 左括号入栈，且p++
     case ')':
     case ']':if(!StackEmpty(s)) // 栈不空
              {
               Pop(s, e); // 弹出栈顶元素
                if(*p==')'&&e!='('|| *p == ']' && e != '[') 
                                            // 弹出的栈顶元素与*p不配对
                {
                  printf("isn't matched pairs\n");
                  exit(ERROR);
                }
                else
                {
                  p++;
                  break; // 跳出switch语句
                }
              }
              else // 栈空
              {
                printf("lack of left parenthesis\n");
                exit(ERROR);
              }
     default: p++; // 其它字符不处理，指针向后移
   }
 if(StackEmpty(s)) // 字符串结束时栈空
   printf("matching\n");
 else
   printf("lack of right parenthesis\n");
}
}
int main()
 {
   check();
 }

/*

输入格式
第一行：输入一个包含圆括号或方括号、不超过80个字符的表达式串。


输出格式
第一行：若输入表达式括号匹配，输出"matching"; 若不匹配，输出具体信息:"isn't matched pairs", 或"lack of left parenthesis"或"lack of right parenthesis"


输入样例
8*[3*(35-23)]


输出样例
matching


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
