#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

const int MAXN=1001; 
const int INF=0x7ffff;

int map[MAXN][MAXN];
int a[MAXN][MAXN];
int xx[5]={-1,+1,0,0};
int yy[5]={0,0,-1,+1};
int n,m,ans;
bool flag;
int vis[MAXN][MAXN];

void dfs(int nowx,int nowy,int val)
{
    if(nowx==n && nowy==m)    
	{ 
		flag=true;
		return; 
	}
    for(int i=0;i<4;i++)
    {
        int wx=nowx+xx[i];
        int wy=nowy+yy[i];
        if(map[wx][wy]>=val && a[wx][wy]==0 && wx>0 && wy>0 && wx<=n && wy<=m && vis[wx][wy]==0)
        {
            vis[wx][wy]=1;
            dfs(wx,wy,val);
            vis[wx][wy]=0;
            if(flag==true)    
				return;
        }
    }
}

bool check(int val)
{
    flag=false;
    vis[1][1]=1;
    dfs(1,1,val);
    if(flag==true)    
		return true;
	else 
		return false;    
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            map[i][j]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j])
                map[i][j]=INF;
            else
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=m;l++)
                        if(a[k][l])
                            map[i][j]=min(map[i][j],abs(k-i)+abs(l-j));
    int l=0,r=(n*m);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))    
		{
			l=mid+1;
			ans=mid;
		}
        else 
			r=mid-1;
    }
    printf("%d",ans);
    return 0;
}
