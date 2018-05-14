/*
f[i][a][b][c]表示填了前i位，是否卡住n上界为a，是否卡住m上界为b，是否卡住k下界为c的方案数
g[i][a][b][c]表示填了前i位，是否卡住n上界为a，是否卡住m上界为b，是否卡住k下界为c的和
*/
#include<cstdio>
#define N 61
int T,P,i,j,k,l,x,y,A,B,C,a[N],b[N],c[N],f[N][2][2][2],g[N][2][2][2];long long n,m,K;
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int main(){
  for(scanf("%d",&T);T--;){
    scanf("%lld%lld%lld%d",&n,&m,&K,&P);
    for(i=0;i<N-1;i++)a[i]=n>>i&1,b[i]=m>>i&1,c[i]=K>>i&1;
    for(i=0;i<N;i++)
      for(j=0;j<2;j++)
        for(k=0;k<2;k++)
          for(l=0;l<2;l++)
            f[i][j][k][l]=g[i][j][k][l]=0;
    f[60][1][1][1]=1;
    for(i=60;i;i--)for(j=0;j<2;j++)for(k=0;k<2;k++)for(l=0;l<2;l++)if(f[i][j][k][l])
      for(x=j?a[i-1]:1;~x;x--)for(y=k?b[i-1]:1;~y;y--){
        if(l&&(x^y)<c[i-1])continue;
        A=j?x==a[i-1]:0;
        B=k?y==b[i-1]:0;
        C=l?(x^y)==c[i-1]:0;
        up(f[i-1][A][B][C],f[i][j][k][l]);
        up(g[i-1][A][B][C],(2LL*g[i][j][k][l]+(x^y)*f[i][j][k][l])%P);
      }
    printf("%d\n",((1LL*g[0][0][0][0]-1LL*K%P*f[0][0][0][0])%P+P)%P);
  }
  return 0;
}