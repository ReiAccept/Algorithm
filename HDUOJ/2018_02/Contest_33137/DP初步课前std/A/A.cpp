#include<cstdio>
typedef long long ll;
const int N=10005,K=12;
const ll inf=1LL<<60;
int Case,n,m,i,j,k,x,a[N];ll f[N][K][K][3],ans;
inline void up(ll&a,ll b){a<b?(a=b):0;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<=n;i++)for(j=0;j<=m;j++)for(k=0;k<=m;k++)for(x=0;x<3;x++)f[i][j][k][x]=-inf;
    f[0][0][0][0]=0;
    for(i=0;i<n;i++)for(j=0;j<=m;j++)for(k=0;k<=m;k++)for(x=0;x<3;x++){
      ll t=f[i][j][k][x];
      if(t==-inf)continue;
      if(x==0){
        //i+1<l，且不换入
        up(f[i+1][j][k][0],t);
        //i+1<l，但是换入
        if(j<m)up(f[i+1][j+1][k][0],t+a[i+1]);
      }
      if(x==0||x==1){
        //l<=i+1<=r，且不换出
        up(f[i+1][j][k][1],t+a[i+1]);
        //l<=i+1<=r，且换出
        if(k<m)up(f[i+1][j][k+1][1],t);
      }
      if(x==1||x==2){
        //i+1>r，且不换入
        up(f[i+1][j][k][2],t);
        //i+1>r，且换入
        if(j<m)up(f[i+1][j+1][k][2],t+a[i+1]);
      }
    }
    ans=-inf;
    for(j=0;j<=m;j++)for(x=1;x<3;x++)up(ans,f[n][j][j][x]);
    printf("%lld\n",ans);
  }
}