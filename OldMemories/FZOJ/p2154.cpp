#include<cstdio>

using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i;j<=n-i;j++)
		{
			int k=n-i-j;
			if(k<j)
				break;
			if((i+j>k) && (i+k>j) && (j+k>i))
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
