#include<bits/stdc++.h>

using namespace std;

int flag;
int arr[8][8],vis[8][8];

bool check()
{
    for(int i=1; i<5; i++)for(int j=1; j<7; j++)vis[i+1][j]=(arr[i][j]+vis[i][j-1]+vis[i][j]+vis[i][j+1]+vis[i-1][j])%2;
    for(int i=1; i<7; i++)if((vis[5][i-1]+vis[5][i]+vis[5][i+1]+vis[4][i])%2!=arr[5][i]) return false;
    return true;
}

int main()
{
    for(int i=0; i<6; i++) vis[i][0]=vis[i][7]=0;
    for(int i=1; i<7; i++) vis[0][i]=0;
    for(int i=1; i<6; i++)for(int j=1; j<7; j++)scanf("%d",&arr[i][j]);
    for(int i=1; i<7; i++) vis[1][i]=0;
    while(!check())
    {
        vis[1][1]++;
        flag=1;
        while(vis[1][flag]>1) vis[1][flag]=0,vis[1][++flag]++;
    }
    for(int i=1; i<6; i++)
    {
        for(int j=1; j<7; j++) printf("%d ",vis[i][j]);
        printf("\n");
    }
    return 0;
}
