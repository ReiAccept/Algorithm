#include<cstdio>
#include<iostream>

using namespace std;

int n,M,T;
int m[1003],t[1003];
int f[1003][1003];

int main()
{
    scanf("%d%d%d",&n,&M,&T);
    for(int i=1;i<=n;i++) scanf("%d%d",&m[i],&t[i]);
    for(int i=1;i<=n;i++)
        for(int j=M;j>=m[i];j--)
            for(int k=T;k>=t[i];k--)
                f[j][k]=max(f[j][k],f[j-m[i]][k-t[i]]+1);
    cout<<f[M][T]<<endl;
    return 0;
}
