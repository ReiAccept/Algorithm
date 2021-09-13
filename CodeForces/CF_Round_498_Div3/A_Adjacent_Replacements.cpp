#include<cstdio>

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp%2==0)
			printf("%d ",tmp-1);
		else
			printf("%d ",tmp);
	}
	return 0;
}
