#include<cstdio>
#include<iostream>

using namespace std;

int t,n,k,MOD=8388608;
int c[100003][24];

void Init()
{
    c[0][0]=1;
    for(int i=1;i<=100000;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=min(i,23);j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
}

int main()
{
    Init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        long long ans=0;
        for(int i=1;i<=min(k,23);i++)
            ans=(long long)(ans+(long long)c[n][i]*i*(1<<(i-1)))%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
