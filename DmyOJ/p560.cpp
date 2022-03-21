#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS puts("YES")
#define NOO puts("NO")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int ans1,ans2,r1,r2;
string s,t;
int cnt[10];

bool find(string &s,string &t) {
	int n=sz(s),m=sz(t),i=0;
	for(auto c:t) {
		while (i<n&&s[i]!=c) {
            cnt[s[i++]-'0']--;
        }
		if (i==n) {
            return false;
        }
		i++;
	}
	while(i<n) {
        cnt[s[i++]-'0']--;
    }
	for (int i=0;i<10;i++) {
        if (cnt[i]) {
            return false;
        }
    }
	return true;
}

void work(int CASE,bool FINAL_CASE)
{
    cin>>s>>t;
    int n=sz(s),m=sz(t);
    for (auto &x:s) {
        r1=r1*10+(x-'0');
    }
    for (auto &x:t) {
        r2=r2*10+(x-'0');
    }
    int ans1=r1,ans2=r2,now=__gcd(r1,r2);
    r1/=now; r2/=now;
    for (int j=0;j<1<<n;j++)
    {
        int r3=0,ctt=0;
        mmst0(cnt);
        for (int i=0;i<n;i++) {
            if (j>>i&1) {
                r3=r3*10+s[i]-'0';
            } else {
                cnt[s[i]-'0']++;
                ctt++;
            }
        }
        if (r3%r1||!r3||(__int128)r3/r1*r2>=1llu<<63) {
            continue;
        }
        ll r4=r3/r1*r2;
        string tar=to_string(r4);
        while (tar.size()+ctt<m) {
            tar='0'+tar;
        }
        if (r3<ans1&&find(t,tar)) {
            ans1=r3,ans2=r4;
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}
//nmd,wsm 又是一个我在赛场上没出的题，当时这题甚至没开没看题意