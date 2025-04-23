// Just for test this code

#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define PIS pair<int,string>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lowbit(x) (-x&x)
#define YESS puts("Yes")
#define NOO puts("No")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps=1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e5+3,MOD=(int)1e9+7;

inline int rnd(int x) {mt19937 mrand(random_device{}()); return mrand()%x;};
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

ll maxn,maxm,n,m,v,e,f,a[MAXN],b[MAXN],tree1[MAXN],tree2[MAXN];
struct node{
	ll l,r,a,b;
	bool operator<(const node &rhs)const{
		return l<rhs.l;
	}
}c1[MAXN],c2[MAXN];

void add1(ll x,ll v){
	while(x<=n)tree1[x]+=v,x+=lowbit(x);
}
void add2(ll x,ll v){
	while(x<=m)tree2[x]+=v,x+=lowbit(x);
}
ll query1(ll x){
	ll res=0;
	while(x)res+=tree1[x],x-=lowbit(x);
	return res;
}
ll query2(ll x){
	ll res=0;
	while(x)res+=tree2[x],x-=lowbit(x);
    return res;
}
inline void work(signed CASE=1,bool FINAL_CASE=false) {
	maxn=read(),maxm=read(),n=read(),m=read();
	for(int i=1;i<=n;i++){
		c1[i].l=a[i]=read(),c1[i].r=b[i]=read();
		if(!a[i]||a[i]==maxm)v--,e--;
		if(!b[i]||b[i]==maxm)v--,e--;
		if(((!a[i])&&(!b[i]))||(a[i]==maxm&&b[i]==maxm))n--,i--,e+=2,v+=2;
	}
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)c1[i].a=lower_bound(a+1,a+n+1,c1[i].l)-a,c1[i].b=lower_bound(b+1,b+n+1,c1[i].r)-b;
	for(int i=1;i<=m;i++){
		c2[i].l=a[i]=read(),c2[i].r=b[i]=read();
		if(!a[i]||a[i]==maxn)v--,e--;
		if(!b[i]||b[i]==maxn)v--,e--;
		if(((!a[i])&&(!b[i]))||(a[i]==maxn&&b[i]==maxn))m--,i--,e+=2,v+=2;
	}
	sort(a+1,a+m+1),sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)c2[i].a=lower_bound(a+1,a+m+1,c2[i].l)-a,c2[i].b=lower_bound(b+1,b+m+1,c2[i].r)-b;
	e+=1ll*(n+1)*(m+2)+1ll*(n+2)*(m+1),v+=1ll*(n+2)*(m+2);
	sort(c1+1,c1+n+1),sort(c2+1,c2+m+1);
	for(int i=1;i<=n;i++)add1(c1[i].b,1),v+=i-query1(c1[i].b),e+=2ll*(i-query1(c1[i].b));
	for(int i=1;i<=m;i++)add2(c2[i].b,1),v+=i-query2(c2[i].b),e+=2ll*(i-query2(c2[i].b));
	f=1-v+e;
	printf("%lld",f);
	return ;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        work(CASE,CASE==T);
        if(CASE!=T) {}
    }
    return 0;
}