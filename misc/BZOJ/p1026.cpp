#include<cmath>
#include<cstdio>

using namespace std;

int f[1000][1000],fab[20];

void init()
{
	fab[1]=1;
	for(int i=2;i<=10;i++)
		fab[i]=fab[i-1]*10;
	for(int i=1;i<=9;i++)
		f[1][i]=1;
	for(i=2;i<=10;i++)
		for(j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				if(abs(j-k)>=2)
					f[i][j]+=f[i-1][k];

}

int work(int now)
{
	if(now==0)
		return 0;
	int n=10,ans=0;
	while(fab[n]>now)
		n--;
	for(int i=1;i<n;i++)
		for(int j=1;j<=9;j++)
			ans+=f[i][j];
	int cur=now/fab[n];
	for(int i=1;i<cur;i++)
		ans+=f[n][i];
	now%=fab[n];
	int pre=cur;
	for(int i=n-1;i;i--)
	{
		cur=now/fab[i];
		if(i!=1)
		{

		}
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	return 0;
}
