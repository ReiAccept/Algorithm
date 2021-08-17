#include<iostream>

using namespace std;

int n,k,s,g;
int city[103][103];

const int INF=0x3f3f3f3f;

int main()
{
    cin>>n>>k>>s>>g;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                city[i][j]=0;
            else
                city[i][j]=INF;
    for(int i=1;i<=k;i++)
	{
		int x,y;
        cin>>x>>y;
        city[x][y]=1;
        city[y][x]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(city[i][j]>city[i][k]+city[k][j])
                    city[i][j]=city[i][k]+city[k][j];
    if(city[s][g]==INF)
        cout<<"-1"<<endl;
    else if(city[s][g]==0)
        cout<<"0"<<endl;
    else
        cout<<city[s][g]-1<<endl;
    return 0;
} 
