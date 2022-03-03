#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)5e3+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

// struct node{
//     int to,next;
// }a[MAXN<<1];
// int tot,ls[MAXN];
struct line{
    int x,y;
}l[MAXN<<1];
int n,m,t,in[MAXN],state[MAXN],w[MAXN],ans[MAXN],x,y,q[MAXN];
bool k[MAXN][MAXN],v[MAXN];
vector<int> grap[MAXN<<1];
void addl(int x,int y)//加边
{
    // a[++tot].to=y;
    // a[tot].next=ls[x];
    // ls[x]=tot;
    grap[x].pb(y);
    in[y]++;
}

bool topsort(){
    int l=0,r=0;
    for (int i=1;i<=n;i++) 
      if(in[i]==1) q[++r]=i;
    while(l<r) {
        int now=q[++l];
        // for (int i=ls[now];i;i=a[i].next){
        for(auto y: grap[now]) {
            // int y=a[i].to;
            if(in[y]>1){
                in[y]--;
                if(in[y]==1) q[++r]=y;
            }
        }
    }
    if(r==n) return true;
    return false;
}//拓扑求环
bool cmp(line x,line y)
{return x.y>y.y;}
void dfs(int x)//走一遍
{
    state[++t]=x;
    v[x]=true;
    // for(int i=ls[x];i;i=a[i].next)
    for(auto y:grap[x])
    {
        // int y=a[i].to;
        if(k[x][y]||v[y]) continue;
        dfs(y);
    }
}
void check()//判断是否为更小字典序
{
    int i;
    bool flag=false;
    for(i=1;i<=n;i++)
      if(state[i]<ans[i])
      {flag=true;break;}
      else if(state[i]>ans[i]) return;
    if(!flag) return;
    for(;i<=n;i++)
      ans[i]=state[i];
}
void get_ans(int xs)//暴力删边
{
    int x=xs,b=0,i,last=0;
    do
    {
        w[++b]=x;
        in[x]=1;
        // for(i=ls[x];i;i=a[i].next)
        for(auto y : grap[x])
        {
            // int y=a[i].to;
            if(in[y]>1)
            {x=y;break;}
        }
    }while(i);//记录环的每个点
    w[++b]=xs;
    for(int i=1;i<b;i++)//枚举删除的边
    {
        k[w[i]][w[i+1]]=k[w[i+1]][w[i]]=true;
        memset(v,0,sizeof(v));
        t=0;
        dfs(1);
        check();
        k[w[i]][w[i+1]]=k[w[i+1]][w[i]]=false;
    }
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    memset(ans,127/3,sizeof(ans));
    n=read(); m=read();
    for(int i=1;i<=m;i++) {
        l[i]=(line){x=read(),y=read()};
        l[i+m]=(line){y,x};
    }
    sort(l+1,l+1+2*m,cmp);//排序
    // tot=1;
    for(int i=1;i<=2*m;i++)//加边
    {addl(l[i].x,l[i].y);}
    if(m==n-1)//普通的树
    {
        dfs(1);
        for(int i=1;i<=n;i++)
            printf("%d ",state[i]);
        return ;
    }
    topsort();
    for(int i=1;i<=n;i++)
        if(in[i]>1)
        {
            get_ans(i);
            break;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}