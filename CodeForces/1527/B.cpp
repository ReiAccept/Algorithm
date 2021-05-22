#include<bits/stdc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int N=(int)1e3+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
string s;

void work()
{
    cin>>n>>s; bool hw=true;int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++)if(s[i]=='0') cnt0++;
    for(int i=0;i<(n>>1);i++)
    {
        if(s[i]!=s[n-i-1]) hw=false;
        if((s[i]=='1' || s[n-1-i]=='1') && s[i]!=s[n-1-i]) cnt1++;
    }
    if(hw)
    {
        if(cnt0==1) cout<<"BOB"<<endl;
        else if(cnt0%2) cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
    }
    else
    {
        if(cnt0==2 && cnt1==1) cout<<"DRAW"<<endl;
        else cout<<"ALICE"<<endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    int T;cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

