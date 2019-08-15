#include<queue>
#include<iostream>

using namespace std;

int n,p;
int a[103],u[103];
int grap[103][103];

queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>u[i];
    for(int i=1;i<=p;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>grap[x][y];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i])
            q.push(i);
    }
    while(!q.empty())
    {

    }
    return 0;
}
