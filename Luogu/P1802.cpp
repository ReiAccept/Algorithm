#include<cstdio>
#include<iostream>

using namespace std;

int n,x;
int f[1003],l[1003],w[1003],u[1003];

int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d%d%d",l+i,w+i,u+i);
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=u[i];j--) f[j]=max(f[j]+l[i],f[j-u[i]]+w[i]);
        for(int j=u[i]-1;j>=0;j--) f[j]+=l[i];
    }
    cout<<(long long)f[x]*5<<endl;
    return 0;
}
