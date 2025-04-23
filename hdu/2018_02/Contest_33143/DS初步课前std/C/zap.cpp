/*
f[i]=max(t[i],f[i-1]+d)
f[0]=0

3 10 12 23
[                       ]       [                ]

对于每个f[i]=t[i]的，计算f[i]-f[i-1]
当d>f[i]-f[i-1]时，merge it

d>=(a[x]-a[pre])/(x-pre)
*/
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
const int N=200010;
int Case;
int n,m,i,x,y,k,b[N],q[N],lim,pre[N],nxt[N],w[N];ll a[N],ans[N],cur,cnt;
priority_queue<P,vector<P>,greater<P> >Q;
inline bool cmp(int x,int y){return b[x]<b[y];}
inline ll ask(ll a,ll b){return a/b+(a%b>0);}
inline ll cal(int x){return ask(a[x]-a[pre[x]],x-pre[x]);}
inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
inline void read(ll&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
int main(){
  read(Case);
  while(Case--){
  memset(b,0,sizeof b);
  memset(q,0,sizeof q);
  lim=0;
  memset(pre,0,sizeof pre);
  memset(nxt,0,sizeof nxt);
  memset(w,0,sizeof w);
  memset(a,0,sizeof a);
  memset(ans,0,sizeof ans);
  cur=cnt=0;
  while(!Q.empty())Q.pop();
  read(n),read(m);
  for(i=1;i<=n;i++)read(a[i]);
  for(i=1;i<=m;i++)read(b[i]),q[i]=i;
  for(i=0;i<n;i++)nxt[i]=i+1;
  for(i=1;i<=n;i++)pre[i]=i-1,Q.push(P(a[i]-a[i-1],i));
  for(i=0;i<=n;i++)w[i]=1;
  sort(q+1,q+m+1,cmp);
  for(i=1;i<=m;i++){
    lim=b[q[i]];
    while(!Q.empty()){
      P t=Q.top();
      if(t.first>lim)break;
      Q.pop();
      x=t.second;
      if(!w[x])continue;
      if(cal(x)!=t.first)continue;
      k=w[x];
      cur-=1LL*k*a[x];
      cnt-=1LL*k*(k-1);
      y=pre[x];
      k=w[y];
      cur-=1LL*k*a[y];
      cnt-=1LL*k*(k-1);
      w[y]+=w[x];
      w[x]=0;
      k=w[y];
      cur+=1LL*k*a[y];
      cnt+=1LL*k*(k-1);
      nxt[y]=x=nxt[x];
      if(!x)continue;
      pre[x]=y;
      Q.push(P(cal(x),x));
    }
    ans[q[i]]=cur+cnt/2*lim;
  }
  for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
  }
}