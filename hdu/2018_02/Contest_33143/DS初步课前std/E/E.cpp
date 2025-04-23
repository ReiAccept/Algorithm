#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
typedef pair<int,int>P;
const int N=600010;
int Case;
int n,m,ce,i,x,y,z,v[N],f[N],g[N],ans[N];set<P>T;
struct E{int x,y,t;E(){}E(int _x,int _y,int _t){x=_x,y=_y,t=_t;}}e[N];
inline bool cmp(const E&a,const E&b){
  if(a.y!=b.y)return a.y>b.y;
  return a.x<b.x;
}
inline int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
inline void merge(int x,int y){
  x=F(x),y=F(y);
  if(x==y)return;
  f[x]=y,v[y]+=v[x];
}
int main(){
  scanf("%d",&Case);
  while(Case--){
  n=m=ce=i=x=y=z=0;
  memset(v,0,sizeof v);
  memset(f,0,sizeof f);
  memset(g,0,sizeof g);
  memset(ans,0,sizeof ans);
  T.clear();
  memset(e,0,sizeof e);
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&x,&y);
    x<<=1,y<<=1;
    e[++ce]=E(x,y,0);
  }
  scanf("%d",&m);
  for(i=1;i<=m;i++){
    scanf("%d%d",&x,&y);
    x<<=1,y<<=1;
    x++,y++;
    e[++ce]=E(x,y,i);
    f[i]=i;
  }
  sort(e+1,e+ce+1,cmp);
  for(i=1;i<=ce;i++){
    x=e[i].x,z=e[i].t;
    if(z){
      T.insert(P(x,z));
      set<P>::iterator it=T.find(P(x,z)),k=it;
      k++;
      if(k!=T.end())g[z]=k->second;
      while(1){
        k=T.find(P(x,z));
        if(k==T.begin())break;
        k--;
        if(k->second<z)break;
        T.erase(k);
      }
    }else{
      set<P>::iterator it=T.lower_bound(P(x,0));
      if(it!=T.end())v[it->second]++;
    }
  }
  for(i=m;i;i--){
    ans[i]=v[F(i)];
    if(g[i])merge(i,g[i]);
  }
  for(i=1;i<=m;i++)printf("%d\n",ans[i]);
  }
}