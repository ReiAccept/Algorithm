#include<cstdio>

using namespace std;

int n,pjs,ans;
int a[103];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pjs+=a[i];
	}
	pjs/=n;
	for(int i=1;i<=n;i++)
		a[i]-=pjs;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			a[i+1]+=a[i];
			ans++;
		}
	printf("%d\n",ans);
	return 0;
}
