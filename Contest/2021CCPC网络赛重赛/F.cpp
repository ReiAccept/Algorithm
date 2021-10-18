#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds; //If using pbds don't using std!
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;
const int MOD=998244353;
int read() { //fuck fread!!!!!!! ON HDOJ
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    return x*f;
}
/*
inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
*/
//int len,sum_a,len_p;
//int p[MAXN];
//char pfx[]=" nunhehheh";
//char s[MAXN];
int ans;
int dp[100010][10],pfx[100010];

int qpow(int a,int x){
	int res=1;
	while(x) {
		if(x&1) res=(res*a)%MOD;
		x>>=1;a=(a*a)%MOD;
	}
	return res;
}
char c[100010];

inline void work(int Case=1)
{
    int n=0;
    char x=getchar();
    ans=0;
    while(x!='\n') {
        c[++n]=x;
        x=getchar();
    }
    pfx[n+1]=0;
    for(int i=1; i<=8; i++) dp[0][i]=0;
    for(int i=n; i; i--) pfx[i]=pfx[i+1]+(c[i]=='a');
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=8; j++) dp[i][j]=dp[i-1][j];
        if(c[i]=='n') {
            dp[i][1]+=1;
            dp[i][3]+=dp[i-1][2];
        }
        else if(c[i]=='u') {
            dp[i][2]+=dp[i-1][1];
        }
        else if(c[i]=='h') {
            dp[i][4]+=dp[i-1][3];
            dp[i][6]+=dp[i-1][5];
            dp[i][7]+=dp[i-1][6];
            ans=(ans+dp[i-1][8]*(qpow(2,pfx[i])-1))%MOD;
        }
        else if(c[i]=='e') {
            dp[i][5]+=dp[i-1][4];
            dp[i][8]+=dp[i-1][7];
        }
        for(int j=1; j<=8; j++) dp[i][j]%=MOD;
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
