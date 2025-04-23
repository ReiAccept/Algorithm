#include<cstdio>
const int N=100010,K=320,P=998244353;
int n,i,j,o,f[N],g[2][N],ans[N];
inline void up(int&a,int b){a=a+b<P?a+b:a+b-P;}
int main(){
  scanf("%d",&n);
  f[0]=1;
  for(i=1;i<K;i++)for(j=i;j<=n;j++)up(f[j],f[j-i]);
  for(i=0;i<=n;i++)g[0][i]=ans[i]=f[i];
  for(i=o=1;i<K;i++,o^=1){
    for(j=0;j<=n;j++){
      g[o][j]=0;
      if(j>=K)up(g[o][j],g[o^1][j-K]);
      if(j>=i)up(g[o][j],g[o][j-i]);
      up(ans[j],g[o][j]);
    }
  }
  for(i=1;i<=n;i++)printf("%d\n",ans[i]);
}