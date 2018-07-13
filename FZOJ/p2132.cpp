#include<cstdio>
#include<algorithm>

using namespace std;

struct hd
{
	int start,end;
}a[1003];

int n,ans=1;

bool cmp(hd a,hd b)
{
	return a.end<b.end;
}

int main()
{
	scanf("%d",&n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].start,&a[i].end);
	sort(a+1,a+1+n,cmp);
	int tmp=a[1].end;
	for(int i=2;i<=n;i++)
	{
		if(tmp<=a[i].start)//我觉得这里很烦人,题面明明是[Si,Fi]实际上数据是[si,fi)
		{
			tmp=a[i].end;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
