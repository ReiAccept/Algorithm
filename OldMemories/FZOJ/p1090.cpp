#include<cstdio>

int n,m,ac;

void dfs(int last,int l,int depth);

int main()
{
    int i;
    scanf("%d%d",&n,&m);
    dfs(n,1,1);
    printf("%d\n",ac);
    return 0;
}

void dfs(int last,int l,int depth)
{
    int i;
    if(depth==m)
    {
        ac++;
        return;
    }
    for(i=l; i<=(int)(last/2); i++)
        dfs(last-i,i,depth+1);
}
