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
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int tr[MAXN<<3];
int n,N=1;

void build(){
    scanf("%d",&n);
    while(N<=n+1) N<<=1; //zkw的缺点,一定是一颗满二叉树,一定程度上是用空间来换了时间
    for(int i=N+1;i<=N+n;i++) scanf("%d",&tr[i]);
    for(int i=N-1;i>=1;i--) tr[i]=tr[i<<1]+tr[i<<1 | 1];
}

void modify(int pos,int v){
    for(pos+=N;pos;pos>>=1) tr[pos]+=v;
}

int querySingle(int pos){
    return tr[pos];
}

void work()
{
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}