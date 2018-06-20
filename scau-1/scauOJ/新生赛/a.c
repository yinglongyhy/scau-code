#include <stdio.h>
void panduan(int a,int b,int num)
{
    int p[9]={0},c,d;
    loop:
        c=(a+b)/2;
        p[0]=c/10;
        p[1]=c/100;
        p[2]=c/1000;
        p[3]=c/10000;
        p[4]=c/100000;
        p[5]=c/1000000;
        p[6]=c/10000000;
        p[7]=c/100000000;
        p[8]=c;
        d=p[0]+p[1]+p[2]+p[3]+p[4]+p[5]+p[6]+p[7]+p[8];
        if(d==num)
        {
            printf("%d\n",c);
            return;
        }
		/*
        else if(d==num-1)
        {
            printf("-1\n");
            return;
        }
		*/
        else if(d<num)
        {
            b=c;
            goto loop;
        }
        else if(d>a)
        {
            a=c;
            goto loop;
        }
    }

int main()
{
    int y[9]={0},a,b,c,n,i,x,num=0;
    scanf("%d",&n);
    for(i=0,x=0;i<n;i++)
    {
		for(int j = 0; j < 9; j++) y[j] = 0;
        scanf("%d",&a);
        b=(a+x)/2+1;
        num=a;
        y[0]=b/10;
        y[1]=b/100;
        y[2]=b/1000;
        y[3]=b/10000;
        y[4]=b/100000;
        y[5]=b/1000000;
        y[6]=b/10000000;
        y[7]=b/100000000;
        y[8]=b;
        c=y[8]+y[0]+y[1]+y[2]+y[3]+y[4]+y[5]+y[6]+y[7];
        if(c==a)
        {
            printf("%d\n",c);
            continue;
        }
        else if(c==a-1)
        {
            printf("-1\n");
            continue;
        }
        else if(c<a)
        {
            //x=b;
            panduan(a,b,num);
        }
        else if(c>a)
        {
            a=c;
            panduan(a,b,num);
        }
    }
    return 0;
}
