#include<iostream>

using namespace std;

const int MAXN=1000;
int tot;
int ver[MAXN],next[MAXN],head[MAXN],edge[MAXN];
//ver顶点 edge 边权 next 下一个 head 头
//head和next数组里保存到是ver数组的下标

void add(int x,int y,int z)//x->y且值为z的边
{
    ver[++tot]=y,edge[tot]=z;
    next[tot]=head[x],head[x]=tot;
}

int main()
{
    int x=0;
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i],z=edge[i];//找到一条x->y的有向边,权值为z
    }
    return 0;
}
