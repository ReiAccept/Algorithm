#include<cstdio>

using namespace std;

int n,m;
bool grap[10003];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		grap[x][y]=true;
	}
	return 0;
}
