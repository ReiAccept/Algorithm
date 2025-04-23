#include<cstdio>

int n,all;
int a[100];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=50)
			i--,n--;
		else
			all+=a[i];
	}
	return 0;
}
