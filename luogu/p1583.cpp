#include<cstdio>
#include<algorithm>

using namespace std;

struct Node
{
	int num,w;
}a[20003];

int n,k;
int e[11];

bool cmp(Node a,Node b)
{
	if(a.w==b.w)
		return a.num<b.num;
	return a.w>b.w;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++)
		scanf("%d",&e[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].w);
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		a[i].w+=e[((i-1)%10)+1];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",a[i].num);
	return 0;
}
