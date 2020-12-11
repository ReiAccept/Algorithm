class DSU
{
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
