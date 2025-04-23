/*
长为A，宽为B的矩阵放K个车的方案数=C(A,K)*C(B,K)*K!
建立笛卡尔树，那么左右儿子独立，设f[i][j]表示i子树内放j个车的方案数
合并左右儿子之后，枚举在底部矩形放几个车进行转移即可
时间复杂度O(n^3)
*/
#include<cstdio>
#include<cstring>
const int N=505,M=1000005,P=1000000007;
int Case,n,m,i,a[N],mx,fac[M],inv[M],g[N],f[N][N];
inline int cal(int a,int b,int k){
  if(a<k||b<k)return 0;
  return 1LL*fac[a]*inv[a-k]%P*inv[k]%P*fac[b]%P*inv[b-k]%P;
}
int dp(int l,int r,int h){
  if(l>r)return 0;
  int i,j,x=l;
  for(i=l;i<=r;i++)if(a[i]<a[x])x=i;
  int u=dp(l,x-1,a[x]),v=dp(x+1,r,a[x]);
  for(i=0;i<=r-l;i++)g[i]=0;
  for(i=0;i<=x-l;i++)if(f[u][i])for(j=0;j<=r-x;j++)
    g[i+j]=(1LL*f[u][i]*f[v][j]+g[i+j])%P;
  for(i=0;i<=r-l+1;i++)for(f[x][i]=j=0;j<=r-l&&j<=i;j++)
    f[x][i]=(1LL*g[j]*cal(r-l+1-j,a[x]-h,i-j)+f[x][i])%P;
  return x;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof a);
    memset(fac,0,sizeof fac);
    memset(inv,0,sizeof inv);
    memset(g,0,sizeof g);
    memset(f,0,sizeof f);
    for(mx=n,i=1;i<=n;i++)scanf("%d",&a[i]),mx=a[i]>mx?a[i]:mx;
    for(fac[0]=i=1;i<=mx;i++)fac[i]=1LL*fac[i-1]*i%P;
    for(inv[0]=inv[1]=1,i=2;i<=mx;i++)inv[i]=1LL*P/i*(P-inv[P%i])%P;
    for(i=2;i<=mx;i++)inv[i]=1LL*inv[i-1]*inv[i]%P;
    printf("%d\n",f[dp(f[0][0]=1,n,0)][m]);
  }
}