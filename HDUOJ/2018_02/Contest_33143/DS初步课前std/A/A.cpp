#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2010;
int Case,n,i,j,x,ans,f[N],l[N],r[N],q[N],t;
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)f[i]=0;
    ans=0;
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        scanf("%d",&x);
        if(x)f[j]=0;else f[j]++;
      }
      for(q[t=0]=0,j=1;j<=n;q[++t]=j++){
        while(t&&f[q[t]]>=f[j])t--;
        l[j]=q[t]+1;
      }
      for(q[t=0]=n+1,j=n;j;q[++t]=j--){
        while(t&&f[q[t]]>=f[j])t--;
        r[j]=q[t]-1;
      }
      for(j=1;j<=n;j++)ans=max(ans,f[j]*(r[j]-l[j]+1));
    }
    printf("%d\n",ans);
  }
}