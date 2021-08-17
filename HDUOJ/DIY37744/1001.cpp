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
const int MAXN=(int)1e5+3;

//int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

char a[20][20];
bool vis[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int n, m, t;
int sx, sy, ex, ey;
bool flag;
void dfs(int x, int y, int step)
{
	if(x==ex && y==ey && step==t)flag=true;
	if(step>t || flag)return;
	if(abs(t-step-abs(x-ex)-abs(y-ey))%2)return;
	for(int i = 0; i < 4; i++)
    {
		int nx = x+dx[i], ny = y+dy[i];
		if(nx>=1&&nx<=n &&ny>=1&&ny<=m &&!vis[nx][ny]&&a[nx][ny]!='X')
        {
			vis[nx][ny] = true;
			dfs(nx,ny,step+1);
			vis[nx][ny] = false;
		}
	}
}

void work()
{
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
            {
				cin>>a[i][j];
				if(a[i][j]=='S')sx=i,sy=j;
				if(a[i][j]=='D')ex=i,ey=j;
			}
		flag = false,vis[sx][sy] = true;
		dfs(sx,sy,0);
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	return;
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        while(cin>>n>>m>>t &&n&&m&&t)
            work();
    }
    return 0;
}
