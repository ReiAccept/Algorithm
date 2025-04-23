// 孩子弃疗了，之前WA太多了
// 不想调了
#include<bits/stdc++.h>
#define mst(s,x) memset(s,x,sizeof(s));
#define sr(x) scanf("%lld",&x); 
#define sr2(a,b) scanf("%d%d",&a,&b); 
#define sr3(a,b,c) scanf("%d%d%d",&a,&b,&c); 
#define sr3d(a,b,c) scanf("%lf%lf%lf",&a,&b,&c); 
#define sr4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d);
#define f(i,a,n) for(int i=a;i<=n;i++)
#define ff(i) for(int i=1;i<=n;i++)
#define sc(x) cout<<#x<<" : "<<x<<endl;
#define hh cout<<endl;
//#define int __int128
#define pii pair<int,int>

#define mk(a,b) make_pair(a,b)
#define dd double
#define inf 0x3f3f3f3f
#define ll __int128
#define fi first
#define se second
using namespace std;
inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return w==1?x:-x;
}
inline void write(ll x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define int long long
//------------------------------------------------
const int N=2e6+5;
int pre[N];
int vis[N];
int cnt=1;
void get_pri()
{
	f(i,2,1e6+5)
	{
		if(!vis[i])pre[cnt++]=i;
		for(int j=i+i;j<=1e6+6;j=j+i) vis[j]=1;
	}
}
int x,k;
int ans[N];
const int mod=1e9+7;
int power(int a,int b)
{
	int ans1=1;
	while(b)
	{
		if(b&1) ans1=ans1*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans1;
}
int jc[N];
void get_jc()
{
	int now=1;
	jc[0]=1;
	f(i,1,1e6)
	{
		now=now*i%mod;
		jc[i]=now;
	}
}
int C(int a,int b)
{
	return jc[a]*power(jc[a-b],mod-2)%mod*power(jc[b],mod-2)%mod;
}
int p[N],m,c[N];
void divide(int n)
{
	m=0;
	f(i,2,sqrt(n))
	{
		if(n%i==0)
		{
			p[++m]=i,c[m]=0;
			while(n%i==0)n/=i,c[m]++;
		}
	}
	if(n>1)p[++m]=n,c[m]=1;
}
inline void solve()
{
	scanf("%lld%lld",&x,&k);
	int temp=x;
	divide(x);
	int ansi=1;
	f(i,1,m)
	{
		if(!c[i])continue;
		ansi=(ansi*C(c[i]+k-1,k-1))%mod;
	}
	ansi=ansi*power(2,k-1)%mod;
	printf("%lld\n",ansi);
	return;
}

//------------------------------------------------
signed main()
{
	clock_t c1=clock();
#ifdef LOCAL
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
//==================================
    int T=1;
	cin>>T;
	get_pri();
	get_jc();
	for(int i=1;i<=T;i++)
	{
		solve();
	}
//==================================
end:
    cerr<< "Time used:" << clock() - c1 << endl;
	return 0;
}