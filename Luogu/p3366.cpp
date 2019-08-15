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
		if(!chaxun(G[i].x,G[i].y))//非同祖宗
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
//给自己的回顾:并查集的路径压缩是可以的，路径压缩之后只是两个点的父亲被直接找到了,合并时候的sum+=G[i].z是把他们连接在一起,不会受影响的，然后由于最小生成树,在i==m或者flag=n的时候就会结束建树。    ——NOIP2018初赛前回顾
