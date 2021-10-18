#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define Max 100005
using namespace std;
int n,m,a;
int step[505][505];
int prime[Max];
void IsPrime()//素数打表模板
{
	int i;
     prime[0]=prime[1]=0;
     prime[2]=1;
     for( i=3;i<=Max;i++)
        prime[i]=i%2==0?0:1;
     int t=(int)sqrt(Max*1.0);
     for( i=3;i<=t;i++)
       if(prime[i])
         for( int j=i*i;j<Max;j+=2*i)//优化
            prime[j]=0;
}
int f(int n)
{
    if(prime[n]==1)
        return 0;
    else
        for(int i=n;i<=100005;i++)
            if(prime[i]==1)
                return i-n;
}
int main()
{
    IsPrime();
//    for(int i=1;i<=100;i++)
//        printf("i=%d %d\n",i,prime[i]);//我用来检验打表情况
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(step,0,sizeof(step));
        int i,j;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                {
                    scanf("%d",&a);
                    step[i][j]=f(a);
                }
        int sum,Min;
        sum=0; Min=99999999;
        for(i=1;i<=n;i++)//横着遍历一遍

        {
            sum=0;
            for(j=1;j<=m;j++)
                sum+=step[i][j];
            if(sum<Min)
                Min=sum;
        }
        for(j=1;j<=m;j++)//竖着遍历一遍
        {
            sum=0;
            for(i=1;i<=n;i++)
                sum+=step[i][j];
            if(sum<Min)
                Min=sum;
        }
        printf("%d\n",Min);
    }
    return 0;
}

