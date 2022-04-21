#include <cstdio>

using namespace std;

int vis[10];

int judge(int a,int b)
{
	if (b>98765)
		return 0;
	for(int i=0;i<10;i++)
		vis[i]=0;
	if (a<10000) 
		vis[0]=1;
	while(a)
	{
		vis[a%10]=1;
		a/=10;
	}
	while(b)
	{
		vis[b%10]=1;
		b/=10;
	}
	int sum=0;
	for(int i=0;i<10;i++)
		sum+=vis[i];
	return (sum==10);
}

int main()
{
	int n,T=0;
	while(~scanf("%d",&n) && n)
	{
		if(T++)
			printf("\n");
		int count = 0;
		for(int i=1234;i<100000;++i)
		{
			if (judge(i,i*n))
			{ 
				printf("%05d / %05d = %d\n",i*n,i,n);
				count++;
			}
		}
		if (!count) 
			printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
