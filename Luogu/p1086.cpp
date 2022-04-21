#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,Time,map[21][21],ans = 0;

void dfs(int nowtime,int x,int y)
{
    int Maxx,Maxy,Max = -99999;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if (map[i][j] > Max)
            {
                Max = map[i][j];
                Maxx = i;
                Maxy = j;
            }
    if (!y) 
        y = Maxy;
    if (nowtime < abs(x-Maxx)+abs(y-Maxy)+Maxx+1 || !map[Maxx][Maxy])
        return;
    else {
        ans += map[Maxx][Maxy];
        map[Maxx][Maxy] = 0;
        dfs(nowtime-abs(x-Maxx)-abs(y-Maxy)-1,Maxx,Maxy);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&Time);//尴尬,这里nm反了
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&map[i][j]);
    dfs(Time,0,0);
    printf("%d\n",ans);
    return 0;
}
