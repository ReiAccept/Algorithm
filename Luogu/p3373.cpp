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

struct Node
{
    int val,add,mul=1;
} t[400003];

int p;
int a[100003];

void build_t(int root,int l,int r)
{
    t[root].mul=1,t[root].add=0;
    if(l==r) t[root].val=a[l]%p;
    else
    {
        int m=(l+r)>>1;
        build_t(root<<1,l,m);
        build_t(1+(root<<1),m+1,r);
        t[root].val=(t[root<<1].val+t[1+(root<<1)].val)%p;
    }
}

void push_down(int root,int l,int r)
{
    int m=(l+r)>>1;
    t[root<<1].val=(t[root<<1].val*t[root].mul+t[root].add*(m-l+1))%p;
    t[1+(root<<1)].val=(t[root<<1].val*t[root].mul+t[root].add*(r-m))%p;
    
    t[root<<1].mul=(t[root<<1].mul*t[root].mul)%p;
    t[1+(root<<1)].mul=(t[1+(root<<1)].mul*t[root].mul)%p;

    t[root<<1].add=(t[root<<1].add*t[root].mul+t[root].add)%p;
    t[1+(root<<1)].add=(t[1+(root<<1)].add*t[root].mul+t[root].add)%p;
    
    t[root].mul=1,t[root].add=0;
}

void up1(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].val=(t[root].val*k)%p;
        t[root].mul=(t[root].mul*k)%p;
        t[root].add=(t[root].add*k)%p;
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1;
    up1(root<<1,nowl,m,l,r,k);
    up1(1+(root<<1),m+1,nowr,l,r,k);
    t[root].val=(t[root<<1].val+t[1+(root<<1)].val)%p;
}

void up2(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].add=(t[root].add+k)%p;
        t[root].val=(t[root].val+k*(nowr-nowl+1))%p;
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1;
    up2(root<<1,nowl,m,l,r,k);
    up2(1+(root<<1),m+1,nowr,l,r,k);
    t[root].val=(t[root<<1].val+t[1+(root<<1)].val)%p;
}

ll query(int root,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return t[root].val;
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1;
    return (query(root<<1,nowl,m,l,r)+query(1+(root<<1),m+1,nowr,l,r))%p;
}

void work()
{
    int n=read();int m=read();p=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build_t(1,1,n);
    while(m--)
    {
        int op=read(),x=read(),y=read();ll k;
        if(op==1)
        {
            scanf("%lld",&k);
            up1(1,1,n,x,y,k);
        }
        else if(op==2)
        {
            scanf("%lld",&k);
            up2(1,1,n,x,y,k);
        }
        else
        {
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}

