#include <stdio.h>
int i;
void input(char *p[20])
{
	printf("请输入一个字符串：\n");
	for(i = 0; i < 3; i++)
	{
		scanf("%s", p);
	}
}

int main()
{
	char ch[3][20];
	input(ch);
	for(i = 0; i < 3; i++)
	{
		printf("你输入的是：%s\n", ch[i]);
	}
	return 0;
}
