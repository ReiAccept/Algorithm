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

int n;
int len[105];
string str[105];

inline void work()
{
    cin>>n;
    //map<char,int> h;
    unordered_map<char,int> h; //注意这里用红黑树map会T
    map<char,bool> a;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        len[i]=(int)str[i].length();
        for(char c:str[i]) a[c]=true; //统计一共包含多少个字符
    }
    int maxround =len[0];
    for(int i=1;i<n;i++) maxround=len[i]*maxround/__gcd(len[i],maxround);
    string s;
    for(int i=0;i<maxround; i++) 
        for(int j=0;j<n;j++) s+=str[j][i%len[j]]; //第 j 个字符串中取第 i % len[j] 位
    s+=s; //cout<<s<<endl;
    maxround*=2*n;
    int cnt=0,l=0,r=INF,ans=INF;
    for(int i=0;i<maxround;i++) //寻找右侧指针的起始点
    {
        if(h[s[i]]++ == 0) cnt++; //找出所有字符种数
        if(cnt == (int)a.size()) 
        {
            r=i+1; //处理右侧指针的起始点
            ans=r;
            break;
        }
    }
    while(r < maxround && l<maxround/2)
    {
        while(--h[s[l]]) ++l; //左指针寻找一个 h[s[l]]==1 的,然后 --h[s[l]]之后等于0就跳出,如果非0的话，证明后面还有好几个同样的字符,可以继续向后减
        ans=min(ans,r-l);
        while(r < maxround && ++h[s[r]])
        {
            r++;
            if(h[s[l]]) //补充外层循环被删去的 s[l] 计数
            {
                ++l; //左指针右移
                break;
            }
        }
    }
    cout<<ans<<endl;
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
