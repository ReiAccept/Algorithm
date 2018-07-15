#include<cmath>
#include<cstdio>
#include<algorithm>

using namespace std;

int a,b,ans=999999;
bool SF[10003];
bool road[10003];

void init_SF()
{
	for(int i=2;i<=9999;i++)
		for(int j=2;i*j<=9999;j++)
			SF[i*j]=true;
}

void dfs(int x,int y,int deep)
{
	if(x==y)
	{
		ans=min(deep,ans);
		return;
	}
	if(deep>=6)
		return;
	for(int i=0;i<4;i++)
	{
		int q=1;
		int qwq=i;
		while(qwq--)
			q*=10;
		for(int j=1;j<10;j++)
		{
			int numx=((x/q)%10)*q;
			int numex=x-numx+j*q;
			//printf("%d ",numx);
			if(numex!=x && !SF[numex] && !road[numex])
			{
				road[numex]=true;
				dfs(numex,y,deep+1);
				road[numex]=false;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	//if(a>b)
		//swap(a,b);
	init_SF();
	dfs(a,b,0);
	dfs(b,a,0);
	if(ans==999999)
		printf("Impossible");
	else
		printf("%d",ans);
	return 0;
}
