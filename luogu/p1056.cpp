#include<cstdio>
#include<algorithm>

using namespace std;

int m,n,k,l,d;

struct Node{//n存可以隔开的人数,p存隔开的道路
	int n,p;
}ki[1003],li[1005];

bool cmpn(Node a,Node b)
{
	return a.n>b.n;
}

bool cmpp(Node a,Node b)
{
	return a.p<b.p;
}

int main()
{
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=1;i<=d;i++)
	{
		int xi,yi,pi,qi;//也是蛋疼,题面搞个x1y1,x2y2不好吗
		scanf("%d%d%d%d",&xi,&yi,&pi,&qi);
		if(xi==pi)//输入数据保证的相邻,不会斜着,意思就是xi==pi 或者 yi==qi
		{
			li[min(yi,qi)].p=min(yi,qi);//两个人竖向相等用行隔开,横向相等用列隔开
			li[min(yi,qi)].n++;//其实p里面存的是隔开这两人所需的,n是存多少个
		}
		else
		{
			ki[min(xi,pi)].p=min(xi,pi);
			ki[min(xi,pi)].n++;
		}
	}
	sort(li+1,li+n+1,cmpn);
	sort(ki+1,ki+m+1,cmpn);
	sort(li+1,li+1+l,cmpp);
	sort(ki+1,ki+1+k,cmpp);
	for(int i=1;i<=k;i++)
		printf("%d ",ki[i].p);
	printf("\n");
	for(int i=1;i<=l;i++)
		printf("%d ",li[i].p);
	return 0;
}
