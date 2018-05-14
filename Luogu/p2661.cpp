#include<cstdio>
#include<climits>
#include<iostream>
#include<algorithm>

int n,t,ans=INT_MAX;
int g[200009],d[200009];
bool flag,f[200009];

int dfs(int k)//寻找最小环的函数,tmp其实就算环的长度,当!f[k]并没有被访问的时候,就一直找下去(其实觉得这个函数不像是DFS,像并查集里的find函数,要我写的话会改成递归)
{
    int tmp=0;
    while(!f[k])
    {
        f[k]=true;
        k=g[k];
        tmp++;
    }
    return tmp;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&t);
        g[i]=t;
        d[t]++;//使路径的长度为1,也就是初始环1
    }
    for(int i=1; i<=n; i++)
    {
        flag=false;
        for(int j=1; j<=n; j++)
        {
            if(f[j])
                continue;
            if(!d[j])
            {
                f[j]=true;
                d[g[j]]--;
                flag=true;
            }
        }
        if(!flag)
            break;
    }
    for(int i=1; i<=n; i++)
    {
        if(f[i])
            continue;
        ans=std::min(ans,dfs(i));//这个dfs函数是拿来求环的长度的,如果之前已经打过标记,就不求了
    }
    printf("%d",ans);
    return 0;
}
/*
#include<cstdio>
#include<iostream>
using namespace std;
int f[200002],d[200002],n,minn,last;   //f保存祖先节点，d保存到其祖先节点的路径长。 
int fa(int x)
{
    if (f[x]!=x)                       //查找时沿途更新祖先节点和路径长。 
    {
        int last=f[x];                 //记录父节点（会在递归中被更新）。 
        f[x]=fa(f[x]);                 //更新祖先节点。 
        d[x]+=d[last];                 //更新路径长（原来连在父节点上）。 
    }
    return f[x];
}
void check(int a,int b)
{
    int x=fa(a),y=fa(b);               //查找祖先节点。 
    if (x!=y) {f[x]=y; d[a]=d[b]+1;}   //若不相连，则连接两点，更新父节点和路径长。 
    else minn=min(minn,d[a]+d[b]+1);   //若已连接，则更新最小环长度。 
    return;
}
int main()
{
    int i,t;
    scanf("%d",&n);
    for (i=1;i<=n;i++) f[i]=i;         //祖先节点初始化为自己，路径长为0。 
    minn=0x7777777;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&t);
        check(i,t);                    //检查当前两点是否已有边相连接。 
    }
    printf("%d",minn);
    return 0;
}
*/
