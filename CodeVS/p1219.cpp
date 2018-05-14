#include<cstdio>

using namespace std;

int n,m,x1,y1,x2,y2;

long long dfs[53][53];

long long dp(int x,int y)
{
	if(x>n || y>m || x>x2 || y<1)
		return 0;
	if(x==x2 && y==y2)
		return 1;
	if(!dfs[x][y])
		dfs[x][y]=dp(x+1,y+2)+dp(x+1,y-2)+dp(x+2,y+1)+dp(x+2,y-1);
	return dfs[x][y];
}

int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
	printf("%lld\n",dp(x1,y1));
	return 0;
}
