#include<cstdio>
#include<algorithm>

using namespace std;

int n,m;
int num[10003];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=m;i++)
		next_permutation(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	return 0;
}
