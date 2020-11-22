//http://hzwer.com/1216.html看题解看的不明所以 
#include<cstdio>

using namespace std;

int n,b,point,ans;
int num[100001],sum[100001],l[200001],r[200001];

int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]>b)
			num[i]=1;
		else if(num[i]==b)
		{
			num[i]=1;
			point=i;
		}
		else 
			num[i]=-1;
	}
	l[n]=1;
	r[n]=1;
	for(int i=point-1;i>=1;i--)
	{
		sum[i]=sum[i+1]+num[i];
		l[sum[i]+n]++;
	}
	for(int i=point+1;i<=n;i++)
	{
		sum[i]=sum[i-1]+num[i];
		r[sum[i]+n]++;
	}
	for(int i=0;i<=2*n-1;i++)
		ans+=l[i]*r[2*n-i];//知其然不知其所以然的一段 
		printf("%d",ans);
	return 0;
}
