#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[1003],f[1003];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=2*i;j<=n;j+=i)
			a[j]+=i;
	for(int i=1;i<=n;i++)
		for(int j=n;j>=i;j--)
			f[j]=max(f[j],f[j-i]+a[i]);
	printf("%d",f[n]);
	return 0;
}
