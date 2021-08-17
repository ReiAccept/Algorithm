#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int f[20][20];

int work(int n,int ans=0)
{
    for(int i=1; i<=n; i++)
    {
        int wei=i%10,tou=i;
        while(tou>=10)tou/=10;
        f[tou][wei]++;
    }
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
            ans=ans+f[i][j]*f[j][i];
    return ans;
}

signed main()
{
    int T=1;
	for(int Case=1;Case<=T;Case++) printf("%d\n",work(read()));
    return 0;
}
