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
