#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

class DSU
{
    protected:
    vector<int> fa,rank;
    public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++) 
        {
            fa.push_back(i);
            rank.push_back(1);
        }
    }
    int findx(int x)
    {
        return x==fa[x]?x:(fa[x]=findx(fa[x]));
    }
    inline void merge(int i, int j)
    {
        int x=findx(i),y=findx(j);//先找到两个根节点
        if (rank[x]<=rank[y]) fa[x]=y;
        else fa[y]=x;
        if (rank[x]==rank[y] && x!=y) rank[y]++;//如果深度相同且根节点不同,则新的根节点的深度+1
    }
};

class Solve : DSU
{
    public:
    Solve()
    {

    }
    ~Solve()
    {
        for(int x,y,i=1;i<=p;i++)
        {
            x=read();y=read();
            if(a.findx(x)==a.findx(y))printf("Yes\n");
            else printf("No\n");
        }
    }
};

void work()
{
    int n=read(),m=read(),p=read();
    DSU a(n);
    for(int x,y,i=1;i<=m;i++)
    {
        x=read();y=read();
        a.merge(x,y);
    }
    
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
