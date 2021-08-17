#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;
const int MANX=1003;

int read()
{
    char c;
    int num,f=1;
    while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
    num=(int)(c-'0');
    while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
    return num*f;
}
void prt(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)prt(x/10);
    putchar((char)(x%10+'0'));
}

int p[MANX][4];
double dp[MANX];
int n=0,t=0;
double res=0.0;

void work()
{
    n=read();
    t=read();
    for(int i=1; i<=n; i++)
    {
        p[i][3]=read();
        p[i][2]=read();
        p[i][1]=read();
    }
    for(int pn,s,i=1; i<=t; i++)
    {
        pn=read();
        s=read();
        res+=(double)p[pn][s]*(double)s;
        dp[i]=(double)s*((double)p[pn][1]-(double)p[pn][s]);
    }
    sort(dp+1,dp+1+t);
    for(int i=1; i<=6; i++) if(dp[i]<0) res+=dp[i];
    cout<<res/(double)100<<endl;
    return;
}

signed main()
{
    int T=1;//read();
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
