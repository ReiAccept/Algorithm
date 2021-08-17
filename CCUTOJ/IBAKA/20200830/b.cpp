#include<bits/stdc++.h>

using namespace std;

int n,maxn;
int a[300003],c[300003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    a[1]=c[1];
    a[2]=c[2]+c[1];
    maxn=max(a[1],a[2]);
    for(int i=3;i<=n;i++)
    {
        a[i]=c[i]+maxn;
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}
