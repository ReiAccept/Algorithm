#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int a,b,c;
}a[53];

int T,n;
long long ans;
long long f[100003];

bool cmp(Node x,Node y)
{
    return x.c*y.b<y.c*x.b;
}

int main()
{
    scanf("%d%d",&T,&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].a);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].b);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].c);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        for(int j=T;j>=a[i].c;j--)
            ans=max(ans,f[j]=max(f[j-a[i].c]+a[i].a-(long long)j*a[i].b,f[j]));
    cout<<ans<<endl;
    return 0;
}
