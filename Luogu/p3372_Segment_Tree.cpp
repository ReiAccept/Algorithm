#include<cstdio>
#include<iostream>

using namespace std;

struct tree
{
	int l,r;
	long long sum;
	int add;
}tr[400005];

int n,m;
int a[100003];

//隔一段时间写代码,数据名称都记不起来了,Fuck
//l-->left;r-->right;p-->place(表示当前位置);
void build_tree(int l,int r,int p)
{
	tr[p].l=l;
	tr[p].r=r;
	if(l==r)
		tr[p].sum=a[l];
	else
	{
		int mid=(l+r)/2;
		build_tree(l,mid,p*2);
		build_tree(mid+1,r,p*2+1);
		tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;
	}
}

void push_down(int x,int m)
{
	if(tr[x].add)
	{
		tr[x*2].add=tr[x].add;
		tr[x*2+1].add=tr[x].add;
		tr[x*2].sum+=tr[x].add*(m-m/2);
		tr[x*2+1].sum+=tr[x].add*(m/2);
		tr[x].add=0;
	}
}

void update_tree(int l,int r,int k,int p)
{
	if(l<=tr[p].l && r>=tr[p].r)
	{
		tr[p].add+=k;
		tr[p].sum+=k*(tr[p].r-tr[p].l+1);
	}
	else
	{
		push_down(p,tr[p].r-tr[p].l+1);
		int mid=(tr[p].l+tr[p].r)/2;
		if(r<=mid)
			update_tree(l,r,k,p*2);
		else if(l>=mid)
			update_tree(l,r,k,p*2+1);
		else
		{
			update_tree(l,r,k,p*2);
			update_tree(l,r,k,p*2+1);
		}
		tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;
	}
}

long long chaxun_tree(int l,int r,int p)
{
	if(l<=tr[p].l && r>=tr[p].r)
		return tr[p].sum;
	else
	{
		push_down(p,tr[p].r-tr[p].l+1); 
		int mid=(tr[p].l+tr[p].r)/2;
		if(l>mid)
			return chaxun_tree(l,r,p*2+1);
		else if(r<=mid)
			return chaxun_tree(l,r,p*2);
		else
			return chaxun_tree(l,r,p*2+1)+chaxun_tree(l,r,p*2);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build_tree(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int cz;
		scanf("%d",&cz);
		if(cz==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			update_tree(x,y,k,1);
		}
		else if(cz==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			cout<<chaxun_tree(x,y,1)<<endl;
		}
	}
	return 0;
}
