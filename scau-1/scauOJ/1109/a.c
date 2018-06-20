#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct eng{
	char word[21];
	int count;
	struct eng *next;
};
struct eng *insert(struct eng *head, struct eng *p)
{
	if(head == NULL) return p;
	if(p -> count > head -> count || p -> count == head -> count && strcmp(p -> word, head -> word) < 0)
	{
		p -> next = head;
		head = p;
	}
	else
	{
		struct eng *p1, *p2;
		p1 = head;
		p2 = p1 -> next;
		while(p2 != NULL)
		{
			if(p2 -> count < p -> count || p2 -> count == p -> count && strcmp(p2 -> word, p -> word) > 0)
				break;
			p1 = p2;
			p2 = p2 -> next;
		}
		p -> next = p1 -> next;
		p1 -> next = p;
	}
	return head;
}
struct eng *choice(struct eng *head)
{
	if(head == NULL) return head;
	else if(head -> next == NULL) return head;
	struct eng *p1, *p2;
	p1 = head;
	p2 = p1 -> next;
	p1 -> next = NULL;
	while(p2 != NULL)
	{
		p1 = p2;
		p2 = p2 -> next;
		p1 -> next = NULL;
		head = insert(head, p1);
	}
	return head;
}
int main()
{
	FILE *fp;
	struct eng *head = NULL, *p1, *p2, *p3;//p1新节点 p2旧节点 p3判断节点
	char ch, news[21], cha;
	int i = 0, j = 0, LONG = 0;//LONG节点数
	int mark = 0;
	fp = fopen("case1.in", "r");
	while(EOF != (ch = fgetc(fp)))//读取单词
	{
		j = 0;
		if(ch >= 'A' && ch <= 'Z')	
			ch += 32;
		if('-' == ch)
		{
			if((ch = fgetc(fp)) == '\n')
				continue;
			if(ch >= 'a' && ch <= 'z')
			{
				cha = ch;
				ch = '\0';
				mark = 1;
			}
		}
		if(ch >= 'a' && ch <= 'z')
		{
			news[i++] = ch;
			continue;
		}
		news[i] = '\0';
		i = 0;
		if('\0' == news[0])
			continue;
		if(NULL == head)
		{
			p1 = (struct eng *)malloc(sizeof(struct eng));
			LONG++;
			strcpy(p1 -> word, news);
			p1 -> count = 1;
			p1 -> next = NULL;
			head = p1;
		}else{
				p3 = head;
			 	while(NULL != p3)
				{
					if(strcmp(p3 -> word, news) == 0)
					{
						p3 -> count++;
						j++;
						break;
					}
					p3 = p3 -> next;
				}
				if(0 == j)
				{
					p1 = (struct eng *)malloc(sizeof(struct eng));
					LONG++;
					p1 -> count = 1;
					p1 -> next = NULL;
					strcpy(p1 -> word, news);
					p2 -> next = p1;
				}
			 }
		p2 = p1;
		if(1 == mark)
		{
			news[i++] = cha;
			mark = 0;
		}
	}
	head = choice(head);
	/*
	for(i = 0; i < LONG - 1; i++)	//排序
		for(j = 0; j < LONG - 1 - i; j++)
		{
			if(0 == j)	
			{
				p2 = head;
				p1 = p2 -> next;
				if(p2 -> count < p1 -> count || p2 -> count == p1 -> count && strcmp(p2 -> word, p1 -> word) > 0)
				{
					p2 -> next = p1 -> next;
					p1 -> next = p2;
					head = p1;
					p2 = head;
					p1 = p2 -> next;
				}
			}else{
				 	p3 = p2;
					p2 = p1;
					p1 = p1 -> next;
					if(p2 -> count < p1 -> count || p2 -> count == p1 -> count && strcmp(p2 -> word, p1 -> word) > 0)
					{
						p2 -> next = p1 -> next;
						p1 -> next = p2;
						p3 -> next = p1;
					}
					p2 = p3 -> next;
					p1 = p2 -> next;
				 }
		}
		*/

	

	p1 = head; //打印
	i = 0;
	while(p1 != NULL)
	{
		printf("%s %d\n", p1 -> word, p1 -> count);
		p1 = p1 -> next;
		i++;
	}
	fclose(fp);
	return 0;
}
/*
1109 综合实验：文件操作与字符处理
时间限制:4000MS  内存限制:65536K
提交次数:6265 通过次数:1646

题型: 填空题   语言: GCC
Description
在当前目录中存在文件名为"case1.in"（其中case后为数字1，不是字母l，写错提交后会判错）的文本文件，
其内容为一篇英文文章（以EOF作为结束标志）。现要求读取该文本文件内容，统计文章中每个单词出现的次数，
并输出出现次数最多的前5个单词及其出现次数（按出现次数由多到少的顺序输出，次数相同时按字典顺序输出，
不足5个单词时，按序输出全部单词）。程序中注意如下细节：
（1）	空格、标点符号与回车符起到分隔单词的作用。
（2）	文章一行的末尾可能有连字符，出现连字符时，该行最末的字符串与下行最先出现的字符串构一个单词；
（3）	名词缩写算一个单词；
（4）	数字不算单词；
（5）	单词不区分大小写；
（6）	输出时单词全使用小写；

#include "stdio.h" 
#include "math.h" 
#include "string.h" 
#include "stdlib.h" 

_______________________ 

main() 
{ 
         _______________________ 
} 

输入格式
文件case1.in中一篇英文文章，包含多段文字，单词数不超过10000，每个单词不超过20个字符


输出格式
按题意输出答案


输入样例
（如case1.in内容如下） 
I am a student. My school is SCAU. It is a beau-
tiful university. I like it.


输出样例
a 2
i 2
is 2
it 2
am 1
*/
