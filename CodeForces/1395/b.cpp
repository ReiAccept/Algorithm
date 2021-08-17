#include<iostream>

using namespace std;

int n,m,x,y;
bool vis[103][103];

inline void out(int x,int y)
{
    cout<<x<<" "<<y<<endl;
}

int main()
{
    cin>>n>>m>>x>>y;
    vis[x][y]=vis[1][y]=vis[1][1]=true;
    out(x,y);
    out(1,y);
    out(1,1);
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                if(!vis[i][j])
                {
                    vis[i][j]=true;
                    out(i,j);
                }
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                if(!vis[i][j])
                {
                    vis[i][j]=true;
                    out(i,j);
                }
            }
        }
    }
    return 0;
}
