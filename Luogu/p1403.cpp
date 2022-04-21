#include <cstdio>

int n,s;
int a[10000001];

int main()
{
	scanf ("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
			a[j]++;
		s+=a[i];
	}
	printf ("%d\n",s);
	return 0;
}
