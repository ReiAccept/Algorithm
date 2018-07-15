#include<cstdio>

using namespace std;

int n,m;
int c[1003],a[1003];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=a[cur])
		{
			cur++;
		}
	}
	printf("%d",cur-1);
	return 0;
}
