#include<cstdio>
typedef long long ll;
const int N=500010;
int Case,n,K,i,a[N],pos[N],pre[N],nxt[N];
ll ans;
inline void del(int i){
  pre[nxt[i]]=pre[i];
  nxt[pre[i]]=nxt[i];
}
inline ll solve(int x){
  static int a[100],b[100];
  int i,ca=0,cb=0;
  for(i=x;i;i=pre[i]){
    a[++ca]=i-pre[i];
    if(ca==K)break;
  }
  for(i=x;i<=n;i=nxt[i]){
    b[++cb]=nxt[i]-i;
    if(cb==K)break;
  }
  ll t=0;
  for(i=1;i<=ca;i++)if(K-i+1<=cb)t+=1LL*a[i]*b[K-i+1];
  return t;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
    for(i=0;i<=n+1;i++)pre[i]=i-1,nxt[i]=i+1;
    pre[0]=0;
    nxt[n+1]=n+1;
    ans=0;
    for(i=1;i<=n;i++){
      int x=pos[i];
      ans+=solve(x)*i;
      del(x);
    }
    printf("%I64d\n",ans);
  }
}