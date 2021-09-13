#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int m,s;
int a[103],b[103];

void work()
{
    m=read();s=read();//长度m,数位和为s
    if(s==0)
    {
        if(m==1)printf("0 0\n");
        else printf("-1 -1\n");
        return;
    }
    if(s/m>9)//s/m>9就说明即使全是九,数位和仍然小于n,无解 
    {
        printf("-1 -1\n");
        return;
    }
    if(s%m!=0 && s/m==9)//s不能整除m,则n/m=9(>=9)时,无法构成自然数
    {
        printf("-1 -1\n");
        return;
    }
    int j=0,l=0;
    while(l+9<=s)//要取最大数,就尽量让高位变大 
    {
        a[++j]=9;
        l+=9;
    }
    if(s-l) a[++j]=(s-l);
	j=0,l=1,b[m]=1;
    while(l+9<=s)//于最大值相反,让数位尽量变低位大
    {
        b[++j]=9;
        l+=9;
    }
    if(s-l) b[++j]+=(s-l);//注意，这里是+=，原因是当j=m时刚好取到最高位，而最高位已经付为1了
    for(int i=m;i>=1;i--)printf("%d",b[i]);
	printf(" ");
	for(int i=1;i<=m;i++)printf("%d",a[i]);
    printf("\n");
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
