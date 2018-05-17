#include<cstdio>
#include<algorithm>

using namespace std;

struct person
{
	int k,s;
}a[5003];

int n,m,fsx,rs;

bool cmp(person a,person b)
{
	if(a.s==b.s)
		return a.k<b.k;
	return a.s>b.s;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].k,&a[i].s);
	sort(a+1,a+n+1,cmp);
	fsx=a[(int)(m*1.5)].s;
	for(int i=1;i<=n;i++)
		if(a[i].s>=fsx)
			rs++;
	printf("%d %d\n",fsx,rs);
	for(int i=1;i<=rs;i++)
		printf("%d %d\n",a[i].k,a[i].s);
	return 0;
}
