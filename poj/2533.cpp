#include<cstdio>
#include<cstdlib>
#include<iostream>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,maxn=-1;
int a[1003],f[1003];

void work()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i] && f[j]>=f[i])
                f[i]=f[j]+1;
        }
        if(f[i]>maxn)maxn=f[i];
    }
    printf("%lld\n",maxn);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
