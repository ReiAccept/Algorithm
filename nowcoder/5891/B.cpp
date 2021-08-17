#include<cstdio>
#include<iostream>

using namespace std;
#define ll long long

void exgcd(int a,int b,int &d,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        d=a;//d==gcd(a,b);
        return ;
    }
    exgcd(b,a%b,d,x,y);
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}
void fun(int a,int b,int c,int &x,int &y)
{
    int d;
    exgcd(a,b,d,x,y);
    if(c%d) return ;
    while(x<0)//求最小的非负数
    {
        x+=b;
        y-=a;
    }
    cout<<x<<endl;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    int a,b,x,y;
    while(T--)
    {
        scanf("%d%d",&a,&b);
        if(gcd(a,b)==1) fun(a,b,1,x,y);
        else printf("-1\n");
    }
    return 0;
}
