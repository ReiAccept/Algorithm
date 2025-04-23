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

void hebing(int x,int y)
{
	x=findx(x);
	y=findx(y);
	r[x]=y;
}

bool chaxun(int x,int y)
{
	if(findx(x)==findx(y))
		return true;
	else
		return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		r[i]=i;
	for(int i=1;i<=m;i++)
	{
		int z,x,y;
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)
			hebing(x,y);
		else if(chaxun(x,y))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
