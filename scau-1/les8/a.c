#include <stdio.h>
#include <stdlib.h>
int main()
{
	char ch;
	FILE *fp1, *fp2;

	fp1 = fopen("filel1.txt", "r");
	fp2 = fopen("filel2.txt", "w");
	if(NULL == fp1)
	{
		printf("filel1.txt open error!\n");
		exit(0);
	}
	while(EOF != (ch = fgetc(fp1)))
	{
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("copy success!");
	return 0;
}



