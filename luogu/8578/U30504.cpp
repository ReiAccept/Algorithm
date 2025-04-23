#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int xA,yA;
int r,c,n,ans=500*500+5;
char grap[503][503];
char road[17];
char roadtrue[17];
bool visx[17];

void dfs(int x,int y,int deep,int num)
{
	if(grap[x][y]=='*' || x>r || x<=0 || y>c || y<=0)
		return;
	if(grap[x][y]!='.' && grap[x][y]!='*')
	{
		if(visx[grap[x][y]-'A'])
			return;
		road[num]=grap[x][y];
		num++;
		visx[grap[x][y]-'A']=true;
	}
	if(num>=n)
	{
		if(deep<ans)
		{
			ans=deep;
			memcpy(roadtrue,road,strlen(road));
		}
		return;
	}
	dfs(x+1,y,deep+1,num);
	dfs(x-1,y,deep+1,num);
	dfs(x,y+1,deep+1,num);
	dfs(x,y-1,deep+1,num);
	visx[grap[x][y]-'A']=false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>r>>c>>n;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>grap[i][j];
			if(grap[i][j]=='A')
				xA=i,yA=j;
		}
	}
	dfs(xA,yA,0,0);
	cout<<ans<<endl;
	cout<<roadtrue<<endl;
	return 0;
}
