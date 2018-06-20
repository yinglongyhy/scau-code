#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#define LENGHT 45

typedef struct link{
    //有头指针
    string ISBN;
    string bookname;
    string writer;
    string publisher;
    string date;
    int price;
    struct link *next;
}Link;

typedef struct statistics{
	string sort;
	int count;
	struct statistics *next;
}Statistics;

bool BuildRoot(Link *head);//创建管理员密码
bool ResetRoot(Link *head);//重设管理员密码
void EncryptedRoot(Link *head);//加密管理员密码
void DecryptedRoot(Link *head);//解密管理员密码
bool IsRoot(Link *head);//判断是否管理员
bool LinkCreat(Link *head);//创建链表
bool LinkInsert(Link *head, Link *q);//插入图书信息
bool LinkInput(Link *q);//输入书籍信息
bool Linkdelete(Link *head);//删除图书
bool LinkChange(Link *head);//修改图书信息
int ISBNOrNameOrPublisher();//ISBN为1  Name为2 Publisher为3
Link *LinkfindByISBN(Link *head);//通过ISBN查找图书位置的前驱
Link *LinkfindByName(Link *head);//通过字符串查找所有书名中包括该字符串的图书的信息的前驱
Link *LinkfindByPublisher(Link *head);//通过出版社名称查找书籍的前驱
void TitlePrint();//打印书籍基本数据类型
bool BookPrint(Link *p);//打印图书信息
bool BookShow(Link *head);//显示合适的图书信息
void Tearvser(Link *head);//遍历图书
bool IsInIt(Statistics *p, string &ch);//查找作者或出版社是否存在 存在就++
void StatisticsAdd(Statistics *head, int flag);//输出具体信息1、作者 0、出版社
void StatisticsIt(Link *head);//统计作者或出版社 
int getLenght(Statistics *head);//获取链表长度
bool Read(Link *head);//从文件读入内存
bool Write(Link *head);//从内存写入文件
bool Save(Link *head);//保存
bool menu(Link *head);//菜单
#endif
