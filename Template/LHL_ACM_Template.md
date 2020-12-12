# 起手式

```cpp
#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
//#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar(x%10+'0');}

void work()
{
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
```

# 并查集DSU

```cpp
int fa[MAXN], rank[MAXN];

inline void INIT(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        rank[i]=1;
    }
}

int findx(int x)
{
    return x==fa[x]?x:(fa[x]=findx(fa[x]));
}

inline void mergexy(int i, int j)
{
    int x=find(i),y=find(j);//先找到两个根节点
    if (rank[x]<=rank[y]) fa[x]=y;
    else fa[y]=x;
    if (rank[x]==rank[y] && x!=y) rank[y]++;//如果深度相同且根节点不同,则新的根节点的深度+1
}
```

# qisprime

```cpp
bool isprime(int a)
{
    if(a==2||a==3)return true;
    if(a==1 || (a%6!=1&&a%6!=5))return false;
    for(int i=5; i<=(int)sqrt(a)+1; i+=6)if(a%i==0||a%(i+2)==0)return false;
    return true;
}
```

# 线段树

```cpp
int n, m, mod;
int a[MAXN];

struct Segment_Tree {
	ll sum, add, mul;
	int l, r;
}s[MAXN * 4];

void update(int pos) {
	s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % mod;
    return;
}

void pushdown(int pos) { //pushdown的维护
	s[pos << 1].sum = (s[pos << 1].sum * s[pos].mul + s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1)) % mod;
	s[pos << 1 | 1].sum = (s[pos << 1 | 1].sum * s[pos].mul + s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1)) % mod;
	
	s[pos << 1].mul = (s[pos << 1].mul * s[pos].mul) % mod;
	s[pos << 1 | 1].mul = (s[pos << 1 | 1].mul * s[pos].mul) % mod;
	
	s[pos << 1].add = (s[pos << 1].add * s[pos].mul + s[pos].add) % mod;
	s[pos << 1 | 1].add = (s[pos << 1 | 1].add * s[pos].mul + s[pos].add) % mod;
		
	s[pos].add = 0;
	s[pos].mul = 1;
	return; 
}

void build_tree(int pos, int l, int r) { //建树
	s[pos].l = l;
	s[pos].r = r;
	s[pos].mul = 1;
	
	if (l == r) {
		s[pos].sum = a[l] % mod;
		return;
	}
	int mid = (l + r) >> 1;
	build_tree(pos << 1, l, mid);
	build_tree(pos << 1 | 1, mid + 1, r);
	update(pos);
	return;
}

void ChangeMul(int pos, int x, int y, int k) { //区间乘法
	if (x <= s[pos].l && s[pos].r <= y) {
		s[pos].add = (s[pos].add * k) % mod;
		s[pos].mul = (s[pos].mul * k) % mod;
		s[pos].sum = (s[pos].sum * k) % mod;
		return;
	}
	pushdown(pos);
	int mid = (s[pos].l + s[pos].r) >> 1;
	if (x <= mid) ChangeMul(pos << 1, x, y, k);
	if (y > mid) ChangeMul(pos << 1 | 1, x, y, k);
	update(pos);
	return;
}

void ChangeAdd(int pos, int x, int y, int k) { //区间加法
	if (x <= s[pos].l && s[pos].r <= y) {
		s[pos].add = (s[pos].add + k) % mod;
		s[pos].sum = (s[pos].sum + k * (s[pos].r - s[pos].l + 1)) % mod;
		return;
	}
	pushdown(pos);
	int mid = (s[pos].l + s[pos].r) >> 1;
	if (x <= mid) ChangeAdd(pos << 1, x, y, k);
	if (y > mid) ChangeAdd(pos << 1 | 1, x, y, k);
	update(pos);
	return;
}

ll AskRange(int pos, int x, int y) { //区间询问
	if (x <= s[pos].l && s[pos].r <= y) {
		return s[pos].sum;
	}
	pushdown(pos);
	ll val = 0;
	int mid = (s[pos].l + s[pos].r) >> 1;
	if (x <= mid) val = (val + AskRange(pos << 1, x, y)) % mod;
	if (y > mid) val = (val + AskRange(pos << 1 | 1, x, y)) % mod;
	return val;
}

int main() {
	scanf("%d%d%d", &n, &m, &mod);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build_tree(1, 1, n);
	for (int i = 1; i <= m; i++){
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) {
			int k;
			scanf("%d", &k);
			ChangeMul(1, x, y, k);
		}
		if (opt == 2) {
			int k;
			scanf("%d", &k);
			ChangeAdd(1, x, y, k);
		}
		if (opt == 3) {
			printf("%lld\n", AskRange(1, x, y));
		}
	}
    
	return 0;
}
```

# Dij

```cpp
int n,m,s;//n-点数 m边数 s起点
bool vis[200003];
struct Edge{
    int to,dis,next;
}e[200003];
int head[200003],dis[200003],cnt;
void addedge(int u,int v,int d)//from u to v dis d(w);
{
    cnt++;
    e[cnt].dis=d;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

struct Node
{
    int dis,pos;
    bool operator < (const Node &x)const
    {
        return x.dis<dis;
    }
};
std::priority_queue<Node> q;//区别pbds的优先队列和std的优先队列 

void dij()
{
    dis[s]=0;
    q.push((Node){0,s});
    while(!q.empty())
    {
        Node t=q.top();
        q.pop();
        int x=t.pos,d=t.dis;
        if(vis[x])continue;
        vis[x]=true;
        for(int i=head[x];i;i=e[i].next)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].dis)
            {
                dis[y]=dis[x]+e[i].dis;
                if(!vis[y]) q.push((Node){dis[y],y});
            }
        }
    }
}

void work()
{
    n=read();m=read();s=read();
    for(int i=1;i<=n;i++) dis[i]=INF;
    for(int u,v,w,i=1;i<=m;i++)
    {
        u=read();v=read();w=read();
        addedge(u,v,w);
    }
    dij();
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return;
}
```

