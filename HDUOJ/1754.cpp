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
const int maxn = 200000+10;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m,k;
char action;
int grade[maxn*2],segtree[maxn*2];
void build(int l,int r,int pos){
    if(r - l == 1){
        segtree[pos] = grade[l];
        return;
    } 
    int mid = (l+r)/2;
    build(l,mid,pos*2+1);
    build(mid,r,pos*2+2);
    segtree[pos] = max(segtree[pos*2+1],segtree[pos*2+2]);
}
void update(int id,int val){
    id += k-1;
    segtree[id] = val;
    while(id > 0){
        id = (id-1)/2;
        segtree[id] = max(segtree[id*2+1],segtree[id*2+2]);
    }
}
int query(int ql,int qr,int l,int r,int pos){
    if(ql >= r || qr <= l) return 0;
    if(ql <= l && qr >= r) return segtree[pos]; 
    int mid = (l+r)/2;
    return max(query(ql,qr,l,mid,pos*2+1), query(ql,qr,mid,r,pos*2+2));
}

void work()
{
    while(cin>>n>>m){
        k = 1;
        while(k < n) k*=2;
        mmst0(grade);
        for(int i=0;i<n;i++)grade[i]=read();
        build(0,k,0);
        for(int x,y,i=0;i<m;i++)
        {
            cin>>action;
            x=read()-1;y=read();
            if(action == 'Q') printf("%d\n",query(x,y,0,k,0));
            else update(x,y);
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

