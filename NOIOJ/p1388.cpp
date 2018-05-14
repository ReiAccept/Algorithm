#include<iostream>

using namespace std;

struct zb
{
    int x,y;
}q[10003];

char t;
int n,m,ans,head,tail;
bool s[103][103];

void bfs(int y,int x);
{
    ans++;
    head=0,tail=1;
    while(head!=tail)
    {

    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>t;
            if(t=='W')
                s[i][j]=true;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j])
                bfs(i,j);
}

// http://noi.openjudge.cn/ch0205/1388/
