#include<bits/stdc++.h>

using namespace std;

int n,f[3000]={0,1,1};
bool v[1000000]={0,1};

int main()
{
    scanf("%d",&n);
    for(int i=3;i<=30;i++)
    {
        f[i]=f[i-1]+f[i-2];
        v[f[i]]=1;
    }
    for(int i=1;i<=n;i++)
        if(v[i]) printf("O");
        else printf("o");
}
