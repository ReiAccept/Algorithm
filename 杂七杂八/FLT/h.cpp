#include<cstdio>
#include<iostream>

using namespace std;

int ans,n;
int f[10003],a[10003];

bool check()
{
    for(int i=1;i<=n;++i)
        if(f[i]<a[i-1]+a[i]) return false;
        else if(f[i]==3&&a[i-1]+a[i]==1) return false;
        else if(f[i]==a[i-1]+a[i]) a[i+1]=0;
        else a[i+1]=1;
    return f[n]==a[n]+a[n-1];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&f[i]);
    a[1]=1;ans+=check();
    a[1]=0;ans+=check();
    printf("%d\n",ans);
    return 0;
}
