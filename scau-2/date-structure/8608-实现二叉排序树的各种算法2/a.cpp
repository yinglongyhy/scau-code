/*
8608 实现二叉排序树的各种算法(2)
时间限制:1000MS  内存限制:1000K
提交次数:2559 通过次数:1396

题型: 编程题   语言: G++;GCC
Description
用函数实现如下二叉排序树算法： 
（1） 插入新结点 
（2） 前序、中序、后序遍历二叉树 
（3） 中序遍历的非递归算法 
（4） 层次遍历二叉树 
（5） 在二叉树中查找给定关键字(函数返回值为成功1,失败0) 
（6） 交换各结点的左右子树 
（7） 求二叉树的深度 
（8） 叶子结点数
*/

#include <iostream>
using namespace std;
typedef struct node{
    int date;
    char lorr;
    struct node *lchild, *rchild;
}Tree, *pTree;
typedef struct stack{
    pTree *stack;
    int top;
    int base;
}Stack;

bool StackCreate(Stack &s, int n)
{
    s.stack = (pTree*)malloc(n * sizeof(pTree));
    if(!s.stack) return false;
    s.top = s.base = 0;
    return true;
}

bool StackDelete(Stack &s)
{
    free(s.stack);
    s.stack = NULL;
	return true;
}

bool GetTop(Stack &s, pTree &p)
{
    if(s.top == s.base) return false;
    p = s.stack[s.top-1];
    return true;
}

bool Push(Stack &s, pTree &T)
{
    s.stack[s.top] = T;
    s.top++;
    return true;
}

bool Pop(Stack &s)
{
    if(s.top == s.base) return false;
    s.top--;
    pTree p = s.stack[s.top];
    if(!p) return true;
    cout << p->date << " ";
    return true;
}

bool TreeInsert(pTree &T);
bool TreeCreate(pTree &T, int &n)
{
    T = (pTree)malloc(sizeof(Tree));
    if(T == NULL) return false;
	cin >> T->date;
    T->lchild = NULL;
    T->rchild = NULL;
    for(int i = 1; i < n; i++)
    {
        TreeInsert(T);
    }
    return true;
}

bool TreeInsert(pTree &T)
{
    int temp;
    char ch = 0;
    cin >> temp;
	if(!T)
	{
		T = (pTree)malloc(sizeof(Tree));
		T->date = temp;
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
    pTree p = T, q = NULL;

    while(p)
    {
        if(p->date < temp) 
        {
            q = p;
            p = p->rchild;
            ch = 'r';
        }        
        else 
        {
            q = p;
            p = p->lchild;
            ch = 'l';
        }
    }
    p = (pTree)malloc(sizeof(Tree));
    if(!p) return false;
    p->date = temp;
    p->lchild = NULL;
    p->rchild = NULL;
    if(ch == 'l') q->lchild = p;
    else if(ch == 'r') q->rchild = p;
    return true;
}

bool pre(pTree &T)
{
    if(!T) return false;
    cout << T->date << " ";
    pre(T->lchild);
    pre(T->rchild);
    return true;
}

bool in(pTree &T)
{
    if(!T) return false;
    in(T->lchild);
    cout << T->date << " " ;
    in(T->rchild);
    return true;
}

bool next(pTree &T)
{
    if(!T) return false;
    next(T->lchild);
    next(T->rchild);
    cout << T->date << " " ;
    return true;
}

bool noin(pTree &T, int n)
{
    //栈顶指针非空访问左子树
    //左子树退栈返回访问根节点
    //访问根节点后访问右子树
    //右子树返回根节点退栈
    Stack s;
    StackCreate(s, n);
    pTree p = NULL;
    Push(s, T);
    while(GetTop(s, p))
    {
        while(GetTop(s, p) && p) Push(s, p->lchild);
        Pop(s);
        if(GetTop(s, p))
        {
            GetTop(s, p);
            Pop(s);
            Push(s, p->rchild);
        }
    }
    cout << endl;
    StackDelete(s);
	return true;
}

bool level(pTree &T)
{
	int i = 1;
	pTree *p = (pTree *)malloc(sizeof(pTree) * i);//something to do 
	p[0] = T;
	cout << p[0]->date << " ";
	int t;
	while(i)
	{
		t = 0;
		pTree *q = (pTree *)malloc(sizeof(pTree) * i * 2);//something to do 
		for(int j = 0; j < i; j++)
		{
			if(p[j]->lchild) q[t++] = p[j]->lchild;
			if(p[j]->rchild) q[t++] = p[j]->rchild;
		}
		for(int j = 0; j < t; j++) cout << q[j]->date << " ";
		i = t;
		free(p);
		p = q;
	}
	cout << endl;
	return true;
}

int find(pTree &T)
{
	int e;
	cin >> e;
	pTree p = T;
	while(p)
	{
		if(e == p->date) 
		{
			return 1;
		}
		if(e < p->date) 
		{
			p = p->lchild;
			continue;
		}
		if(e > p->date) 
		{
			p = p->rchild;
			continue;
		}
	}
	return 0;
}

void exchange(pTree &T)
{
	if(!T) return;
	pTree temp = NULL;
	temp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = temp;
	exchange(T->lchild);
	exchange(T->rchild);
}

bool deepin(pTree &T)
{
	if(!T) {cout << '0' << endl; return true;}
	int i = 1;
	int deep = 0;
	pTree *p = (pTree *)malloc(sizeof(pTree) * i);//something to do 
	p[0] = T;
	int t;
	while(i)
	{
		t = 0;
		pTree *q = (pTree *)malloc(sizeof(pTree) * i * 2);//something to do 
		for(int j = 0; j < i; j++)
		{
			if(p[j]->lchild) q[t++] = p[j]->lchild;
			if(p[j]->rchild) q[t++] = p[j]->rchild;
		}
		i = t;
		free(p);
		p = q;
		deep++;
	}
	cout << deep << endl;
	return true;
}

bool leave(pTree &T, int &n)
{
	if(!T) return true;
	if(!T->lchild && !T->rchild) n++;
	leave(T->lchild, n);
	leave(T->rchild, n);
	return true;
}


int main()
{
	pTree T;
	int n;
	cin >> n;
	if(n != 0) TreeCreate(T, n);
	else T = NULL;
	pre(T);
	cout << endl;
	in(T);
	cout << endl;
	next(T);
	cout << endl;
	cout << find(T) << endl;
	cout << find(T) << endl;
	TreeInsert(T);
	pre(T);
	cout << endl;
	in(T);
	cout << endl;
	next(T);
	cout << endl;
	noin(T, n);
	level(T);
	exchange(T);
	pre(T);
	cout << endl;
	in(T);
	cout << endl;
	next(T);
	cout << endl;
	exchange(T);
	pre(T);
	cout << endl;
	in(T);
	cout << endl;
	next(T);
	cout << endl;
	deepin(T);
	int q = 0;
	leave(T, q);
	cout << q << endl;
	return 0;
}
/*
输入格式
第一行：准备建树的结点个数n 
第二行：输入n个整数，用空格分隔 
第三行：输入待查找的关键字 
第四行：输入待查找的关键字 
第五行：输入待插入的关键字


输出格式
第一行：二叉树的先序遍历序列 
第二行：二叉树的中序遍历序列 
第三行：二叉树的后序遍历序列 
第四行：查找结果 
第五行：查找结果 
第六行~第八行：插入新结点后的二叉树的先、中、序遍历序列 
第九行：插入新结点后的二叉树的中序遍历序列(非递归算法) 
第十行：插入新结点后的二叉树的层次遍历序列 
第十一行~第十三行：第一次交换各结点的左右子树后的先、中、后序遍历序列 
第十四行~第十六行：第二次交换各结点的左右子树后的先、中、后序遍历序列 
第十七行：二叉树的深度 
第十八行：叶子结点数


输入样例
7
40 20 60 18 50 56 90
18
35
30


输出样例
40 20 18 60 50 56 90
18 20 40 50 56 60 90
18 20 56 50 90 60 40
1
0
40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
18 20 30 40 50 56 60 90
40 20 60 18 30 50 90 56

40 60 90 50 56 20 30 18
90 60 56 50 40 30 20 18
90 56 50 60 30 18 20 40

40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
4
4


作者 yqm
 
Version 1.0 | Designer：Chen Xiang-ji | © 2009-2018 Unlimited Studio
*/
