#include<cstdio>
#include<algorithm>

using namespace std;

struct Node
{
	int yw,sx,yy,xh,ans;
}a[303];

int n;

bool cmp(Node a,Node b)
{
	if(a.ans!=b.ans)
		return a.ans>b.ans;
	if(a.yw!=b.yw)
		return a.yw>b.yw;
	return a.xh<b.xh;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].yw,&a[i].sx,&a[i].yy);
		a[i].xh=i;
		a[i].ans=a[i].yw+a[i].sx+a[i].yy;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=5;i++)
		printf("%d %d\n",a[i].xh,a[i].ans);
	return 0;
}
