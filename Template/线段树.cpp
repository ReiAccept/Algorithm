#include<cstdio>
#include<iostream>

using namespace std;

struct tree{
    int l,r;
    long long sum;
    long long add;
}tr[400003];

int n,m;
int a[100003];

void build_tree(int x,int y,int i)
{
    tr[i].l=x;
    tr[i].r=y;
    if(x==y) tr[i].sum=a[x];
    else
    {
        
    }
}

int main()
{
    scanf("%d%d",&n,&m)
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build_tree(1,n,1);
    return 0;
}































//自从来了大学，发现对于OI水平的提问每次都是:线段树会不会啊，这尼玛是高一学的啊==某谷水题啊
