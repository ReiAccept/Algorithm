#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,x,y,tot;
int h[100005],siz[100005],f[100005];

struct Edge{
    int x,next;
} e[200005];

inline void add_edge(int x,int y)
{
    e[++tot].x=y;
    e[tot].next=h[x],h[x]=tot;
}

bool dfs(int x,int fa)
{
    siz[x]=1;
    int cnt=0;
    for(int i=h[x];i;i=e[i].next)
    {
        if(e[i].x==fa)continue;
        if(dfs(e[i].x,x))return true;
        if(siz[e[i].x])
        {
            cnt++,siz[x]=0;
            if(cnt==2)return true;
        }
    }
    return false;
}

void Solve()
{
    n=qrd();
    for(int i=1;i<n;i++)
    {
        x=qrd();y=qrd();
        add_edge(x,y);
        add_edge(y,x);
    }
    printf(dfs(1,0)||siz[1]?"First\n":"Second\n");
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
/*
贪心即可。考虑当前树上的叶子节点，若先手将其父亲节点染为白色，则后手定会将其儿子节点染为黑色，否则该儿子节点满足条件，先手胜利。若该父亲节点有两个或以上儿子节点，先手必胜。
每一轮涂色后，该两点对胜负无影响，直接从树上删去，继续贪心。最后判断根节点是否满足条件即可。
*/
