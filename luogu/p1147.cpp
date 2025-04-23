#include<cstdio>

using namespace std;

int m,sum;

int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		sum=0;
		for(int j=i;j<m;j++)
		{
			sum+=j;
			if(sum>m)
				break;
			if(sum==m)
			{
				printf("%d %d\n",i,j);
				break;
			}
		}
	}
	return 0;
}
