#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#define int long long//__int128
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
const int MAXN=(int)3e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,cnt;
char s[MAXN];

void dfs(int now, int ji, int ou, bool flag)
{
    if(cnt==100) exit(0);
    if(n%2)
    {
        if(ji+(n-ji-ou) < (n>>1) || ou + (n-ji-ou) < (n>>1) || ji > (n>>1)+1 || ou > (n>>1)+1) return;
    }
    else
    {
        if(ji+(n-ji-ou) < (n>>1) || ou + (n-ji-ou) < (n>>1) || ji > (n>>1) || ou > (n>>1)) return;
    }
    if(now == n)
    {
        for(int i=1;i<=n-1;i++) printf("%c",s[i]);
        printf("\n");
        cnt++;
        return;
    }
    s[now]='b';
    if(flag) dfs(now+1,ji+1,ou,flag);
    else dfs(now+1,ji,ou+1,flag);
    s[now]='r'; //flag取反
    if(!flag) dfs(now+1,ji+1,ou,!flag);
    else dfs(now+1,ji,ou+1,!flag);
}

inline void work()
{
    n=read()+1; ll ans=((ll)n/2) * ((ll)n-(ll)n/2);
    printf("%lld\n",ans);
    dfs(1,0,1,false);
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
//构造一个长度为 n 的只含有 b,r 的字符串,使得子串中 r 数量为奇数的最多
//r 看成 1,b 看成 0 的话,前缀和中为奇数的子串就满足要求
