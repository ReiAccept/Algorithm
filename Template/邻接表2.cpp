const int N=10;

struct Edge
{
    int to,next;
}edge[N];

int cnt=1;
int head[N];

void add(int u,int v)//加入u->v的边
{
    edge[cnt].to=v;//
    edge[cnt].next=head[u];
    head[u]=cnt++;//head[u]->cnt
}

//遍历方式
for(int i = head[u]; i; i = edge[i].next)
    int v=edge[i].to;
