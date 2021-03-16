#include<bits/stdc++.h>

using namespace std;

int n,l,sx,sy;
char g[103][103];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='S')sx=i,sy=j;
        }
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        char op;
        cin>>op;
        if(op=='W') if(sx!=1 && g[sx-1][sy]!='#')sx--;
        if(op=='S') if(sx!=n && g[sx+1][sy]!='#')sx++;
        if(op=='A') if(sy!=1 && g[sx][sy-1]!='#')sy--;
        if(op=='D') if(sy!=n && g[sx][sy+1]!='#')sy++;
        if(g[sx][sy]=='E')
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}