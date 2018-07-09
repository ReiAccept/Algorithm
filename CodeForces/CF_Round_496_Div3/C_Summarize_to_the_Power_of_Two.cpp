//¾øÁË,T3»¹ÄÜWA 
#include<cstdio>

using namespace std;

int n,ans;
int a[120003];
bool vis[120003];


inline bool chk(int num)
{
	if(num&(num-1))
		return false;
	else
		return true;
}

int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(!vis[i])
		{
			bool flag=true;
			int j;
			for(j=i+1;flag && j<=n;j++)
			{
				if(chk(a[i]+a[j]))
				{
					flag=false;
					vis[i]=vis[j]=1;
				}
			}
			if(flag)
			{
				//printf("%d %d\n",a[i],a[j-1]);
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
