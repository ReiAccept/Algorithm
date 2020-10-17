#include <cstring>
#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;

int T,n,m;
int map[53][53];
bool vis[53];

int main()
{
    scanf("%d%d",&n,&m);//n件展览品,有m条路径
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) map[i][j]=0;
            else map[i][j]=inf;
    for(int x,y,v,i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&v);//起始展品x终点展品y距离v
        map[x][y]=v;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(map[i][j]>map[i][k]+map[k][j] )
                    map[i][j]=map[i][k]+map[k][j];
    //map[x][y]即展览盘x到y的最短路径
    scanf("%d",&T);//T组游客请求
    while(T--)
    {
        for(int i=1;i<=50;i++) vis[i]=false;
        printf("请输入你要去的展览品位置,以0为结束");
        int x=0,sum=0;
        while(cin>>x && x)
        {
            if(x<=1 && x>=50)
            {
                printf("没有这个展品,请重新输入\n");
                continue;
            }
            else if(vis[x])
            {
                printf("已经选择了这个展品，请重新输入\n");
                continue;
            }
            else if(!vis[x])
            {
                vis[x]=true;
                printf("成功选择,请继续,输入0结束");
                sum++;
            }
        }
        while(sum>1)
        {
            int i;while(!vis[i])i++;
            if(vis[i])i//i 出发展览品
            {
                int minn=inf,minx=0;//minn当前最短距离minx当前的目标展览品
                for(int j=1;j<=n;j++)
                {
                    if(i!=j && vis[j] && map[i][j]<minn)
                    {
                        minn=map[i][j],minx=j;
                    }
                }
                printf("从%d到%d的路径长为%d",i,minx,minn);
                vis[i]=false;
                sum--;
                i=minx;
            }
        }
        printf("游览路径规划结束\n");
    }
    return 0;
}
