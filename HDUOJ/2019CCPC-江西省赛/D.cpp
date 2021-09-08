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
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,c;
int a[MAXN];
int dp[MAXN][103],nx[MAXN]; 
//dp[i][j]-> i 第几个位置 j-> 字符 c 是什么数

inline void work()
{
    while(cin>>n>>c)
    {
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=c;i++) dp[n+1][i]=nx[i]=n+1;
        for(int i=n;i>=0;i--)
        {
            for(int j=1;j<=c;j++)
            {
                dp[i][j]=nx[j];
                if(i)nx[a[i]]=i;
            }
        }
        int res=0; 
        for(int i=1;i<=c;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(i!=j)
                {
                    int tmp=0,cur=0;
                    while(cur<=n)
                    {
                        cur=dp[cur][i];
                        if(cur<=n) tmp+=1;
                        else break;
                        cur=dp[cur][j];
                        if(cur<=n) tmp+=1;
                        else break;
                    }
                    res=tmp>1?max(res,tmp):res;
                }
            }
        }
        cout<<res<<endl;
    }
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
