//喵喵喵，不能AC的代码
#include<cstdio>
#include<iostream>

using namespace std;

struct tree
{
	int l,r;
	long long sum;
}tr[400003];

int n,m,a[100003];

void Build_tree(int x,int y,int i)
{
	tr[i].l=x;
	tr[i].r=y;
	if(x==y)
		tr[i].sum=a[x];
	else
	{
		int mid=(x+y)/2;
		Build_tree(1,mid,i*2);
		Build_tree(mid,n,i*2+1);
		tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
	}
}

void Update_tree(int x,int a,int i)
{
	if(tr[i].l==x && tr[i].r==x)
		tr[i].sum+=a;
	else
	{
		int mid=(tr[i].l+tr[i].r)/2;
		if(x<=mid)
			Update_tree(x,a,i*2);
		else
			Update_tree(x,a,i*2+1);
		tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
	}
}

long long Query_tree(int a,int b,int i)
{
	if(a<=tr[i].l && b>=tr[i].r)
		return tr[i].sum;
	else
	{
		int mid=(tr[i].l+tr[i].r)/2;
		if(a>mid)
			return Query_tree(a,b,i*2+1);
		else if(b<=mid)
			return Query_tree(a,b,i*2);
		else
			return Query_tree(a,b,i*2)+Query_tree(a,b,i*2+1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	Build_tree(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,a;
			scanf("%d%d",&x,&a);
			Update_tree(x,a,1);
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			cout<<Query_tree(a,b,1)<<endl;
		}
	}
	return 0;
}
