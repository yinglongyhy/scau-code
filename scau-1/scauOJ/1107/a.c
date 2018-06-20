/*
在当前目录有文件“case1.in”，文件里存放有多个（总个数不超过10000个）英文单词（每个英文单词不会超过10个字文字符）， 每行一个，单词未排序。现要求，将文件中的所有单词按字典顺序排序，然后将排序好的单词写入新建的文件answer.txt中（注：文件存放于当前目录）。 请完成程序，实现该功能，（注意，填空题，请不要使用return 0结束，否则会影响评判而判错）
（如case1.in文件中原内容如下）
hello
bye
yes
（程序执行后，在文件answer.txt中内容如下）
bye
hello
yes
*/

#include <stdio.h>
#include <string.h> 

int main() 
{ 
	FILE *fp1, *fp2;
	int i = 0, j = 0, max;
	char ch, a[10000][11] = {"\0"}, word[11];
	fp1 = fopen("case1.in", "r");
	fp2 = fopen("answer.txt", "w");
	while(EOF != (ch = fgetc(fp1)))
	{
		i = 0;
		if('\n' == ch)
			continue;
		word[i++] = ch;
		while('\n' != (ch = fgetc(fp1)) && ch != EOF)
			word[i++] = ch;
		word[i] = '\0';
		strcpy(a[j++], word);
	}
	max = j;
	for(i = 0; i < max - 1; i++)
		for(j = 0; j < max - 1- i; j++)
			if(strcmp(a[j], a[j + 1]) > 0)
			{
				strcpy(word, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], word);
			}
	for(i = 0; i < max; i++)
	{
		fputs(a[i], fp2);
		fputs("\n", fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
} 
