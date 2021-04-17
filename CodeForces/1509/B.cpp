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

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
string s;

void work()
{
    cin>>n>>s;int mx=0;
    stack<char> st;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='T')
        {
            st.push('T');
        }
        if(s[i]=='M' )
        {
            mx++;
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    while(mx--)st.pop();
    if(!st.empty())
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=(int)s.size()-1;i>=0;i--)
    {
        if(s[i]=='T')
        {
            st.push('T');
        }
        if(s[i]=='M' )
        {
            mx++;
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T;cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

