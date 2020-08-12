#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,k;
int h[1003][1003];
bool flag;

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			const int a=h[i][j];
			if(a<=h[i+1][j] || a<=h[i-1][j] || a<=h[i][j-1] || a<=h[i][j+1])
				h[i][j]=0;
		}
}

void printx()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",h[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&h[i][j]);
	init();
	for(int i=1;i<=k;i++)
	{
		int x,y,dis=0x3f3f3f3f;
		flag=true;
		scanf("%d%d",&x,&y);
		for(int curx=x;curx>0;curx--)
		{
			int cen=x-curx+1;
			for(int cury=y;cury>0;cury--)
			{
				if(h[curx][cury])
				{
					dis=min(dis,max(x-curx,y-cury));
					flag=false;
				}
			}
		}
		if(flag)
			printf("Pool Babingbaboom!\n");
		else
			printf("%d\n",dis);
	}
	return 0;
}
