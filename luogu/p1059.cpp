#include<cstdio>

using namespace std;

int n,tmp,ans;
int a[1003];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		a[tmp]++;
	}
	for(int i=1;i<=1000;i++)
		if(a[i])
			ans++;
	printf("%d\n",ans);
	for(int i=1;i<=1000;i++)
		if(a[i])
			printf("%d ",i);
	return 0;
}
