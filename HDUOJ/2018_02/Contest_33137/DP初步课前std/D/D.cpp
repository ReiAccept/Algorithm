#include<cstdio>
#include<cstring>
const int N=10,M=1050,P=998244353;
int Case,n,m,h,i,j,S,x,y,w,ans;char g[N][M];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
namespace ODD{
int f[M][1<<N][2][2];
void solve(){
  memset(f,0,sizeof f);
  f[0][(1<<n)-1][0][0]=1;
  for(i=1;i<=m;i++)for(S=0;S<(1<<n);S++)
    for(x=0;x<2;x++)for(y=0;y<2;y++)if(f[i-1][S][x][y]){
      w=f[i-1][S][x][y];
      up(f[i][S][x][0],w);
      if(!y)for(j=0;j<n;j++)if(S>>j&1)if(g[j][i]=='1')
        up(f[i][S^(1<<j)][x|(i==1)][1],w);
    }
  for(x=0;x<2;x++)for(y=0;y<2;y++)if(!x||!y)up(ans,f[m][0][x][y]);
}
}
namespace EVEN{
int f[M/2][1<<N][3][3];
void solve(){
  memset(f,0,sizeof f);
  f[0][(1<<n)-1][0][0]=1;
  for(i=1;i<=h;i++)for(S=0;S<(1<<n);S++)
    for(x=0;x<3;x++)for(y=0;y<3;y++)if(f[i-1][S][x][y]){
      w=f[i-1][S][x][y];
      up(f[i][S][x][0],w);
      for(j=0;j<n;j++)if(S>>j&1){
        if(g[j][i]=='1'&&y!=1)up(f[i][S^(1<<j)][x|(i==1)][1],w);
        if(g[j][i+h]=='1'&&y!=2)up(f[i][S^(1<<j)][x|((i==1)*2)][2],w);
      }
    }
  for(x=0;x<3;x++)for(y=0;y<3;y++)if(x+y!=3)up(ans,f[h][0][x][y]);
}
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    memset(g,0,sizeof g);
    ans=0;
    scanf("%d%d",&n,&m);h=m/2;
    for(i=0;i<n;i++)scanf("%s",g[i]+1);
    if(m&1)ODD::solve();else EVEN::solve();
    printf("%d\n",ans);
  }
}