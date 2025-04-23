#include<bits/stdc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)50+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Point{
    int x,y;
};
int n,k,ans=INF;
int f[MAXN][MAXN],grap[50][50];
vector<Point> v[MAXN*MAXN];


inline int abs(int x)
{
    return x<0?-x:x;
}

inline int manhattan(int x1,int y1,int x2,int y2)
{
    return abs(abs(x1-x2)+abs(y1-y2));
}

inline void work()
{
    n=read();k=read();
    mmst3f(f);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            grap[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            (grap[i][j]==1) && (f[i][j]=0);
            (grap[i][j]==1 && k==1) && (ans=0);
            Point tmp={i,j};
            v[grap[i][j]].pb(tmp);
        }
    for(int x=1;x<k;x++)
        for(int i=0;i<(int)v[x].size();i++)
        {
            for(int j=0;j<(int)v[x+1].size();j++)
            {
                f[v[x+1][j].x][v[x+1][j].y]= min(f[v[x+1][j].x][v[x+1][j].y],f[v[x][i].x][v[x][i].y]+manhattan(v[x+1][j].x,v[x+1][j].y,v[x][i].x,v[x][i].y));
                (x==(k-1)) && (ans=min(ans,f[v[x+1][j].x][v[x+1][j].y]));
            }
        }
    printf("%d\n",(ans==INF?-1:ans));
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
