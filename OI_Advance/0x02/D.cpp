#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef long double rld;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

bool g[5][5];

void turn(int x,int y)
{
    int dx[5]={
        0,1,-1,0,0
    },dy[5]={
        0,0,0,-1,1
    };
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0 && a<5 && b>=0 && b<5) g[a][b]^=1;
    }
}

void work()
{
    for(int tmp,i=0;i<5;i++)
    {
        tmp=read();
        for(int j=4;j>=0;j--)
        {
            g[i][j]=tmp%10;
            tmp/=10;
        }
    }
    int ans=INF;
    for(int k=0;k<(1<<5);k++)
    {
        int res=0,org[5][5];
        memcpy(org,g,sizeof(g));
        for(int j=4;j>=0;j--)
        {
            if((k>>j)&1)
            {
                turn(0,j);
                res++;
            }
        }
        for(int i=0;i<4;i++)
            for
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    signed T=read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

