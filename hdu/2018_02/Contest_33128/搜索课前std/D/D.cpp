//ÕÛ°ëËÑË÷
#include<cstdio>
#include<algorithm>
typedef long long ll;
int Case,n,lim,ca,cb,i,j;ll m,a[40],f[1111111],g[1111111],ans;
void dfsl(int x,ll y){
  if(y>m)return;
  if(x==lim){
    f[ca++]=y;
    return;
  }
  dfsl(x+1,y),dfsl(x+1,y+a[x]);
}
void dfsr(int x,ll y){
  if(y>m)return;
  if(x==n){
    g[cb++]=y;
    return;
  }
  dfsr(x+1,y),dfsr(x+1,y+a[x]);
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    ca=cb=j=ans=0;
    scanf("%d%lld",&n,&m);
    for(i=0;i<n;i++)scanf("%lld",&a[i]);
    lim=n/2;
    dfsl(0,0);
    dfsr(lim,0);
    std::sort(f,f+ca),std::sort(g,g+cb);
    for(i=ca-1;~i;i--){
      while(j<cb&&f[i]+g[j]<=m)j++;
      ans+=j;
    }
    printf("%lld\n",ans);
  }
}