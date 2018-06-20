struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈
Status InitStack(SqStack &S)       
Status Push(SqStack &S,SElemType e)   
Status Pop(SqStack &S,SElemType &e)   
Status GetTop(SqStack S,SElemType &e)   
int StackLength(SqStack S) 
Status StackTraverse(SqStack S)
