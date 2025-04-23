/*
naive:
����״̬�����嵱�ҽ���a[i]==b[j]
f[i][j][0]=1+sum(f[x<i][y<j][1])
a[x]>a[i]
f[i][j][1]=sum(f[x<i][y<j][0])
a[x]<a[i]
O(n^4)

std:
g[i][j][k]��ʾ��f[i][j][k]��Ϊx,y����������ö��i
h[i][j][k]��ʾ����ö��j
f[i][j][k]->g[i+1][j][k]��ʾ��ʼö����һ��i
g[i][j][k]->g[i+1][j][k]��ʾi��������ö��
g[i][j][k]->h[i][j+1][k](a[i] opt b[j])��ʾ��ʼö��j
h[i][j][k]->h[i][j+1][k]��ʾj��������ö��
h[i][j][k]->f[i][j][k^1]��ʾֹͣö��
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