#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+10;

int T,Case=1;
int n,m;

vector<int> grap[MAXN];

void work()
{
    for(int i=1;i<=n;i++) grap[i].clear();
    printf("Case #%d: \n",Case);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        for(int j=1;j<=num;j++)
        {
            int to; scanf("%d",&to);
            grap[i].push_back(to);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int cur,num; scanf("%d%d",&cur,&num);
        bool flag=true;
        for(int j=1;j<=num;j++)
        {
            int to; scanf("%d",&to);
            if(flag)
            {
                to--; //0 号边开始存
                if((int)grap[cur].size()>to) cur=grap[cur][to];
                else 
                {
                    flag=false;
                }
            }
        }
        if(!flag) printf("Packet Loss");
        else printf("%d",cur);
        if(i!=m)printf("\n");
    }
    if(Case!=T) printf("\n");
}

signed main()
{
    scanf("%d",&T);
    for(Case=1;Case<=T;Case++) work();
    return 0;
}
