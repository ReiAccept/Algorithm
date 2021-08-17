#include<cstdio>
#include<algorithm>

int n,ans;
int a[5003],dui[5003];

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(!ans)//拿来建立第一堆 
			dui[++ans]=1;
		else
		{
			int num=0,Max=0;
			for(int j=1;j<=ans;j++)//在当前已经建立的堆中遍历
				if(a[i]>=dui[j] && dui[j]>Max) 
				{
					Max=dui[j];
					num=j;
				}
			if(!num)//找不到,建堆
				dui[++ans]=1;
			else//找得到,堆上加一
				dui[num]++;
		}
	printf("%d",ans);
	return 0;
}
