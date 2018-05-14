#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct qwq
{
    long long xh;
    string name;
    double df;
} a[103];

int n;

bool cmp(qwq x,qwq y)
{
    if(x.df==y.df)
        return x.xh>y.xh;
    else
        return x.df>y.df;
}

void pjf(int x)
{
    double ans,mdzz,maxx=0,minx=999;
    for(int i=1; i<=10; i++)
    {
        cin>>mdzz;
        minx=min(minx,mdzz);
        maxx=max(maxx,mdzz);
        ans+=mdzz;
    }
    ans=ans-minx-maxx;
    a[x].df=ans/8.00;
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].xh>>a[i].name;
        pjf(i);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<a[i].xh<<" "<<a[i].name<<" ";
        printf("%.2lf",a[i].df);
        if(i!=n)
            printf("\n");
    }
    return 0;
}
