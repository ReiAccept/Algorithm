#include<cstdio>

using namespace std;

int n,ans;
bool SF[1005003];

int main()
{
	SF[1]=true;
	for(int i=2;i<=1005000;i++)
		for(int j=2;i*j<=1005000;j++)
			SF[i*j]=true;
	scanf("%d",&n);
	if(!SF[n])
	{
		printf("0");
		return 0;
	}
	int cur=n;
	while(cur--)
	{
		if(!SF[cur])
			break;
	}
	ans+=(n-cur);
	cur=n;
	while(cur++)
	{
		if(!SF[cur])
			break;
	}
	ans+=(cur-n);
	printf("%d",ans);
	return 0;
}
