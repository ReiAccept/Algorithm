#include<cstdio>
#include<iostream>
using namespace std;
int n,m,cnt;
bool b[101][101];
struct que
{
    int x,y;
} q[10001];
const int dx[]= {+1,-1,0,0};
const int dy[]= {0,0,-1,+1};
void bfs(int x,int y)
{
    int head=0,tail=1;
    b[x][y]=1;
    q[0].x=x;
    q[0].y=y;
    while(head!=tail)
    {
        que now=q[head++];
        if(head==10000)head=0;
        for(int i=0; i<4; i++)
        {
            int cx=now.x+dx[i];
            int cy=now.y+dy[i];
            if(1<=cx&&cx<=n&&1<=cy&&cy<=m&&(!b[cx][cy]))
            {
                b[cx][cy]=1;
                q[tail].x=cx;
                q[tail].y=cy;
                tail++;
                if(tail==10000)tail=0;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char ch;
            cin>>ch;
            if(ch=='0')
                b[i][j]=1;
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(!b[i][j])
            {
                cnt++;
                bfs(i,j);
            }
    printf("%d\n",cnt);
    return 0;
}
