#include<iostream>

using namespace std;

int n,m;
char g[103][103];
int h[103][103];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='*')
            {
                h[i-1][j-1]++;
                h[i-1][j]++;
                h[i-1][j+1]++;
                h[i][j-1]++;
                h[i][j+1]++;
                h[i+1][j-1]++;
                h[i+1][j]++;
                h[i+1][j+1]++;
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]=='*')cout<<"*";
            else cout<<h[i][j];
        }
        cout<<endl;
    }
    return 0;
}
