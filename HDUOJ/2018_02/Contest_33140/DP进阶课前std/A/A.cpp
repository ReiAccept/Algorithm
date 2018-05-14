#include<cstdio>
#include<cstring>
const int N=3010,M=500010,S=26;
int Case,n,m,i,j,g[M][S],f[N][N];char a[N],b[M];
inline void up(int&a,int b){a>b?(a=b):0;}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1),m=strlen(b+1);
    for(i=1;i<=n;i++)a[i]-='a';
    for(i=1;i<=m;i++)b[i]-='a';
    for(j=0;j<S;j++)g[m+1][j]=m+1;
    for(i=m;i;i--){
      for(j=0;j<S;j++)g[i][j]=g[i+1][j];
      g[i][b[i]]=i;
    }
    for(i=0;i<=n;i++)for(j=0;j<=n;j++)f[i][j]=m+1;
    up(f[0][0],0);
    for(i=0;i<n;i++)for(j=0;j<=n;j++)if(f[i][j]<=m){
      up(f[i+1][j],f[i][j]);
      up(f[i+1][j+1],g[f[i][j]+1][a[i+1]]);
    }
    for(j=n;~j;j--)if(f[n][j]<=m)break;
    printf("%d\n",j);
  }
}