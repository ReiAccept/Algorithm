#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,tot,cur;

struct node
{
	int x,y;
}e[200003];

bool cmp(const node&s1,const node&s2)
{
	return s1.y<s2.y;
}

int main()
{
	scanf("%d%d",&n,&m);
	int t=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y)
			swap(x,y);
		if(x+1!=y)
		{
			e[++t].x=x;
			e[t].y=y;
		}
	}
	sort(e+1,e+t+1,cmp);
	for(int i=1;i<=t;i++)
		if(e[i].x>=cur)
		{
			cur=e[i].y;
			tot++;
		}
	printf("%d\n",tot+n-1);
	return 0;
}
