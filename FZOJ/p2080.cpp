#include<cstdio>

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if(n<k || k>26 || (k<=1 && n>1))
	{
		printf("-1");
		return 0;
	}
	if(n==1 && k==1)
	{
		printf("a");
		return 0;
	}
	for(int i=1;i<=n-k+2;i++)
	{
		if(i%2) 
			printf("a");
		else 
			printf("b");
	}
	for(int i=1;i<=k-2;i++)
		printf("%c",i+98);
	return 0;
}
