#include<cstdio>

using namespace std;

int n,m,res,flag;
bool a[100000005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&flag);
		a[flag]=true;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&flag);
		if(a[flag])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
