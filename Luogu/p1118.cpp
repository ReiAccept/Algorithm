#include<cstdio>
#include<iostream>

using namespace std;

const int PT[][13]= //杨辉三角
{
    {1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1},
    {1,6,15,20,15,6,1},{1,7,21,35,35,21,7,1},{1,8,28,56,70,56,28,8,1},
    {1,9,36,84,126,126,84,36,9,1},{1,10,45,120,210,252,210,120,45,10,1},
    {1,11,55,165,330,462,462,330,165,55,11,1}
};

int n,sum;
int a[20];
bool flag,used[20];

void dfs(int s,int p)
{
    if(p==n && s==sum)flag=true;
    if(p==n)return;
    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;
        used[i]=true;
        a[p]=i;
        if(s+PT[n-1][p]*a[p]<=sum)dfs(s+PT[n-1][p]*a[p],p+1);
        if(flag)return;
        used[i]=false;
    }
}

int main()
{
    scanf("%d%d",&n,&sum);
    dfs(0,0);
    if(flag)for(int i=0;i<n; i++)printf("%d ",a[i]);
    return 0;
}
