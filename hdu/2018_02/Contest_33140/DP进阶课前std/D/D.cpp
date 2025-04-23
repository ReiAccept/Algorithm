/*
������R��Ψһ���Կ�������ɫ������һά���е����
��f[i][j][k][x][y]��ʾ������ǰi��λ�ã���i��λ�õĸ߶���j����߸߶���k���Ѿ�����x��R��y����R�ķ�����
ת������Ҫôʹ�Լ��ĸ߶�+1��Ҫô������һ��λ��
�ɴ˿�����O(n^5)��ʱ����Ԥ�����g[i][j]����ʾһ������i��R��j����R�ķ�����
���ڶ�ά���������dp[i][j][k]��ʾ������ǰi�У�����j��R��k����R�ķ�������ö����һ��ת�Ƽ���
�����Ҫ������������ʣ��������ɫ�������
ʱ�临�Ӷ�O(n^5)
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=27,P=1000000007;
int Case,R,G,B,n,m,o,i,j,k,x,y,C[N*2][N*2],f[2][N][N][N][N*2],g[N][N*2],dp[N][N][N*2],ans;
inline void up(int&a,int b){a+=b;if(a>=P)a-=P;}
int cal(int R,int G,int B){return 1LL*dp[n][R][G+B]*C[G+B][G]%P;}
int main(){
  scanf("%d",&Case);
  while(Case--){
  scanf("%d%d%d%d",&R,&G,&B,&n);
  m=max(R,max(G,B));
  for(j=0;j<=m;j++)for(k=j;k<=m;k++)for(x=k;x<=m;x++)for(y=0;y<=m*2;y++){
    f[0][j][k][x][y]=0;
    f[1][j][k][x][y]=0;
  }
  memset(C,0,sizeof C);
  memset(g,0,sizeof g);
  memset(dp,0,sizeof dp);
  o=0;
  f[0][0][0][0][0]=1;
  for(i=0;i<n;i++,o^=1){
    for(j=0;j<=m;j++)for(k=j;k<=m;k++)
      for(x=k;x<=m;x++)for(y=0;y<=m*2;y++)f[o^1][j][k][x][y]=0;
    for(j=0;j<=m;j++)for(k=j;k<=m;k++)
      for(x=k;x<=m;x++)for(y=0;y<=m*2;y++)if(f[o][j][k][x][y]){
        up(f[o^1][0][k][x][y],f[o][j][k][x][y]);
        if(j==k)up(f[o][j+1][k+1][x+1][y],f[o][j][k][x][y]);
        else{
          up(f[o][j+1][k][x+1][y],f[o][j][k][x][y]);
          up(f[o][j+1][k][x][y+1],f[o][j][k][x][y]);
        }
      }
  }
  for(k=0;k<=m;k++)for(x=k;x<=m;x++)
    for(y=0;y<=m*2;y++)if(f[o][0][k][x][y])up(g[x][y],f[o][0][k][x][y]);
  for(C[0][0]=i=1;i<=m*2;i++)for(C[i][0]=j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
  dp[0][0][0]=1;
  for(i=0;i<n;i++)for(j=0;j<=m;j++)for(k=0;k<=m*2;k++)if(dp[i][j][k])
    for(x=0;j+x<=m;x++)for(y=0;y+k<=m*2;y++)
      up(dp[i+1][j+x][y+k],1LL*dp[i][j][k]*g[x][y]%P);
  ans=cal(R,G,B);
  up(ans,cal(G,R,B));
  up(ans,cal(B,R,G));
  printf("%d\n",ans);
  }
}