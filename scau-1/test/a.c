/*
描述 输入x(x为整数)，求函数值F(x)
函数定义如下：
F(x)=x          	         x小于2
G(x)=x          	         x小于2
F(x)=G(x/2)*2   	         x大于等于2且x为偶数
F(x)=G((x-1)/2)   	         x大于等于2且x为奇数
G(x)=G(x/2)+1   	         x大于等于2且x为偶数
G(x)=x          	         x为奇数

输入样例 10
输出样例 10
*/
#include <stdio.h>
int G(int x);
int F(int x)
{
	if(x < 2)
		return x;
	if(x >= 2 && x % 2 == 0)
		return G(x / 2) * 2;
	if(x >= 2 && x % 2 == 1)
		return G((x - 1) / 2);
}

int G(int x)
{
	if(x < 2 || x % 2 == 1)
		return x;
	if(x >= 2 && x % 2 == 0)
		return G(x / 2) + 1;
}
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", F(x));
	return 0;
}
