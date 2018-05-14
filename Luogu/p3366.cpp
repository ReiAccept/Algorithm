#include<cstdio>
#include<algorithm>

using namespace std;

struct grap
{
	int x,y,z;
}G[200003];

int n,m,flag,sum;
int r[5003];

int findx(int x)
{
	if(r[x]!=x)
		r[x]=findx(r[x]);
	return r[x];
}

bool chaxun(int x,int y)
{
	return findx(x)==findx(y);
}

void hebing(int x,int y)
{
	x=findx(x);
	y=findx(y);
	r[x]=y;
}

bool cmp(grap a,grap b)
{
	return a.z<b.z;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		r[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&G[i].x,&G[i].y,&G[i].z);
	sort(G+1,G+m+1,cmp);
	int i=1;
	while(i<=m && flag<=n-1)
	{
		if(!chaxun(G[i].x,G[i].y))
		{
			hebing(G[i].x,G[i].y);
			flag++;
			sum+=G[i].z;
		}
		i++;
	}
	printf("%d\n",sum);
	return 0;
}
