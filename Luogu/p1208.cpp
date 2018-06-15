#include<cstdio>
#include<algorithm>

using namespace std;

struct Node
{
	int p,a;
}a[2000003];

int n,m,ans;

bool cmp(Node a,Node b)
{
	return a.p<b.p;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i].p,&a[i].a);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(n<=0)
			break;
		if(n>=a[i].a)
			ans+=(a[i].a*a[i].p);
		else
			ans+=(a[i].p*n);
		n-=a[i].a;
	}
	printf("%d\n",ans);
	return 0;
}
