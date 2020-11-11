#include<cstdio>

using namespace std;

int n,tmp2;
int res[1003],ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp==1)
		{
			ans++;
			res[ans-1]=tmp2;
			tmp2=1;
		}
		else
			tmp2++;
	}
	res[ans]=tmp2;
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",res[i]);
	}
	return 0;
}
