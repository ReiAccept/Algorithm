/*
对于高度相同的一段可以合并
用链表从左往右维护这些连续段，每段维护以下信息：
l,r：表示区间的左右端点
t,a：表示在第t天结束时它的高度是a
b：当阳光在左边时它是否会长高
c：当阳光在右边时它是否会长高
令sa[i],sb[i]分别表示前i天中阳光在左/右边的天数
那么显然第i天这一段的高度为a+b*(sa[i]-sa[t])+c*(sb[i]-sb[t])
对于相邻的两段，根据其b和c，可以得出它们合并的时间
一天一天进行模拟，每天只处理那一天可能发生的合并事件，然后重新计算新的合并发生的时间即可
时间复杂度O(n+m)
*/
#include<cstdio>
#include<cstring>
const int N=300010,M=N*3;
int Case;
int n,m,ca,cb,i,j,k,T,h[N],tot;char b[N];
int sa[N],sb[N],ga[N],gb[N],gab[N],v[M],nxt[M],ed;
struct P{int l,r,pre,nxt,t,a;bool b,c,del;}e[N];
inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
inline void add(int&x,int y){v[++ed]=y;nxt[ed]=x;x=ed;}
inline int ask(const P&p){return p.a+p.b*(ca-sa[p.t])+p.c*(cb-sb[p.t]);}
inline void cal(P&p){
  p.b=ask(p)<ask(e[p.pre]);
  p.c=ask(p)<ask(e[p.nxt]);
}
inline void merge(int o);
inline void check(int o){
  P&p=e[o],&q=e[p.nxt];
  int x=ask(p),y=ask(q),z=x<y?y-x:x-y;
  if(!z)merge(o);
  bool fa=(x>y)^p.b,fb=(x<y)^q.c;
  if(fa&&fb){
    if(ca+cb+z<=m)add(gab[ca+cb+z],o);
    return;
  }
  if(fa){
    if(ca+z<=m)add(ga[ca+z],o);
    return;
  }
  if(fb){
    if(cb+z<=m)add(gb[cb+z],o);
    return;
  }
}
inline void merge(int o){
  P&p=e[o];
  if(p.del||!p.nxt)return;
  P&q=e[p.nxt];
  int x=ask(p),y=ask(q);
  if(x!=y)return;
  q.del=1;
  p.r=q.r;
  p.nxt=q.nxt;
  if(q.nxt)e[q.nxt].pre=o;
  p.t=T,p.a=x;
  cal(p);
  if(p.pre)check(p.pre);
  if(p.nxt)check(o);
}
int main(){
  read(Case);
  while(Case--){
  ca=cb=i=j=k=T=tot=0;
  memset(h,0,sizeof h);
  memset(b,0,sizeof b);
  memset(sa,0,sizeof sa);
  memset(sb,0,sizeof sb);
  memset(ga,0,sizeof ga);
  memset(gb,0,sizeof gb);
  memset(gab,0,sizeof gab);
  memset(v,0,sizeof v);
  memset(nxt,0,sizeof nxt);
  ed=0;
  memset(e,0,sizeof e);
  read(n),read(m);
  for(i=1;i<=n;i++)read(h[i]);
  for(i=1;i<=n;i=j){
    for(j=i;j<=n&&h[i]==h[j];j++);
    tot++;
    e[tot].l=i,e[tot].r=j-1;
    e[tot].a=h[i];
  }
  for(i=1;i<tot;i++)e[i].nxt=i+1;
  for(i=2;i<=tot;i++)e[i].pre=i-1;
  for(i=1;i<=tot;i++)cal(e[i]);
  for(i=1;i<tot;i++)check(i);
  scanf("%s",b+1);
  for(T=1;T<=m;T++){
    b[T]=='A'?ca++:cb++;
    sa[T]=sa[T-1]+(b[T]=='A');
    sb[T]=sb[T-1]+(b[T]=='B');
    for(j=ga[ca];j;j=nxt[j])merge(v[j]);
    for(j=gb[cb];j;j=nxt[j])merge(v[j]);
    for(j=gab[T];j;j=nxt[j])merge(v[j]);
    ga[ca]=gb[cb]=0;
  }
  for(i=1;i<=tot;i++)if(!e[i].del)for(k=ask(e[i]),j=e[i].l;j<=e[i].r;j++)h[j]=k;
  for(i=1;i<=n;i++)printf("%d%c",h[i],i<n?' ':'\n');
  }
  return 0;
}