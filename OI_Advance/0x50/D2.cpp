//滚动数组优化版本
#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f,MOD=1e9+7;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

int l,n,ans=INF;
int p[1003]={3};//让p[0]作为起始点=3
int c[203][203];
int f[2][203][203];

void work()
{
    scanf("%d%d",&l,&n);//l=read();n=read();
    for(int i=1;i<=l;i++)
        for(int j=1;j<=l;j++) scanf("%d",&c[i][j]);//c[i][j]=read();
    for(int i=1;i<=n;i++) scanf("%d",p+i);//p[i]=read();
    mmst3f(f); f[0][1][2]=0;
    for(int i=0;i<n;i++)//p[0]已知为3,因此从0开始往i+1转移,然后得到结果
    {
        for(int x=1;x<=l;x++)
        {
            for(int y=1;y<=l;y++)
            {
                int z=p[i],nxt=p[i+1],now=f[i&1][x][y];
                if(x!=nxt && y!=nxt) f[(i+1)&1][x][y]=min(f[(i+1)&1][x][y],now+c[z][nxt]);//让z去
                if(z!=nxt && y!=nxt) f[(i+1)&1][z][y]=min(f[(i+1)&1][z][y],now+c[x][nxt]);//让x去
                if(x!=nxt && z!=nxt) f[(i+1)&1][x][z]=min(f[(i+1)&1][x][z],now+c[y][nxt]);//让y去
                f[i&1][x][y]=0x3f3f3f3f;
            }
        }
    }
    for(int x=1;x<=l;x++) 
        for(int y=1;y<=l;y++) 
        {
            //if(x==y || x==p[n] || y==p[n]) continue; //ans初始值==INF所以可以不用这句话
            if(f[n&1][x][y]<ans) ans=f[n&1][x][y];
        }
    cout<<ans<<endl;
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
