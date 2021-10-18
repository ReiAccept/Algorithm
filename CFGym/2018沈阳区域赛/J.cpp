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
const int MAXN=(int)1e5+3;
const int MOD=1e9+7;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();}//根据参数个数自动选择
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,cnt;
string s,typ,siz;

int pasersiz()
{
    int cur=0; while(siz[cur]!='[') cur++; cur++;
    int ans=siz[cur]-'0';
    for(int i=cur+1;siz[i]!=']';i++) ans=ans*10 + (siz[i]-'0');
    return ans;
}

int paserstr()
{
    int base=0; char c=typ[0];
    if(c=='i' || c=='f') base=4;
    else if(c=='b' || c=='c') base=1;
    else if(c=='_' || typ=="longdouble") base=16;
    else if(c=='d' || typ=="longlong") base=8;
    if(siz[siz.size()-2]==']')// 是否为数组
    {
        return base*pasersiz();
    }
    return base;
}

inline void work()
{
    cin>>n; int ans=0;
    for(int i=1;i<=n;i++)
    {
        //getline(cin,s);
        cin>>s;
        if(s=="long")
        {
            typ=s; 
            cin>>s;
            typ=typ+s;
        }
        typ=s;
        cin>>siz;
        ans+=paserstr();
        //cout<<"LOG: "<<ans<<endl;
    }
    int res=ans/1024;
    if(ans%1024) res++;
    cout<<"Case #"<<++cnt<<": "<<res<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//
    cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
/*
2
8
bool a;
char b;
int c;
long long d;
int128 e;
float f;
double g;
long double h;
1
int a[1000];
*/
