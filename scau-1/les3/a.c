//判断小/中括号
#include <stdio.h>
int input(int n);
void panduan(int n, int i, char kuoHao[i][1000]);
int main()
{
	
	int n;
	int i;

	scanf("%d", &n);
	char kuoHao[n][1000];
	char * ptr_kuoHao = kuoHao;
	ptr_kuoHao = input(n);
	panduan(n, i, kuoHao);
	return 0;
}

int input(int n)
{
	int i;
	char kuoHao[n][1000];

	for(i = 0; i < n; i++)
	{
		scanf("%s", kuoHao[i]);	

	}
	char * ptr_kuoHao = kuoHao;
	return ptr_kuoHao;
}

void panduan(int n, int i, char kuoHao[i][1000])
{
	
	int j;
	for(i = 0; i < n; i++)
	{
		int k = 0;
		for(j = 0; j < 1000; j++)
		{
			if((kuoHao[i][j] == '(' && kuoHao[i][j + i] == ')') || (kuoHao[i][j] == '[' && kuoHao[i][j + 1] == ']'))
			{
				k++;
			}
		}
		if(k > 0)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
		printf("\n");
	}
}
