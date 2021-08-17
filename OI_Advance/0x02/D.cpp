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

char g[5][5],org[5][5];
int dx[]={
    -1,0,1,0,0
},dy[]={
    0,1,0,-1,0
};

void turn(int x,int y)
{
    for(int i=0;i<5;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<0 || a>4 || b<0 || b>4) continue;
    }
}

void work()
{
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    signed T=read();
    for(signed Case=1; Case<=T; Case++)
    {
        for (int i=0;i<5;i++) cin>>g[i];
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

