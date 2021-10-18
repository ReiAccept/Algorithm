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

string s[10];
const char dot='.';

inline void work()
{
    for(int i=0;i<3;i++) cin>>s[i];
    bool flag=true;
    for(int i=0;i<3;i++) {
        if(s[i][1]== s[i][0] && s[i][1]==s[i][2] && s[i][1]!=dot) {
            cout<<s[i][1]<<endl;
            return ;
        }
        else if(s[0][i]==s[1][i] && s[1][i]==s[2][i] && s[1][i]!=dot) {
            cout<<s[1][i]<<endl;
            return ;
        }
        else if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && s[1][1]!=dot) {
            cout<<s[1][1]<<endl;
            return ;
        }
        else if(s[1][1]==s[0][2] && s[1][1]==s[2][0] && s[1][1]!=dot) {
            cout<<s[1][1]<<endl;
            return ;
        }
    }
    cout<<"ongoing"<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//
    cin>>T;
    for(signed Case=1; Case<=T; Case++) {
        //printf("Case %d: ",Case);
        //while(cin>>n) work(n);
        work();
    }
    return 0;
}
