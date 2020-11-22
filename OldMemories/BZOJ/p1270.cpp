#include<cstdio>
#include<algorithm>

using namespace std;

int n,h,delta,ans;
int grap[2003][2003],f1[2003],f2[2003];

int main()
{
	scanf("%d%d%d",&n,&h,&delta);
	for(int i=1;i<=n;i++)
	{
		int ni;
		scanf("%d",&ni);
		while(ni--)
		{
			int t;
			scanf("%d",&t);
			grap[i][t]++;
		}
	}
	for(int i=h;i>=1;i--)
	{
		int t=(i+delta<=h)?f1[i+delta]:0;
		for(int j=1;j<=n;j++)
		{
			f2[j]=max(f2[j],t)+grap[j][i];
			f1[i]=max(f1[i],f2[j]);
		}
	}
	printf("%d",f1[1]);
	return 0;
}
