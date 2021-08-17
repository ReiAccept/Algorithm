#include<bits/stdc++.h>
#define int long long//__int128
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
const int N=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Node{
    int x,y,z;
    void rd(){
        x=read();y=read();z=read();
    }
    bool operator == (Node b)
    {
        if(x==b.x && y==b.y && z==b.z)return true;
        return false;
    }
}c[10],cx;

inline int fd(Node a,Node b)
{
    int x=abs(a.x-b.x),y=abs(a.y-b.y),z=abs(a.z-b.z);
    return x*x+y*y+z*z;
}

void work()
{
    bool fuck=false;
    map<int,int> m;
    cx.rd();
    for(int i=1;i<=7;i++)
    {
        c[i].rd();
        if(c[i]==cx)
        {
            fuck=true;
        }
        if(i>1)
        {
            for(int j=1;j<i;j++)
            {
                if(c[i]==c[j])
                {
                    fuck=true;
                }
            }
        }
        m[fd(cx,c[i])]++;
    }
    //cout<<"FUCK"<<endl;
    if(fuck)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(m.size()>3)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        int tr=0,one=0;
        for(auto it : m)
        {
            if(it.se == 3)tr++;
            if(it.se == 1)one++;
        }
        if(tr==2 && one==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

