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

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)4e3+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

const int MAXS=4000*9+3;
int a,len,ans;
int si[MAXN],sum[MAXS];
char s[MAXN];

inline void work(int Case=1)
{
    scanf("%lld",&a);
    scanf("%s",s); len=strlen(s);
    for(int i=0;i<len;i++) si[i]=s[i]-'0';
    //sum[0]=si[0]; for(int i=1;i<len;i++) sum[i]=sum[i-1]+s[i]; //前缀和统计,暴力 N^4 太傻逼了
    for(int i=0;i<len;i++) {
        int cnt=0;
        for(int j=i;j<len;j++) {
            cnt+=si[j];
            sum[cnt]++; //假设全为最大值 9 那就是 4000*9=36000
        }
    }
    if(a==0) for(int i=0;i<MAXS;i++) ans+=sum[0]*sum[i];
    for(int i=1;i<MAXS;i++) {
        if(a%i==0 && a/i<=MAXS && a/i>=0) {
            ans+=sum[i]*sum[a/i];
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
//给定一个数字字符串s，定义矩阵b_{i,j} = S_i * S_j 
//问 b 矩阵中的矩形里各元素的和加起来等于 a 的有多少
