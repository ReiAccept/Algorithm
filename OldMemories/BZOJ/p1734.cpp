#include<cstdio>
#include<algorithm>

using namespace std;

int n,c,l,r;
int a[100003];
long long tot,ans;

int main()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	r=a[n];
	while(l<r)
	{
		int mid=(l+r)/2;
		tot=ans=0;
		for(int i=2;i<=n;i++)
			if(tot+a[i]-a[i-1]<=mid)
				tot+=(a[i]-a[i-1]);
			else
			{
				tot=0;
				ans++;
			}
		if(ans<c-1)
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}

