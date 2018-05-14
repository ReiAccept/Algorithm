/*
naive:
所有状态有意义当且仅当a[i]==b[j]
f[i][j][0]=1+sum(f[x<i][y<j][1])
a[x]>a[i]
f[i][j][1]=sum(f[x<i][y<j][0])
a[x]<a[i]
O(n^4)

std:
g[i][j][k]表示从f[i][j][k]作为x,y出发，正在枚举i
h[i][j][k]表示正在枚举j
f[i][j][k]->g[i+1][j][k]表示开始枚举下一个i
g[i][j][k]->g[i+1][j][k]表示i继续往后枚举
g[i][j][k]->h[i][j+1][k](a[i] opt b[j])表示开始枚举j
h[i][j][k]->h[i][j+1][k]表示j继续往后枚举
h[i][j][k]->f[i][j][k^1]表示停止枚举
*/
#include<cstdio>
const int N=2010,P=998244353;
int Case,n,m,i,j,k,t,a[N],b[N],g[N][N][2],h[N][N][2],ans;
inline void up(int&x,int y){x=x+y<P?x+y:x+y-P;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)scanf("%d",&b[i]);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<2;k++)g[i][j][k]=h[i][j][k]=0;
    for(ans=0,i=1;i<=n;i++)for(j=1;j<=m;j++)for(k=0;k<2;k++){
      if(a[i]==b[j]){
        t=h[i][j][k^1];
        if(!k)up(t,1);//new start
        if(t){
          up(ans,t);//update ans
          up(g[i+1][j][k],t);//new i
        }
      }
      if(g[i][j][k]){
        up(g[i+1][j][k],g[i][j][k]);//continue moving i
        if(!k){if(a[i]>b[j])up(h[i][j+1][k],g[i][j][k]);}//new j
        else if(a[i]<b[j])up(h[i][j+1][k],g[i][j][k]);//new j
      }
      if(h[i][j][k])up(h[i][j+1][k],h[i][j][k]);//continue moving j
    }
    printf("%d\n",ans);
  }
  return 0;
}