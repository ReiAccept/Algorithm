/*
因为n=100000,m=300000，且图随机，那么每个点平均连了6条边，且两点间最短路一般不会超过8
对于每个询问S,T，若两个点不连通，那么显然无解，可以O(1)判断
考虑Meet in the middle：从S和T分别爆搜4步，那么除去最短路过来的那条边，平均还剩5条边
可以得到所有不超过8的答案，时间复杂度O(6*5^3)
若此时还得不到答案，那么答案超过8，是小概率事件，直接O(n+m)BFS整张图即可
*/
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int N=100010,M=600010,inf=~0U>>1;
int K=4,lim=10000;
int n,m,Q,i,g[N],v[M],nxt[M],ed;
int h,t,q[N],d[N];
int ans,POS,vis[N];

vector<int>e[N];

int p1,p2,v1[N],v2[N],d1[N],d2[N];

set<P>T;
int cnt=0,all;
int f[N];
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
int bfs(int S,int T){
    int i;
    for(i=1;i<=n;i++)d[i]=-1;
    d[q[h=t=1]=S]=0;
    while(d[T]<0){
        int x=q[h++];
        for(i=g[x];i;i=nxt[i])if(d[v[i]]<0)d[q[++t]=v[i]]=d[x]+1;
    }
    return d[T];
}
inline void bfs1(int S){
    int i;
    v1[S]=++p1;
    d1[q[h=t=1]=S]=0;
    while(h<=t){
        int x=q[h++];
        if(d1[x]==K)continue;
        for(i=g[x];i;i=nxt[i])if(v1[v[i]]<p1){
            d1[q[++t]=v[i]]=d1[x]+1;
            v1[v[i]]=p1;
        }
    }
    all+=t;
}
inline void bfs2(int S){
    int i;
    v2[S]=++p2;
    d2[q[h=t=1]=S]=0;
    while(h<=t){
        int x=q[h++];
        if(v1[x]==p1&&d1[x]+d2[x]<ans)ans=d1[x]+d2[x];
        if(d2[x]==K)continue;
        for(i=g[x];i;i=nxt[i])if(v2[v[i]]<p1){
            d2[q[++t]=v[i]]=d2[x]+1;
            v2[v[i]]=p1;
        }
    }
    all+=t;
}
int F(int x){return f[x]==x?x:f[x]=F(f[x]);}
void dfs1(int x,int y,int z){
    if(vis[x]<POS)vis[x]=POS,d[x]=y;else if(d[x]>y)d[x]=y;else return;
    if(y==K)return;
    y++;
    for(vector<int>::iterator i=e[x].begin();i!=e[x].end();i++)
    if(*i!=z)dfs1(*i,y,x);
}
void dfs2(int x,int y,int z){
    if(vis[x]==POS&&d[x]+y<ans)ans=d[x]+y;
    if(y==K||y>=ans)return;
    y++;
    for(vector<int>::iterator i=e[x].begin();i!=e[x].end();i++)
    if(*i!=z)dfs2(*i,y,x);
}
int main(){
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=n;i++)f[i]=i;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        /*while(1){
            x=rand()%n+1;
            y=rand()%n+1;
            if(x==y)continue;
            if(x>y)swap(x,y);
            if(T.find(P(x,y))==T.end()){
                T.insert(P(x,y));
                break;
            }
        }*/
        if(F(x)!=F(y))f[f[x]]=f[y];
        add(x,y),add(y,x);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    //puts("DONE");
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        //x=rand()%n+1,y=rand()%n+1;
        
        if(F(x)!=F(y)){puts("-1");continue;}
        
        POS++;
        cnt=0;
        //ans=~0U>>1;
        ans=inf;
        dfs1(x,0,0);
        dfs2(y,0,0);
        if(ans==inf)ans=bfs(x,y);
        all+=cnt;
        //printf("cnt=%d\n",cnt);
        printf("%d\n",ans);
    }
    //printf("all=%d\n",all);
}
/*
6 5
1 2
2 3
1 3
1 4
4 5
5
1 3
4 2
3 5
5 1
4 6
*/
