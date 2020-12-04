//#include<bits/extc++.h>
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#define int long long
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int maxn=10010;
const int mod=1e9+7;
int C[maxn][105],dp[maxn],fac[maxn];

void INIT()
{
    fac[0]=fac[1]=dp[0]=dp[2]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=10000;i++) C[i][0]=1,fac[i]=i*fac[i-1]%mod;
    for(int i=3;i<=10000;i++) dp[i]=((i-1)*(dp[i-1]+dp[i-2])%mod)%mod;;
    for(int i=2;i<=10000;i++)
        for(int j=1;j<=i&&j<=100;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
}


void work()
{
    int ans=0,n=read(),k=read();
    for(int i=0;i<k;i++) ans=(ans+(C[n][i]*dp[n-i])%mod)%mod;
    cout<<(fac[n]-ans+mod)%mod<<endl;
    return;
}

signed main()
{
    INIT();
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
