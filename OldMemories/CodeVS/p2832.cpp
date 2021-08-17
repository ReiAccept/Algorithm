#include<cstdio>

using namespace std;

int n,m;
int r[10003];

int findx(int x)
{
	if(r[x]!=x)
		r[x]=findx(r[x]);
	return r[x];
}

inline void hebing(int x,int y)
{
	x=findx(x);
	y=findx(y);
	if(x!=y)
		r[x]=y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		r[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		hebing(a,b);
	}
	return 0;
}
