#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int l,w;
    bool operator < (const Node &b)
    {
        if(l==b.l) return w>b.w;
        return l>b.l;
    }
}a[5003];

int n,ans;
bool vis[5003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].w;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            int w_now=a[i].w;//注意这里不要标记vis[i]，因为一旦标记，无法对木棍进行计数
            for(int j=i+1;j<=n;j++)
                if(!vis[j] && a[j].w<=w_now)
                {
                    vis[j]=true;
                    w_now=a[j].w;
                }
        }
    for(int i=1;i<=n;i++)if(!vis[i])ans++;//为什么这里ans不要初始化为1,是因为靠未访问过的数量来记录时间
    cout<<ans<<endl;
    return 0;
}
